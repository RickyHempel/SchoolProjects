//tells which port the sensor is in
#pragma config(StandardModel, "EV3_REMBOT")
#pragma config(Sensor, S3,sonar3, sensorEV3_Color)
//for motors
tMotor Left_Motor=motorB;
tMotor Right_Motor=motorC;
task main(){
//calculating threshold by taking a reading on both DARK and LIGHT surfaces,adding them together, then dividing by 2.
	int threshold = 11;
	while(true){
		//if threshold is greater than sensor value.
		if(getColorReflected(S3)<threshold){
			//stops when the line is detected
			setMotorSpeed(Left_Motor, 0);
			setMotorSpeed(Right_Motor, 0);
			sleep(500);
			//reverse
			setMotorSpeed(Left_Motor, -20);
			setMotorSpeed(Right_Motor, -20);
			sleep(2000);
			//randomly chooses a new direction
			//turn right
			if(random(10)<5){
				setMotorSpeed(Left_Motor, 10);
				setMotorSpeed(Right_Motor, -10);
				sleep(1875);
			}
			//turn left
		else {
			setMotorSpeed(Left_Motor, -10);
			setMotorSpeed(Right_Motor, 10);
			sleep(1875);
		}
	}
	//go forward
	setMotorSpeed(Left_Motor,50);
	setMotorSpeed(Right_Motor,50);
	}
}