# DS1621 / I2C - Reminder

i2cdetect 1 returns 0x48 for the DS1621 adress.

___Start the temperature acquisition :___
	0xEEh

___Read or write the converter configuration : ___
	0xACh

___Read the last temperature conversion : ___
	0xAAh

___Switch to the one shot mode :___
	modifier le bit 1SHOT du registre de configuration (LSB)

___Read the configuration byte of the temperature sensor :___
	i2cget -y 1 0x48 0xACh 	-> R/W = 1

___Start an acquisition (no acquisition end flag) :___
	i2cset -y 1 0x48 0xEEh

___Read the result of the acquisition (in hexadecimal !) :___
	i2cget -y 1 0x48 0xAAh

    #define DS1621_I2C_BUS			1
    #define DS1621_SLAVE_ADDR		0x48
    #define DS1621_ACCESS_CONFIG		0xACh
    #define DS1621_START_CONVERT		0xEEh
    #define DS1621_READ_TEMPERATURE		0xAAh
    #define DS1621_ONE_SHOT			0x01
    #define DS1621_DONE			0x80

***

___To use the I2C in wiringPi, we start by entering :___
	#include <wiringPiI2C.h>

___Generate the executable :___
	gcc script.c -o script -lwiringPi

___Initialize the I2C communication with the peripheral ID :___
	wiringPiI2CSetup(DS1621_SLAVE_ADDR);

___Write on the I2C bus :___
	fd = wiringPiI2CSetup(DS1621_SLAVE_ADDR);
	wiringPiI2CWrite(fd, data);

___Write an 8 or 16 bit word in a given register :___
	fd = wiringPiI2CSetup(DS1621_SLAVE_ADDR);
	wiringPiI2CWriteReg8 (fd, reg, data) ;
	wiringPiI2CWriteReg16 (fd, reg, data) ;

___Read an 8 or 16 bit word of a given register:___
	fd = wiringPiI2CSetup(DS1621_SLAVE_ADDR);
	wiringPiI2CReadReg8 (fd, reg) ;
	wiringPiI2CReadReg16 (fd, reg) ;












