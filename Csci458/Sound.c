/****************
Name Ricky Hempel & Nisha Patel
Purpose source code for ultrasonic.c
Date 10/13/17
**************/
//sesnor info
#pragma config(StandardModel, "EV3_REMBOT")
#pragma config(Sensor, S4, sonar4, sensorEV3_Ultrasonic)
//for motors
tMotor Left_Motor=motorB;
tMotor Right_Motor=motorC;
//main
task main()
{
	//repeat forever
	while (true)
	{
		//repeat until distnace is true or a sensor is touched
		while(SensorValue(sonar4)>9 && getTouchValue(S1) == 0 && getTouchValue(S4) == 0)
		{
			//move the robot foward
			setMotorSpeed(Left_Motor, 50);
			setMotorSpeed(Right_Motor, 50);
		}

	//move the robot backwards
	setMotorSpeed(Left_Motor, -10);
	setMotorSpeed(Right_Motor, -10);
	sleep(1000);

	//if it touches left, go right
	if(getTouchValue(S1) == 0 && getTouchValue(S4)==1)
	{
		//turn right
		motor[Left_Motor]=10;
		motor[Right_Motor]=-10;
		sleep(2000);
	}

	//if it touches right, go left
	else if(getTouchValue(S4) == 0 && getTouchValue(S1)==1)
	{
		//turn right
		motor[Left_Motor]=-10;
		motor[Right_Motor]=10;
		sleep(2000);
	}

	//if it hits the center, turn right
	else if(getTouchValue(S1) == 1 && getTouchValue(S4) == 1)
	{
		motor[Left_Motor]=10;
		motor[Right_Motor]=-10;
		sleep(2000);
	}

	//else turn right
	else if(random(10)<5)
	{
		setMotorSpeed(Left_Motor, 10);
		setMotorSpeed(Right_Motor, -10);
		sleep(1875);
	}
	//finally turn left if all else are not true
	else
	{
		setMotorSpeed(Left_Motor, -10);
		setMotorSpeed(Right_Motor, 10);
		sleep(1875);
	}
  }
}