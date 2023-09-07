
#ifndef __LCD_TOUCH_H_
#define __LCD_TOUCH_H_

#include <SPI.h>
#include <Wire.h>

#define READ_TIMES  5    //Number of readings
#define LOST_VAL    1    //Discard value

#define TP_ERR_RANGE 50  //tolerance scope

//Touch
#define TP_CS 5
#define TP_CS_0    digitalWrite(TP_CS, LOW)
#define TP_CS_1    digitalWrite(TP_CS, HIGH)

#define TP_IRQ 4
#define GET_TP_IRQ    digitalRead(TP_IRQ)

#define TP_BUSY 3
#define GET_TP_BUSY    digitalRead(TP_BUSY)
#define TP_BUSY_1     digitalWrite(TP_BUSY, HIGH)
#define TP_BUSY_0     digitalWrite(TP_BUSY, LOW)

#define TP_PRESS_DOWN    0x80      //Touch screen had pressed  
#define TP_CATH_PRES     0x40     //button has been pressed

typedef struct 
{
  uint16_t x[5];    
  uint16_t y[5];    //Use x[0], y[0] to represent the coordinates of the touch screen during this scan, 
                    //and use x[4], y[4] to store the coordinates of the first press
                          
  uint8_t  statu;        //The state of the pen
                         //b7:Press 1/Release 0 
                         //b6:0, no button pressed; 1. Press a button
////////////Touch screen calibration parameters///////////                
  float xfac;         
  float yfac;
  short xc;           //Physical value of center X coordinate (AD value)
  short yc;           //Physical value of center Y coordinate (AD value)
  uint16_t paint_color;
}tp_dev_t;

extern tp_dev_t tp_dev;  

//
void TP_Init(void);
uint8_t TP_Scan(uint8_t mode);
void TP_Calibrate(void);
void Load_Touch_Draw(void);
void TP_test(void);
#endif
