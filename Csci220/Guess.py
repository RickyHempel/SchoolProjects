#Ricky Hempel
#Updated 6/12/18
#This is a guess the number game.
import random

guessesTaken = 0

print('Hello! What is your name?')
#stores name in input
myName = input() 

#Gets a random number between 1 and 20
number = random.randint(1, 20)
print('Well, ' + myName + ', I am thinking of a number between 1 and 20.')

while guessesTaken < 6:
     #Checks if the guess is correct
    print('Take a guess.') 
    guess = input()
    guess = int(guess)

    guessesTaken = guessesTaken + 1
	
	# Tells user information about the guessed number

    if guess < number:
        print('Your guess is too low.') 
    if guess > number:
        print('Your guess is too high.')

    if guess == number:
        break
#Tells users information about the number of guesses they took
if guess == number:
    guessesTaken = str(guessesTaken)
    print('Good job, ' + myName + '! You guessed my number in ' + guessesTaken + ' guesses!')
#Tells users the number
if guess != number:
    number = str(number)
    print('Nope. The number I was thinking of was ' + number)

