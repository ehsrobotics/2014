#pragma config(Motor,  port1,            ,             tmotorVex393HighSpeed_HBridge, openLoop)
#pragma config(Motor,  port10,            ,             tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/** Compares a regular VEX 393 motor with a VEX 393 high speed motor.
 */

task main()
{
	for (int i = 0; i < 127; i++)
	{
		wait1Msec(100);
		motor[port1] = i;
		motor[port10] = i;
	}
	wait1msec(1000);
}