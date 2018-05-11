/*
  Name: Richard Hempel
  Date: 11/7/2014
  Purpose: Declaring the dvd struct for the dvd_collection.cpp
  File: dvd.h
  
*/

#ifndef dvd_h_
#define dvd_h_

#include <string>//String use.
using namespace std;

//Declaring the struct for dvd
struct dvd{
  //public:    
  string Title; //Stores Title in form of a string.

  string Director; //Stores the Director's name in form of a string
  
  int Release_Year; //Stores the Release Year in form of an integer.
  
  string  Rating; //Stores the Rating in form of an sting i. e. G,PG,PG13, or R
  
  int Runtime; //Stores the Runtime in form of an integer.
			      
};
#endif
