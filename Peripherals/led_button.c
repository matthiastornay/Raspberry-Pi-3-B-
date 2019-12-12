// LED + push button

#include <stdio.h>
#include <wiringPi.h>

#define LED1 21
#define LED2 22
#define BP1 0
#define BP2 2

int main (void) {

        wiringPiSetup();

        pinMode(LED1, OUTPUT); // GPIO configured as an output
        pinMode(LED2, OUTPUT);
        pinMode(BP1, INPUT);
        pinMode(BP2, INPUT);

        while(1) {

                if(!digitalRead(BP1) && digitalRead(BP2)) {

                        digitalWrite(LED1, 1);
                        digitalWrite(LED2, 0);

                } else if(digitalRead(BP1) && !digitalRead(BP2)) {

                        digitalWrite(LED1, 0);
                        digitalWrite(LED2, 1);

                } else if(!digitalRead(BP1) && !digitalRead(BP2)) {

                        digitalWrite(LED1, 0);
                        digitalWrite(LED2, 0);		

                        return 0;

                }

        }	

}
