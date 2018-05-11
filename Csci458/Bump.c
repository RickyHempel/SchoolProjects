tMotor Left_Motor=motorB;
tMotor Right_Motor=motorC;
task main(){
	//repeat forever
	while(true){
	//goes forward at 50 speed
	 repeatUntil(getTouchValue(S1) == 1 || getTouchValue(S4) == 1){
		setMotorSpeed(motorB, 50);
		setMotorSpeed(motorC, 50);
} //reverses at 50 speed.

		setMotorSpeed(motorB, -50);
		setMotorSpeed(motorC, -50);
		sleep(1000);
	//if it touches left, go right
		if(getTouchValue(S1) == 0 && getTouchValue(S4)==1){
	//turn right
			motor[Left_Motor]=10;
			motor[Right_Motor]=-10;
			sleep(2000);
	}
	//if it touches right, go left
		else if(getTouchValue(S4) == 0 && getTouchValue(S1)==1){
	//turn left
			motor[Left_Motor]=-10;
			motor[Right_Motor]=10;
			sleep(2000);
		}
	//if touches both go right
		if(getTouchValue(S1) == 0 && getTouchValue(S4) == 0){
			//turn right
			motor[Left_Motor]=10;
			motor[Right_Motor]=-10;
			sleep(2000); 
		}
		wait1Msec(2000);
	}

}