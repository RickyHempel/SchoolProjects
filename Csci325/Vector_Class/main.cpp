/*
 * File: driver.cpp
 * Name: Joshua T. Guerin
 * Date: Fall 2014
 * Purpose: Contains a class and a driver program to test a custom vector class.
 */

#include <iostream> //STDIN/STDOUT

#include "gradebook.h"

using namespace std;

int main() {
  Gradebook grades;
  char file_name[100];

  cout << "Please enter a file name: ";
  cin >> file_name;
  
  //Calculate average, print to the user.
  grades.read_data(file_name);
  cout << "Grades for the current assignment are: " << endl;
  grades.print();
  cout << endl << endl
       << "Class average for file_name: " << grades.average() << endl;
  
  return 0;
}




