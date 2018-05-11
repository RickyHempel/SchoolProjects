#pragma config(StandardModel, "EV3_REMBOT")
#pragma config(Sensor, S3, sonar3, sensorEV3_Color)
tMotor Left_Motor=motorB;
tMotor Right_Motor=motorC;
task main(){
	int threshold = 15; // Light sensor threshold
	//to detect a white line or region
	while(getColorReflected(S3) > threshold){
		setMotorSpeed(Left_Motor, 25);
		setMotorSpeed(Right_Motor, 25);
	}
	setMotorSpeed(motorB, 0);
	setMotorSpeed(motorC, 0);
	wait1Msec(500);
	// to detect a black line
	while(getColorReflected(S3) < threshold){
		setMotorSpeed(Left_Motor, 25);
		setMotorSpeed(Right_Motor, -25);
	}
	setMotorSpeed(Left_Motor, 0);
	setMotorSpeed(Right_Motor, 0);
	while(true){
		//If the Light Sensor reads a value less than 30, then the robot is seeing the
		//black line
		if(getColorReflected(S3) < threshold){
			setMotorSpeed(Left_Motor, 25);
			setMotorSpeed(Right_Motor, 0);
		}

		// If the Light Sensor reads a value greater than or equal to 30, then the robot
		//is not seeing a black line
		else{	
			setMotorSpeed(Left_Motor, 0);
			setMotorSpeed(Right_Motor, 25);
		}
	}
}