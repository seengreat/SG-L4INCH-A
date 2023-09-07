/********************************
 *  Seengreat 4 Inch LCD Display demo
 *  Author(s):Andy Li from Seengreat
 * ********************************/
 
#include "lcd_4inch.h"
#include "sd_pic.h"
#include "lcd_gui.h"
/*************************************
 * CLK     --> D13
 * MISO    --> D12
 * MOSI    --> D11
 * LCD_CS  --> D10  
 * LCD_BL  --> D9 
 * LCD_DC  --> D8
 * LCD_RST --> D7 
 * SD_CS   --> D6  
 * TP_CS   --> D5 
 * TP_IRQ  --> D4
 * TP_BUSY --> D3 
**************************************/
/******************************
when set DFT_SCAN_DIR to D2U_R2L:
 * 1------------> x (1~480) 
 * |
 * |
 * |
 * |
 * y (1~320)
 * */

void setup()
{
    Lcd_Gpio_Init();
    Serial.begin(115200);
      
    SPI.setDataMode(SPI_MODE0);
    SPI.setBitOrder(MSBFIRST);
    SPI.setClockDivider(SPI_CLOCK_DIV2);
    SPI.begin();
    
    Serial.println("SD Card Init...");  
    SD_Init();
    Serial.println("4Inch LCD Init..."); 
    Lcd_Init();

    Gui_draw_line(10, 1, 10, 320, RED, 2, SOLID);
    Gui_draw_line(15, 1, 15, 320, ORANGE, 2, SOLID);
    Gui_draw_line(20, 1, 20, 320, YELLOW, 2, SOLID);
    Gui_draw_line(25, 1, 25, 320, GREEN, 2, SOLID);
    Gui_draw_line(30, 1, 30, 320, GBLUE, 2, SOLID);
    Gui_draw_line(35, 1, 35, 320, BLUE, 2, SOLID);
    Gui_draw_line(40, 1, 40, 320, PURPLE, 2, SOLID);

    delay(2000);
    Serial.print("LCD_Show bmp file...\r\n");
    LCD_ShowBMP(); 
}


void loop()
{

}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
