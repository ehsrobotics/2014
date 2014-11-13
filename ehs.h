/* A library of functions, constants, and other miscellaneous stuff. */

/** Converts controller values into motor values on a quadratic curve.
 *  Takes a value between -127 and 127. It outputs an int between -127 and 127 based on
 *  a quadratic curve. The equation is \f$y = \frac{1}{127}x^2\f$
 */
int quadraticAcceleration(int input /*! input from the controller (an int between -127 and 127) */)
{
	if (input < 0)
	{
		return (int) ((1.0/127.0) * input * input * -1);
	}
	else
	{
		return (int) ((1.0/127.0) * input * input);
	}
}

/** Moves the robot forward or backwards at <code>power</code> with the specified turn.<br />
 * <table><tr><td>To move forward, set <code>power</code> to an integer</td> <td><b>1 to 127</b></td></tr>
 * <tr><td>To stop, set <code>power</code> to</td> <td><b>0</b><br /></td></tr>
 * <tr><td>To move backwards, set <code>power</code> to an integer</td> <td><b>-1 to -127</b></td></tr> </table><br />
 * <table><tr><td>To go straight, set <code>turn</code> to</td> <td><b>0</b></td></tr>
 * <tr><td>To turn, set <code>turn</code> to an integer</td> <td><b>-127 to 127</b></td></tr> </table>
 */
void move(int power/*! The power of the motors */, int turn /*! How much the robot turns. */)
{
	int master = power;
	int slave = power;

	// apply turns
	master += turn;
	slave -= turn;

	// assign values to motors
	motor[masterMotor] = master;
	motor[slaveMotor1] = slave;

}

/** Stops all motors that move the robot.
 */
void stopMoving()
{
	motor[masterMotor] = 0;
	motor[slaveMotor1] = 0;
}
