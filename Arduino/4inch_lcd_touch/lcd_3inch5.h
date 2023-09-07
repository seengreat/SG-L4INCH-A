#ifndef __LCD_3INCH5_H
#define __LCD_3INCH5_H

#include <SPI.h>
#include <Wire.h>

#define LCD_W   480 //LCD width
#define LCD_H   320 //LCD height

#define LCD_CS   10   
#define LCD_CS_0    digitalWrite(LCD_CS, LOW)
#define LCD_CS_1    digitalWrite(LCD_CS, HIGH)

#define LCD_RST  7
#define LCD_RST_0    digitalWrite(LCD_RST, LOW)
#define LCD_RST_1    digitalWrite(LCD_RST, HIGH)   

#define LCD_DC 8
#define LCD_DC_0    digitalWrite(LCD_DC, LOW)
#define LCD_DC_1    digitalWrite(LCD_DC, HIGH)
  
#define LCD_BL   9   
#define LCD_BL_0    digitalWrite(LCD_BL, LOW)
#define LCD_BL_1    digitalWrite(LCD_BL, HIGH)

#define TEST_P   2   
#define TEST_P_0    digitalWrite(TEST_P, LOW)
#define TEST_P_1    digitalWrite(TEST_P, HIGH)

#define TP_CS 5
#define TP_CS_0    digitalWrite(TP_CS, LOW)
#define TP_CS_1    digitalWrite(TP_CS, HIGH)

#define SD_CS 6
#define SD_CS_0    digitalWrite(SD_CS, LOW)
#define SD_CS_1    digitalWrite(SD_CS, HIGH)


#define LCD_SIZE   (LCD_W*LCD_H*2)    

#define WHITE        0xFFFF
#define BLACK        0x0000
#define BLUE         0x001F
#define GBLUE        0X07FF
#define RED          0xF800
#define MAGENTA      0xF81F
#define GREEN        0x07E0
#define CYAN         0x7FFF
#define YELLOW       0xFFE0
#define BROWN        0XBC40
#define BRRED        0XFC07
#define GRAY         0X8430

#define ORANGE       0xFBE0
#define PURPLE       0x881F

//LCD重要参数集
typedef struct  
{                        
  uint16_t width;      //LCD width
  uint16_t height;     //LCD height
  uint8_t  dir;        //LCD display direction
  uint8_t  wramcmd;    //Start writing to GRAM command
  uint8_t  setxcmd;    //set x coordinate command
  uint8_t  setycmd;    //set y coordinate command  
}_lcd_dev;    

//LCD parameter
extern _lcd_dev lcddev; //Manage important LCD parameters
//define LCD pen color and background color    
extern uint16_t  POINT_COLOR;//The color of the dot, the default is red    
extern uint16_t  BACK_COLOR; //Background color. Default is white
   
//Scan Direction Definition
#define L2R_U2D  0 //left to right,up to down
#define L2R_D2U  1 //left to right,down to up
#define R2L_U2D  2 //right to left,up to down
#define R2L_D2U  3 //right to left,down to up

#define U2D_L2R  4 //up to down,left to right
#define U2D_R2L  5 //up to down,right to left
#define D2U_L2R  6 //down to up,left to right
#define D2U_R2L  7 //down to up,right to left  

#define DFT_SCAN_DIR   D2U_R2L

//color definition
#define WHITE            0xFFFF
#define BLACK            0x0000   
#define BLUE             0x001F  
#define BRED             0XF81F
#define GRED             0XFFE0
#define GBLUE            0X07FF
#define RED              0xF800
#define MAGENTA          0xF81F
#define GREEN            0x07E0
#define CYAN             0x7FFF
#define YELLOW           0xFFE0
#define BROWN            0XBC40 
#define BRRED            0XFC07 
#define GRAY             0X8430 

#define BACKGROUND_COLOR   WHITE


void Lcd_Gpio_Init(void);
void Lcd_Init(void); 
void LCD_Scan_Dir(uint8_t dir);
void LCD_Display_Dir(uint8_t dir);
void LCD_Clear(uint16_t color);
void LCD_Clearx(void);
void Draw_Point(uint16_t x, uint16_t y, uint16_t color);
void BlackLight_SetValue(uint16_t value);

void Spi_write_word(uint16_t data);
void LCD_Set_Cursor(uint16_t x, uint16_t y);
void Set_Window(uint16_t start_x, uint16_t start_y, uint16_t end_x, uint16_t  end_y);
void Gui_fill_color(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);


#endif
