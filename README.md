SG-L4INCH-A from seengreat:www.seengreat.com
=======================================
# Instructions
## 1.1、Overview
This product is a 4-inch resistive touchscreen display with a high-performance and user-friendly design based on the Arduino standard interface. It can be folded and parked at any angle up to 180 degrees, making it an ideal choice for Arduino developers and electronics enthusiasts. Combining resistive touchscreen technology with a high-resolution 4-inch colors display, it offers an intuitive user interface and rich display capabilities. We provide example codes for both the Arduino UNO and NUCLEO-F103RB versions.<br>
__Features__<br>
4-inch screen size, compact and portable, capable of folding at any angle up to 180°;<br>
The display boasts a high resolution of 320×480, presenting clear, sharp images and text;<br>
Utilizes resistive touch screen technology, enabling touch interaction, allowing users to input and control operations directly on the screen;<br>
Supports the Arduino standard interface and is compatible with the NUCLEO series of development boards;<br>
Provides open-source example programs suitable for the Arduino UNO and NUCLEO-F103RB development boards.<br>
__Specifications__
|Driver Chip	|LCD control chip ST7796S|
|----------------------|----------------------------|
|touch panel control chip |XPT2046|
|Type	|TFT|
|Communication Interface	|SPI|
|Display Color	|RGB ,65K colors|
|Resolution	|480x320 (Pixel)|
|I/O Voltage	|3.3V/5V|
|Product Dimensions |96mm*66mm|<br>
# Usage
## 2.1、Interface Definition
|Label	|Arduino UNO	|NUCLEO	|Description|
|-----------|----------------------|-----------|-------------|
|5V	|5V	|5V	|5V Power Input|
|GND	|GND	|GND	|Power Ground|
|CLK	|D13|	PA5|	SPI Clock|
|MISO	|D12|	PA6|	SPI Master Input, Slave Output|
|MOSI	|D11|	PA7|	SPI Master Output, Slave Input|
|LCD_CS	|D10|	PB6|	LCD Chip Select|
|LCD_BL	|D9|	PC7|	LCD Backlight|
|LCD_DC	|D8|	PA9|	LCD Data/Command Selection|
|LCD_RST	|D7|	PA8|	LCD Reset|
|SD_CS	|D6|	PB10|	Micro SD Card Chip Select|
|TP_CS	|D5|	PB4|	Touch Panel Chip Select|
|TP_IRQ	|D4|	PB5|	Touch Panel Interrupt|
|TP_BUSY	|D3|	PB3|	Touch Screen Busy Signal|<br>
Table 2-1:  Module Interface Definition<br>
## 2.2 Resource Profile
![SG-L4INCH-A Resource profile.jpg](https://github.com/seengreat/SG-L4INCH-A/blob/main/SG-L4INCH-A%20Reaource%20profile.jpg)<br>
                       Figure 2-1 Resource Overview<br>
## 2.3 Example Program Usage
### 2.3.1 Arduino UNO 
Hardware Interface Configuration Description<br>
Module to Arduino UNO Pin Connection Definition Table：<br>
|Label	|Arduino UNO	|Description|
|-----------|----------------------|-------------|
|5V	|5V	|5V Power Input|
|GND	|GND	|Power Ground|
|CLK	|D13	|SPI Clock|
|MISO	|D12	|SPI Master Input, Slave Output|
|MOSI	|D11	|SPI Master Output, Slave Input|
|LCD_CS	|D10	|LCD Chip Select|
|LCD_BL	|D9	|LCD Backlight|
|LCD_DC	|D8	|LCD Data/Command Selection|
|LCD_RST	|D7	|LCD Reset|
|SD_CS	|D6	|Micro SD Card Chip Select|
|TP_CS	|D5	|Touch Panel Chip Select|
|TP_IRQ	|D4	|Touch Panel Interrupt|
|TP_BUSY	|D3	|Touch Screen Busy Signal|<br>

Table 2-2: Module to Arduino UNO Pin Connection Definition<br>
If you are using an Arduino board that has an ICSP interface, all positions of the ICSP interface DIP switch (as shown in the item 4 of Pin Connection Definition Figure) can be set to the OFF position. If your Arduino board does not have an ICSP interface, all positions of the ICSP interface DIP switch should be set to the ON position.<br>
Since this example program was verified on the Arduino UNO R3 board, the SRAM capacity of this board is only 2KB. Thus, the example program is divided into two project files: image display and touch.<br>

__Image Display Example Program Usage__<br>
1、Properly insert the module into the Arduino UNO development board.<br>
2、For the image display example program "4inch_lcd_show_bmp.ino", before running this program, you should first copy the image files from the PIC folder to the SD card, which should be formatted as FAT. Then insert it into the SD card slot (as seen  in Figure 2-1).<br>
Select the board model(Arduino Uno) and Port number.<br>
3、Next click "Compile", and if there are no compilation errors, click "Upload" to load the example onto the development board.<br>
4、After uploading the image display example program, the screen will sequentially display the images from the SD card.<br>
5、If you want the screen to display other images, you can store the images in the SD card. The image format should be BMP, with a bit depth of 24, and a resolution of 480 (Width) x 320 (Height). Also, modify the content of the "char file_name[4][20]" array in line 11 of the sd_pic.cpp file, i.e., change its content to the names of the images you want to display.<br>
__Touch Screen Example Program Usage__<br>
The touch screen example program "4inch_lcd_touch.ino", when uploaded to the Arduino UNO, will first display lines, rectangles, block fill, circles, and characters, and then enter the touch function display interface.<br>
The "CALIB" button is for screen calibration functionality. Screen calibration parameters have already been filled in the TP_Init() function. Users can also update the values of tp_dev.xfac and tp_dev.yfac based on their own calibration results. After successful calibration, the message "Touch Screen Calibration OK!" will appear on the screen. If calibration fails, calibration will restart. If the user does not perform a calibration action within 10 seconds, the calibration process will automatically exit. <br>
The "CLEAR" button is to clear the screen drawing board content, which can clear all the content drawn by the user on the screen drawing board. The red, green, blue, black, and yellow block buttons are for pen colors. The default pen color is black. If users want to switch colors, they can first press the corresponding color block button and then draw.<br>

Thank you for choosing the products of Shengui Technology Co.,Ltd. For more details about this product, please visit:<br>
www.seengreat.com
