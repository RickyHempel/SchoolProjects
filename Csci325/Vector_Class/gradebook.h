/*
 * File: gradebook.h
 * Author: Joshua T. Guerin
 * Date: Fall 2014
 * Purpose: Implementation for the gradebook class.
 */

#ifndef GRADEBOOK_H
#define GRADEBOOK_H
#include <iostream>
#include <vector>
using namespace std;
class Gradebook {
 private:
  std::vector<float> grades;
  
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
};


#endif

