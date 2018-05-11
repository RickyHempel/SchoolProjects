/*
 * File: gradebook.cpp
 * Author: Joshua T. Guerin
 * Date: Fall 2014
 * Purpose: Implementation for the gradebook class.
 */

#include <iostream> //STDIN/STDOUT
#include <fstream> //File input

#include "gradebook.h" //Gradebook class.

using namespace std;

int Gradebook::read_data(char file_name[]) {
  int num_grades = 0;
  float temp;
  ifstream infile;
  
  infile.open(file_name);
  
  
  // Read data into vector of grades.
  infile >> temp;
  
  while(infile) {
    grades.push_back(temp);
    num_grades++;
    
    infile >> temp;
  }

  infile.close();

  return num_grades;
}



float Gradebook::average() {
  float avg = 0;
  
  //Calculate sum of grades
  for(unsigned int i=0; i<grades.size(); i++) {
    // avg += grades.at(i);

    // Bonus version:
    avg += grades[i];
  }

  //Prevent division by zero.
  if(grades.size() > 0)
    avg = avg/grades.size();   //Compute and return the average
  
  return avg;
}



void Gradebook::print() {
  //print the contents of grades
  for(unsigned int i=0; i<grades.size(); i++) {
    cout << grades.at(i) << " ";

    //Bonus version:
    //cout << grades[i] << " ";
  }
}


