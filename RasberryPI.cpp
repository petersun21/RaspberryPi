#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "i2c.h"
#include "lcd_i2c.h"

#define I2C_FILE_NAME "/dev/i2c-1"



// http://www.quinapalus.com/hd44780udg.html for drawing a symbol
const char symbols[8][8] = {
    {0x04, 0x0E, 0x0E, 0x0E, 0x1F, 0x00, 0x04, 0x00},
	{0x1B, 0x0E, 0x1B, 0x15, 0x15, 0x1B, 0x0E, 0x1b},
	{0x00, 0x01, 0x03, 0x16, 0x1c, 0x08, 0x00, 0x00},
	{0x04, 0x0E, 0x0E, 0x0E, 0x1f, 0x00, 0x40, 0x00},
	{0x00, 0x0A, 0x1F, 0x1F, 0x0E, 0x04, 0x00, 0x00},
	{0x02, 0x03, 0x02, 0x0E, 0x1E, 0x0C, 0x00, 0x00},
	{0x00, 0x0E, 0x15, 0x17, 0x11, 0x0E, 0x00, 0x00},
	{0x00, 0x00, 0x0A, 0x00, 0x11, 0x0E, 0x00, 0x00},
};

const char* txt = "Michelle is Lazy";
const char symb[] = {0,1,2,3,4,5,6,7}
;
int main(int argn, char** arg){
	if (argn < 3) return 1;
    int i2c_dev;
    u8 i;
    lcd lcd0;
    // 0x27 is the address of the i2c device
    i2c_dev = open_i2c(I2C_FILE_NAME, 0x27);
    if(i2c_dev <0){
       printf("Errore: %d\n", i2c_dev);
       return 1;
    }
    lcd_init(&lcd0, i2c_dev);
    lcd_clear(&lcd0);
    for(i=0;i<8;++i)
        lcd_add_char(&lcd0, (u8*) symbols[i], i);
    lcd_print(&lcd0, arg[1], strlen(arg[1]), 0);
    lcd_print(&lcd0, arg[2], strlen(arg[2]), 1);
    close_i2c(i2c_dev);
    return 0;
}
