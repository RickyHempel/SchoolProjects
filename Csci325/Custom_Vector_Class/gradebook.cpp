/******************
Name: Ricky Hempel
      Tanner Thurman
      Justin Evans
Date: 9/19/14
File:Gradebook.cpp
Purpose: To have the member functions of the gradebook class,
 to read grades from a file, compute the avergae and print 
them to the screen

********************/


#include <iostream> //STDIN/STDOUT
#include <fstream> //File input
#include "gradebook.h" //Gradebook class.
using namespace std;//namespace standard

//Member function to take in a file name, put the numbers in the arry, and to return the number of grades.
int Gradebook::read_data(char file_name[]) {

  //Declares variables and sets their values
  int num_grades = 0;
  float temp;
  ifstream infile;
  
  //opens a file
  infile.open(file_name);
  

  // Read data into vector of grades.
  infile >> temp;
  
  while(infile) {
    grades.push_back(temp);
    num_grades++;
    
    infile >> temp;
  }
  
  //closes a file VERY IMPORANT!
  infile.close();
  
  //reutrns the number of grades.
  return num_grades;
}

//Memeber function to calculate the average of the grades
float Gradebook::average() {
  //Declares what avg is set to.
  float avg = 0;
  
  //Calculate sum of grades
  for(unsigned int i=0; i<grades.size(); i++) {
    //avg += grades.at(i);
    
    //Bonus version:
    avg += grades[i];
  }

  //Prevent division by zero.
  if(grades.size() > 0)
    avg = avg/grades.size();   //Compute and return the average
  //returns the average of the grades
  return avg;
}

//Member function to print the grades to the srceen
void Gradebook::print() {
  //print the contents of grades
  for(unsigned int i=0; i<grades.size(); i++) {
    //cout << grades.at(i) << " ";
    
    //Bonus version:
    cout << grades[i] << " ";
  }
}

//Member function that uses selection sort to sort the grades from least to greatest

void Gradebook::sort(){
  //selection sort. 
  for(int i =0; i<(grades.size()-1);i++){
    for(int j=(i+1);j<grades.size();j++){
      if(grades[i]>grades[j]){
	float temp=grades[i];
	grades[i]=grades[j];
	grades[j]=temp;
      }
    }
  }
}

