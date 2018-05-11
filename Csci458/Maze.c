//sensor info
#pragma config(StandardModel, "EV3_REMBOT")
#pragma config(Sensor, S1, sonar1, sensorEV3_Ultrasonic)
#pragma config(Sensor, S2, sonar2, sensorEV3_Touch)
/*
This program assumes you are using the standard LEGO Education robot
Sensor Ports:
S1 = Ultrasonic
S3 = Touch
*/
//motors
tMotor Left_Motor=motorB;
tMotor Right_Motor=motorC;
task main()
{
//loop forever
	while (true){
		// if wall distance from wall is less then 5 turn left
		if (SensorValue(sonar1) < 5){
			setMotorSpeed(Left_Motor,0);
			setMotorSpeed(Right_Motor,25);
		}
	// else turn right
		else{
		setMotorSpeed(Left_Motor,25);
		setMotorSpeed(Right_Motor,0);
		}

	//if sensor is touched back up and do a 90 degree turn
		if(SensorValue(sonar2)==1){
			setMotorSpeed(Left_Motor,-10);
			setMotorSpeed(Right_Motor,-10);
			sleep(550);
			setMotorSpeed(Left_Motor,-10);
			setMotorSpeed(Right_Motor,10);
			sleep(1750);
		}
	//if there is not a wall back and right turn
		if(SensorValue(sonar1) > 29){
			setMotorSpeed(Left_Motor,10);
			setMotorSpeed(Right_Motor,10);
			sleep(1000);
			setMotorSpeed(Left_Motor,10);
			setMotorSpeed(Right_Motor,-10);
			sleep(1000);
		}
		//if end of maze is found stop and stop all task
		if(SensorValue(sonar1)> 90) {
		setMotorSpeed(Left_Motor,0);
		setMotorSpeed(Right_Motor,0);
		sleep(1000);
		stopAllTasks();
		}
	}
}