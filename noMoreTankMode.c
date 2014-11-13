#pragma config(Motor,  port2,           masterMotor,   tmotorVex269_MC29, openLoop)
#pragma config(Motor,  port3,           slaveMotor1,   tmotorVex269_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "ehs.h"

int master = 0; /*! master motor speed */
int slave = 0; /*! slave motor speed */
int turn = 0; /*! the amount by which the robot is turning */

/** Allows the robot to move using one joystick for forward/reverse motion and one for turning.
 * Forward/reverse is vexRT[Ch3]
 * Turning is vexRT[Ch1]
 */
task main()
{
	while (true)
	{
		master = quadraticAcceleration(vexRT[Ch3]);
		slave = quadraticAcceleration(vexRT[Ch3]);

		// apply turns
		turn = vexRT[Ch1];
		master += turn;
		slave -= turn;

		// assign values to motors
		motor[masterMotor] = master;
		motor[slaveMotor1] = slave;
	}
}