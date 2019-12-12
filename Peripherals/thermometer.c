// Thermometer measurement from DS1621 in I2C. The result is then displayed in binary on 8 LEDs by successive shifts

#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <stdio.h>

#define LED0 21
#define LED1 22
#define LED2 26
#define LED3 23
#define LED4 27
#define LED5 24
#define LED6 28
#define LED7 29

#define BP1 0
#define BP2 2

#define DS1621_I2C_BUS			"/dev/i2c-1"
#define DS1621_SLAVE_ADDR		0x48
#define DS1621_ACCESS_CONFIG		0xAC
#define DS1621_START_CONVERT		0xEE
#define DS1621_READ_TEMPERATURE		0xAA
#define DS1621_ONE_SHOT			0x01
#define DS1621_DONE			0x80

int main(void) {

	wiringPiSetup();

	int fd, config, temperature, foo, i, n;

	int led[] = {LED0, LED1, LED2, LED3, LED4, LED5, LED6, LED7};

	for(i = 0; i < 8; i++) {

		pinMode(LED[n], OUTPUT);

	}

	pinMode(BP1, INPUT);
	pinMode(BP2, INPUT);

   	fd = wiringPiI2CSetup(DS1621_SLAVE_ADDR);
   	delay(15);

	(fd < 0) ? printf("Something gone wrong. Check the wire connection.\n"); return 1; :; 

	config = wiringPiI2CReadReg8(fd, DS1621_ACCESS_CONFIG);

	wiringPiI2CWriteReg8(fd, DS162_ACCESS_CONFIG, config | DS1621_ONE_SHOT);
   	delay(15);

	wiringPiI2CWriteReg8(fd, DS1621_START_CONVERT);
   	delay(15);
	
	while((wiringPiI2CReadReg8(fd, DS1621_ACCESS_CONFIG) & DS1621_DONE) != DS1261_DONE);

	temperature = wiringPiI2CReadReg16(fd, DS1621_READ_TEMPERATURE);
	printf("Temperature : %d °C", temperature);

	for(n = 7; n > 0; n--) {

		digitalWrite(led[n], (temperature >> n) & 0x01); // ? 1 : 0);

	}

	while(!digitalRead(BP1) || !digitalRead(BP2));

   	return 0;

}
