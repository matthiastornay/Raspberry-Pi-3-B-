// Testing the PWM 

#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

#define LED1 21

int main (void) {

    int i, pwm;	

    wiringPiSetup();
    pinMode(LED1, PWM_OUTPUT);

    if(!softPwmCreate(LED1, 0, 100)) {

        for(i = 0; i < 100; i++) {

            softPwmWrite(LED1, i);

            delay(150);

        }

    }

    return 0;

}
