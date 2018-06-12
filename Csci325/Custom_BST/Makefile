#File:Makefile
#Author:Ricky Hempel
#Purpose: Makefile for a BST

#Complier Version
CC=g++

#Flags
CFLAGS=-c -Wall $(DEBUGG)

#Comlies program.
all:treedatabase

treedatabase:driver.o bst.o node.o
	$(CC) driver.o bst.o node.o -o treedatabase

driver.o:driver.cpp bst.h
	$(CC) $(CFLAGS) driver.cpp

bst.o:bst.cpp bst.h node.h node.cpp
	$(CC) $(CFLAGS)bst.cpp

node.o:node.cpp node.h
	$(CC) $(CFLAGS) node.cpp

#Cleans the dictory 
clean:
	rm *.o *~ treedatabase
