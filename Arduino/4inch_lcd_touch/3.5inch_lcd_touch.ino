#include "lcd_3inch5.h"
#include "lcd_touch.h"
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
    TP_Init();
    Lcd_Gpio_Init();
    //set Serial
    Serial.begin(115200);
      
    SPI.setDataMode(SPI_MODE0);
    SPI.setBitOrder(MSBFIRST);
    SPI.setClockDivider(SPI_CLOCK_DIV2);
    SPI.begin();
    
    Serial.println("3.5Inch LCD Init..."); 
    Lcd_Init();

    Gui_draw_line(10, 1, 10, 320, RED, 2, SOLID);
    Gui_draw_line(15, 1, 15, 320, ORANGE, 2, SOLID);
    Gui_draw_line(20, 1, 20, 320, YELLOW, 2, SOLID);
    Gui_draw_line(25, 1, 25, 320, GREEN, 2, SOLID);
    Gui_draw_line(30, 1, 30, 320, GBLUE, 2, SOLID);
    Gui_draw_line(35, 1, 35, 320, BLUE, 2, SOLID);
    Gui_draw_line(40, 1, 40, 320, PURPLE, 2, SOLID);
//    
    Gui_draw_line(70, 10, 480, 10, BLACK, 1, SOLID);
    Gui_draw_line(70, 20, 480, 20, RED, 2, DOTTED);
    Gui_draw_line(70, 30, 480, 30, YELLOW, 3, SOLID);
    Gui_draw_line(70, 40, 480, 40, MAGENTA, 4, DOTTED);
//    
    Gui_draw_rectangle(70, 80, 100, 120, RED, 1, EMPTY);
    Gui_draw_rectangle(110, 80, 140, 120, GREEN, 1, EMPTY);
    Gui_draw_rectangle(150, 80, 180, 120, BLUE, 1, EMPTY);

    Gui_fill_color(220, 80, 260, 120, RED);
    Gui_fill_color(290, 80, 330, 120, GREEN);
    Gui_fill_color(360, 80, 400, 120, BLUE);
//
    Gui_draw_circle(370, 180, 20, GREEN, 1, FULL);
    Gui_draw_circle(370, 180, 30, RED, 2, EMPTY);
    Gui_draw_circle(370, 180, 40, BLUE, 3, EMPTY);
    
    Gui_draw_str(80, 160, "0123456789", &Font24, BLACK, WHITE);
    Gui_draw_str(80, 195, "SEENGREAT!", &Font24, RED, WHITE);
    Gui_draw_str(80, 230, "www.seengreat.com", &Font24, BLUE, WHITE);
    Gui_draw_str(80, 265, "3.5inch LCD Display!", &Font24, RED, WHITE);

    delay(2000);
    Serial.println("Init Touch Pad...");
    Load_Touch_Draw();
    Serial.println("Drawing...");
}


void loop()
{
   TP_test();
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
