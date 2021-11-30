# NTS1-Custom-Panel

Work in progress for a custom panel for Korg NTS-1 Programmable Synthesizer. Use at your own risk, no liabilities assumed. 

At this time the code is simply a stub that tests the encoders, display, and EEPROM ( 24LC512 Microchip Technologies, also can use the 24LC1025 or 24LC256) 

This code is being developed on an STMicroelectronics STM32F0308-Discovery evaluation board... which is a discontinued item.

It has been succesfully flashed and run on a STM32F051R8T6 discobvery board which is currently available from ST Microelectronics.  https://estore.st.com/en/products/evaluation-tools/product-evaluation-tools/mcu-mpu-eval-tools/stm32-mcu-mpu-eval-tools/stm32-discovery-kits/stm32f0discovery.html

The display is a common .96" i2c OLED SSD1306 64 x 128 pixel unit. The default address for these varies, so check yours with an i2c scanning sketch, requires the display library from https://github.com/adafruit/Adafruit_SSD1306

Place all files in a single sketch folder, and add the board definitions at https://raw.githubusercontent.com/korginc/nts-1-customizations/master/Arduino/package_nts1_custom_panels_index.json to your arduino IDE ( or use the source to adapt the method of your choice ) It requires the library files added by this board definition or they can be manually retrieved from https://github.com/korginc/nts-1-customizations/

 



