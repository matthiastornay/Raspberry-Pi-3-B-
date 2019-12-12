#include <stdio.h>
#include <wiringPi.h>

#define LED1 21
#define LED2 22
#define LED3 26
#define LED4 23
#define LED5 27
#define LED6 24
#define LED7 28
#define LED8 29

int main (void) {

	int i, j;
	
	wiringPiSetup();

	pinMode(LED1, OUTPUT);
	pinMode(LED2, OUTPUT);
	pinMode(LED3, OUTPUT);
	pinMode(LED4, OUTPUT);
	pinMode(LED5, OUTPUT);
	pinMode(LED6, OUTPUT);
	pinMode(LED7, OUTPUT);
	pinMode(LED8, OUTPUT);	

	int led[] = {LED1, LED2, LED3, LED4, LED5, LED6, LED7, LED8};
		
	while(1) {

		for(i = 0; i < 8; i++) {

			digitalWrite(led[i], 1);

			delay(500);

			digitalWrite(led[i], 0);

		}

		delay(500);

	}

}
