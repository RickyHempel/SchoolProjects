#Name-Ricky Hempel
#Date-12/8/17
#Pledge Statement-
#Program Behavior-The program will begin by printing a welcome message and prompting the customer to
#enter a dollar amount. 
#Then print the The printed output begins by reporting the entered dollar amount. Then display the
#number of bills for each denomination printed and a descriptive label identifying each
#denomination(256,32,16,8,2,1) one per line

# READ AN INTEGER AND ECHO PRINT ITS VALUE.
	.data
Prompt: .asciiz “Enter an integer: “
Echo:   .asciiz “Your number is “
	.text# Text segment is unused for now.
main:
	# Print prompt message to enter an integer.
	li $v0, 4
	la $a0, Prompt
	syscall

	# Load register $v0 with code 5 for read integer
	li$v0, 5
	syscall

	# Integer value is returned in register $v0
	move $t0, $v0	
  	# Print echo message.
	li $v0, 4
	la $a0, Echo
	syscall

	# Load register $v0 with code 1 for print integer
	li$v0, 1
	# Put saved input integer value in register $a0	
	move $a0, $t0
	syscall
# End of program
	