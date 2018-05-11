/*
  Name: Richard Hempel, Tanner Thurman, Justin Evans
  Date: 10/20/2014
  Purpose: Declaring the book struct for the library.cpp
  File: book.h
  
*/

#ifndef book_h_
#define book_h_

#include <string>//String use.
using namespace std;

//Declaring the struct for book
struct book{
  //public:	
  book *next; // setting next to be a node.
  
  string Title; //Stores Title in form of a string.
  
  string Author; //Stores the Author's name in form of a string
  
  int Copyright_Year; //Stores the Copyright Year in form of an integer.
  
  int Edition; //Stores the  Edition in form of an integer.
  
  int Number_of_Pages; //Stores the  page numbers in form of an integer.
			      
};
#endif
