
#include <SD.h>
#include <SPI.h>

#include "sd_pic.h"
#include "lcd_4inch.h"

BMP_INFO bmp_info;
File bmp_file;
//
char file_name[4][20] = {"birds.bmp","cat.bmp","fish.bmp","rabbit.bmp"};

// These read data from the SD card file and convert them to big endian
// (the data is stored in little endian format!)
static uint16_t Read16(File f)
{
  uint16_t result;
  ((uint8_t *)&result)[0] = f.read(); // LSB
  ((uint8_t *)&result)[1] = f.read(); // MSB
  return result;

}

// LITTLE ENDIAN!
static uint32_t Read32(File f)
{
  uint32_t result;
  ((uint8_t *)&result)[0] = f.read(); // LSB
  ((uint8_t *)&result)[1] = f.read();
  ((uint8_t *)&result)[2] = f.read();
  ((uint8_t *)&result)[3] = f.read(); // MSB
  return result;
}

static boolean Read_bmp_header(File f)
{
  uint16_t res;
  
  if ( Read16(f) != 0x4D42) //BMP signature
  {
     Serial.print("File is not BMP signature\r\n"); 
     return false;
  }

  // read file size
  bmp_info.Size = Read32(f);//file size
  // read and ignore creator bytes
  (void)Read32(f);//0006h 4byte:

  bmp_info.offset = Read32(f);// Start of image data

  // read DIB header
  bmp_info.header_size = Read32(f);//Bitmap header = 40

  bmp_info.width = Read32(f);//BMP Image wide
  bmp_info.height = Read32(f);//BMP Image high

  if (bmp_info.width != lcddev.width || bmp_info.height != lcddev.height)  // if image is not 480*320, return false
  {   
     Serial.print("BMP file size should be 480*320\r\n");
     return false;
  }

  if (Read16(f) != 1) // # planes -- must be '1'
    return false;

  bmp_info.bit_depth = Read16(f);
  
  if (Read32(f) == 0 && bmp_info.bit_depth != 24) //0 = uncompressed and the pixel format is RGB888
  {
     Serial.print("pixel format is support\r\n");
     return false;
  }
  return true;
}

void SD_Init(void) 
{
  SD_CS_1;
  LCD_CS_1;

  Sd2Card card;
  card.init(SPI_FULL_SPEED, SD_CS);
  if (!SD.begin( SD_CS ))  
  {
    Serial.print("SD init failed!");
    while (1);           
  }
  else
  {
    Serial.println("SD init OK!");
  }
}

/**************************************************************************
This procedure reads a bitmap and draws it to the screen
its sped up by reading many pixels worth of data at a
time instead of just one pixel at a time. increading the buffer takes
more RAM but makes the drawing a little faster. 120 pixels at a time 
might be a good number
**************************************************************************/
void LCD_ShowBMP(void) 
{
   unsigned char i;
   uint8_t buff[360];
   LCD_Display_Dir(U2D_L2R);
   for (i = 0; i < 4; i++) 
   {
      bmp_file = SD.open(file_name[i]);
      if (! bmp_file)
      {
         Serial.print(file_name[i]);
         Serial.print(" not found");
         continue ;
      } 
      else 
      {
         Serial.print(file_name[i]);
         Serial.print(" had open\r\n");
      }

      if (! Read_bmp_header(bmp_file)) 
      {
         Serial.print("find next bmp file\n");
         continue;
      }
      bmp_file.seek(bmp_info.offset);
      for(int y = 0;y<lcddev.height; y++)
      {
          for(int x = 0; x<4; x++)//4*120=480 pixels a row
          {
             int n=0;
             bmp_file.read(buff, 360); // 120 pixels in RGB888 format ,1 pixel has 3 bytes
             Set_Window(x*120, y, (x+1)*120, y);
             LCD_CS_0;
             LCD_DC_1;
             for(int j=0;j<120;j++)// write the 120 pixels buff to LCD
             {
                 n = j*3;
                 Spi_write_word(RGB888_RGB565(buff[n+2],buff[n+1],buff[n]));
             }
             LCD_CS_1;  
          }
      }
      Serial.print(file_name[i]);
      Serial.print(" close\r\n");
      bmp_file.close();
    
      delay(1000);
      delay(1000);
   }
   LCD_Display_Dir(DFT_SCAN_DIR);
}
