#Name-Ricky Hempel
#Date-12/8/17
#Pledge Statement-I pledge that this assigment is submitted as an independent work by RickyHempel
#Program Behavior-The program will begin by printing a welcome message and prompting the customer to
#enter a dollar amount. 
#Then print the printed output begins by reporting the entered dollar amount. Then display the
#number of bills for each denomination printed and a descriptive label identifying each
#denomination(256,32,16,8,2,1) one per line

        .data
#prompt for user to input data.
Prompt: .asciiz "Greetings! I’m your robot bank teller.\nHow many power-of-two dollars do you want?\n"
#mess1 to 8 is output to the user.
mess1:  .asciiz "Here are your $" 

mess2:	.asciiz " Robo Bucks:\n"

mess3:  .asciiz " two-hundred-fifty-six dollar bills\n"

mess4:	.asciiz " thirty-two dollar bills\n"

mess5:  .asciiz " sixteen dollar bills\n"

mess6:  .asciiz " eight dollar bills\n"

mess7:  .asciiz " two dollar bills\n"

mess8:  .asciiz " one dollar bills\n"

        .text # Text segment is unused for now.
main:
        # load 4 to v0
        li $v0, 4
	# load prompt to a0
        la $a0, Prompt
	#syscall to display prompt.
        syscall

        # Load register $v0 with code 5 for read integer
        li$v0, 5
	#syscall to read integer
        syscall

        # Integer value is returned in register $v0 and move to t0
        move $t0, $v0
         # load 4 to v0
        li $v0, 4
	# load a mess to a0
        la $a0, mess1
	#syscall to display mess.
        syscall

        # Load register $v0 with code 1 for print integer
        li $v0, 1
        # Put saved input integer value in register $a0
        move $a0, $t0
	#syscall to print integer
        syscall
	
	#load t1 with 0
	li  $t1,0
	#move input value to t0
	move $t0,$a0
	#load t2 with 256 
	li  $t2,256

	#loop to subtract and add to counter. 
	LOOP0:  blt  $t0, $t2,END_WHILE0
		#subtracts t0 from t2 and stores in t0 
		sub $t0,$t0,$t2
		#add one to t1
		addi $t1,$t1,1 
		b LOOP0
	END_WHILE0:

	
	#print output message
	li $v0,4
	# load a mess to a0
	la $a0,mess2
	#syscall to display mess.
	syscall

	# Load register $v0 with code 1 for print integer
	li $v0,1
	#move t1 to a0
	move $a0, $t1
	#syscall to display integer
	syscall

	# load 4 to v0
	li $v0,4
	# load a mess to a0
        la $a0,mess3
	#syscall to display mess.
        syscall

	#load t1 with 0
	li $t1,0
	#load t2 with 32
        li  $t2,32
	#loop to subtract and add to counter. 
        LOOP1:  blt  $t0, $t2,END_WHILE1
	#subtracts t0 from t2 and stores in t0 
                sub $t0,$t0,$t2
		#add one to t1
                addi $t1,$t1,1
                b LOOP1
        END_WHILE1:

	# Load register $v0 with code 1 for print integer
	li $v0,1
	#move t1 to a0
        move $a0, $t1
	#syscall to display integer
        syscall
	# load 4 to v0
        li $v0,4
	# load a mess to a0
        la $a0,mess4
	#syscall to display mess.
        syscall

	#load t1 with 0	
	li $t1,0
	#load t2 with 16
        li  $t2,16
	#loop to subtract and add to counter. 
        LOOP2:  blt  $t0, $t2,END_WHILE2
	#subtracts t0 from t2 and stores in t0 
                sub $t0,$t0,$t2
		#add one to t1
                addi $t1,$t1,1
                b LOOP2
        END_WHILE2:

	# Load register $v0 with code 1 for print integer
	li $v0,1
	#move t1 to a0
        move $a0, $t1
	#syscall to print integer
        syscall
	# load 4 to v0
        li $v0,4
	# load a mess to a0
        la $a0,mess5
	#syscall to display mess.
        syscall

	#load t1 with 0
	li $t1,0
	#load t2 with 8
        li  $t2,8
	#loop to subtract and add to counter. 
        LOOP3:  blt  $t0, $t2,END_WHILE3
		#subtracts t0 from t2 and stores in t0 
                sub $t0,$t0,$t2
		#add one to t1
                addi $t1,$t1,1
                b LOOP3
        END_WHILE3:

 	# Load register $v0 with code 1 for print integer
	li $v0,1
	#move t1 to a0
        move $a0, $t1
	#syscall to print integer
        syscall
	# load 4 to v0
        li $v0,4
	# load a mess to a0
        la $a0,mess6
	#syscall to display mess.
        syscall


	#load t1 with 0		
	li $t1,0
	#load t2 with 2
        li  $t2,2
	#loop to subtract and add to counter. 
        LOOP4:  blt  $t0, $t2,END_WHILE4
		#subtracts t0 from t2 and stores in t0 
                sub $t0,$t0,$t2
		#add one to t1
                addi $t1,$t1,1
                b LOOP4
        END_WHILE4:

	# Load register $v0 with code 1 for print integer
	li $v0,1
	#move t1 to a0
        move $a0, $t1
	#syscall to print integer
        syscall
	# load 4 to v0
        li $v0,4
	# load a mess to a0
        la $a0,mess7
	#syscall to display mess.
        syscall

	#load t1 with 0
	li $t1,0
	#load t2 with 1
        li  $t2,1	
	#loop to subtract and add to counter. 
        LOOP5:  blt  $t0, $t2,END_WHILE5
		#subtracts t0 from t2 and stores in t0 
                sub $t0,$t0,$t2
		#add one to t1
                addi $t1,$t1,1
                b LOOP5
        END_WHILE5:

 	# Load register $v0 with code 1 for print integer
	li $v0,1
	#move t1 to a0
        move $a0, $t1
	#syscall to print integer
        syscall
	# load 4 to v0
        li $v0,4
	# load a mess to a0
        la $a0,mess8
	#syscall to display mess.
        syscall


	#load v0 with 10 
	li $v0, 10  
	#ends program                                                                                                                                                             
    	syscall





#End of program
	
