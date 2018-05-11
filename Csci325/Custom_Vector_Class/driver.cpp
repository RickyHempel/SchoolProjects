/******************
Name: Ricky Hempel
      Tanner Thurman
      Justin Evans

Date:9/19/2014

File:Driver.cpp

Purpose:Contains a class and a driver program to test a custom 
vector class also prints grades on the srceen from and least to
greatest and prints the avergae of the grades.
********************/

#include <iostream> //STDIN/STDOUT

//includes the gradebook class and header file.
#include "gradebook.h"

//standard namespace
using namespace std;

//main function
int main() {
  
  //declares a gradebook.
  Gradebook grades;
  
  //declares a arry of 100 to input the file name.
  char file_name[100];
  
  //tells the user to input a file 
  cout << "Please enter a file name: ";
  
  //input of file name.
  cin >> file_name;
  
  //reads the data form the file.
  grades.read_data(file_name);
  
  //prints what the grades are to the srceen.
  cout << "Grades for the current assignment are: " << endl;
  
  //function calls the sort function.
  grades.sort();
  
  //function calls to print the grades to the screen
  grades.print();
  
  //prints to the srceen the average for file name.
  cout << endl << endl
       << "Class average for file_name: " << grades.average() << endl;

  //returns 0.
  return 0;
}




