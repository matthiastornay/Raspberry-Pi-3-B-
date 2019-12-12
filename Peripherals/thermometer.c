// Thermometer measurement from DS1621 in I2C 

#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <stdio.h>

#define DS1621_I2C_BUS				"/dev/i2c-1"
#define DS1621_SLAVE_ADDR			0x48
#define DS1621_ACCESS_CONFIG		0xAC//h
#define DS1621_START_CONVERT		0xEE//h
#define DS1621_READ_TEMPERATURE		0xAA//h
#define DS1621_ONE_SHOT				0x01
#define DS1621_DONE					0x80

int main(void) {

	wiringPiSetup();

	int fd, config, temperature;
	
   	fd = wiringPiI2CSetup(DS1621_SLAVE_ADDR);

	(fd < 0) ? printf("Erreur à l'initialisation. Vérifiez que le périphérique est bien connecté.\n"); return 1; :; 

	config = wiringPiI2CReadReg8(fd, DS1621_ACCESS_CONFIG);
	wiringPiI2CWriteReg8(fd, DS162_ACCESS_CONFIG, config | DS1621_ONE_SHOT);

	wiringPiI2CWriteReg8(fd, DS1621_START_CONVERT);
	
	while((wiringPiI2CReadReg8(fd, DS1621_ACCESS_CONFIG) & DS1621_DONE) != DS1261_DONE);

	temperature = wiringPiI2CReadReg16(fd, 0xAAh);
	printf("Temperature : %d °C", temperature);

   	return 0;

}
