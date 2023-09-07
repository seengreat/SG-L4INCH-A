#ifndef __SD_PIC_H__
#define __SD_PIC_H__


#define  SD_CS 6
#define  SD_CS_1  digitalWrite(SD_CS, HIGH) 
#define  SD_CS_0  digitalWrite(SD_CS, LOW)

#define RGB888_RGB565(R,G,B)  (( (R) >> 3 ) << 11 ) | (( (G) >> 2 ) << 5) | ( (B) >> 3)

typedef struct {
  uint32_t Size;
  uint32_t offset;// Start of image data
  uint32_t header_size;
  uint32_t bit_depth;
  uint16_t width;
  uint16_t height;
} BMP_INFO;

void SD_Init(void);
void LCD_ShowBMP(void);

#endif
