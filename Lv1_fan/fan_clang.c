#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <softPwm.h>

#define MOTOR1 20
#define MOTOR2 21

//buttons
#define Speed 5
#define Direction 6
#define Stop 13

//speed restriction(to prevent motor overheating)
float Speed_Lim(float speed){
	if(speed > 100){
		speed = 100;
		}
	return speed;
	}

int main(void){
    int motor_speed = 0;
    int dircnt = 0;
    int stp = 0;

    wiringPiSetupGpio();
    softPwmCreate(MOTOR1,0,100);
    softPwmCreate(MOTOR2,0,100);
    pinMode(Speed, INPUT);
    pinMode(Direction, INPUT);
    pinMode(Stop, INPUT);

    while(1){
	    if(digitalRead(Speed)==HIGH){
            motor_speed = motor_speed+20;
            Speed_Lim(motor_speed);
            softPwmWrite(MOTOR1,motor_speed);
            softPwmWrite(MOTOR2,0);
            delay(500);
		}
	    if(digitalRead(Direction)==HIGH){
            dircnt++;
            if(motor_speed==0){
                motor_speed = motor_speed+20;
                dircnt = 0;
                }
            if(dircnt%2 == 1){
                softPwmWrite(MOTOR1,0);
                softPwmWrite(MOTOR2,motor_speed);
                }
            else{
                softPwmWrite(MOTOR1,motor_speed);
                softPwmWrite(MOTOR2,0);
                }
            delay(500);
		}
	    if(digitalRead(Stop)==HIGH){
            stp++;
            motor_speed = 0;
            dircnt = 0;
            softPwmWrite(MOTOR1,motor_speed);
            softPwmWrite(MOTOR2,motor_speed);
            delay(500);
		}
	}
    return 0;
}
