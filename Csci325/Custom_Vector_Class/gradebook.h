/******************
Name: Ricky Hempel
      Tanner Thurman
      Justin Evans
Date:9/19/14
File:Gradebook.h
Purpose:Class definition (header file)
for the gradebook class.
********************/

//Micoguards
#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include "float_vector.h" //The float vector class that we did  implement

class Gradebook {
  /*
   * Description: A class that collects statistics on the grades of a
   *              number of past students.  The Gradebook class is designed
   *              to test the float_vector (custom vector) class.
   */

 private:
  float_vector grades; //The float vector class that we did implement.
  
 public:
  
  int read_data(char file_name[]);
  /* Description:
   *    Reads the grades from file_name, and stores them in grades.
   *
   * Return value:
   *    The number of entries read.
   */

  float average();
  /*
   * Purpose:
   *    Computes the average grade for this assignment.
   *
   * Return value:
   *    The average grade for the current assignment.
   */


  void print();
  /*
   * Description:
   *    Prints the contents of grades to STDOUT.
   * 
   * Postconditions:
   *    The contents of the current gradebook have been printed to STDOUT.
   */

  void sort(); //Description: Uses a selection sort to sort the grades from least to grades.
};

//Endif Microguard
#endif

