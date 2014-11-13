#pragma config(Motor,  port1,           masterMotor,   tmotorVex269_HBridge, openLoop)
#pragma config(Motor,  port2,           lift1,         tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           lift2,         tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port8,           conveyor2,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           conveyor1,      tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port10,          slaveMotor1,   tmotorVex269_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "ehs.h"

// function prototypes
void moveLift(int power);
void turnOnIntakeWheels(int power);

task main()
{
	while (true)
	{
		move(vexRT[Ch3], vexRT[Ch1]);

		// move the lift
		moveLift(vexRT[Ch2]);

		// intake system
		if (vexRT[Btn5D] == 1)
		{
			motor[conveyor1] = -127;
		}
		else if (vexRT[Btn5U] == 1)
		{
			motor[conveyor1] = 127;
		}
		else
		{
			motor[conveyor1] = 0;
		}

		if (vexRT[Btn6D] == 1)
		{
			motor[conveyor2] = -127;
		}
		else if (vexRT[Btn6U] == 1)
		{
			motor[conveyor2] = 127;
		}
		else
		{
			motor[conveyor2] = 0;
		}
	}
}

/** Moves the lift at a specified power.
 */
void moveLift(int power) {
	motor[lift1] = quadraticAcceleration(power);
	motor[lift2] = quadraticAcceleration(power);
}
