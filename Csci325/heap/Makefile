#File:Makefile
#Author:Ricky Hempel
#Purpose: Makefile for a library list

#Complier Version
CC=g++
#Debugger
DEBUG= -g -O0

#Flags
CFLAGS=-c -Wall $(DEBUG)

#Comlies program.
all:heap

heap:driver.o heap.o
	$(CC) driver.o heap.o -o heap

driver.o:driver.cpp heap.h
	$(CC) $(CFLAGS) driver.cpp

heap.o:heap.cpp heap.h 
	$(CC) $(CFLAGS) heap.cpp
#Cleans the dictory 
clean:
	rm *.o *~ heap
