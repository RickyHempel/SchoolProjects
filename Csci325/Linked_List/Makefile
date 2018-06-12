#File:Makefile
#Author:Ricky Hempel
#Purpose: Makefile for a dvd list

#Complier Version
CC=g++

#Flags
CFLAGS=-c -Wall 

#Comlies program.
all:collection

collection:driver.o dvd_collection.o
	$(CC) driver.o dvd_collection.o -o collection

driver.o:driver.cpp dvd_collection.h
	$(CC) $(CFLAGS) driver.cpp

dvd_collection.o:dvd_collection.cpp dvd_collection.h dvd.h
	$(CC) $(CFLAGS) dvd_collection.cpp
#Cleans the dictory 
clean:
	rm *.o *~ collection
