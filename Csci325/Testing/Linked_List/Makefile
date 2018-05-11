#File:Makefile
#Author:Ricky Hempel Tanner Thurman Justin Evans.
#Purpose: Makefile for a library list

#Complier Version
CC=g++

#Flags
CFLAGS=-c -Wall 

#Comlies program.
all:library

library:driver.o library.o
	$(CC) driver.o library.o -o library

driver.o:driver.cpp library.h
	$(CC) $(CFLAGS) driver.cpp

library.o:library.cpp library.h book.h
	$(CC) $(CFLAGS) library.cpp

#Cleans the dictory 
clean:
	rm *.o *~ library
