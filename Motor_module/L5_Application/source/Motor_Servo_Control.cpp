/*
 * Motor_Servo_Control.cpp
 *
 *  Created on: Nov 14, 2016
 *      Author: SaurabhDeshmukh
 */
#include "Motor_Servo_Control.h"
#include "lpc_pwm.hpp"


int count_Speed=0;



void Motor_Servo_Set(MASTER_DRIVING_CAR_t rcv_car,double RPM_speed)
{
	static PWM motor(PWM::pwm2, 50);
	    static PWM servo(PWM::pwm1, 50);
	    servo.set(7.2);
	    motor.set(7.5);

	   switch(rcv_car.MASTER_STEER_ENUM)
	   {
	   case FAR_RIGHT:
	       servo.set(10);
	       break;
	   case RIGHT:
	       servo.set(8.2);
	       break;
	   case CENTER:
	       servo.set(7.2);
	       break;
	   case LEFT:
	       servo.set(6.7);
	       break;
	   case FAR_LEFT:
	       servo.set(5.1);
	       break;
	   }

	   switch(rcv_car.MASTER_DRIVE_ENUM)
	   {
	       case REVERSE:
	           motor.set(7.9);
	           break;
	       case STOP:
	           motor.set(7.5);
	           break;
	       case DRIVE:
	       switch(rcv_car.MASTER_SPEED_ENUM)
	       {
	           case LOW:
	             motor.set(7.9);
	           break;
	           case MEDIUM:
	               if(count_Speed<12)
	               {
	                 motor.set(8.1);
	                 count_Speed++;
	               }
	               else
	               {
	                   motor.set(7.9);
	               }
	           break;
	           case HIGH:
	             motor.set(8.3);
	           break;

	           default:
	           break;
	        }
	        break;

	        default:
	        break;
	    }
}

