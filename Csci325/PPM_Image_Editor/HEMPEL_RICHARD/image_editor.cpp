/*
  Name:Ricky Hempel
  Date:10/4/14
  File:image_editor.cpp
  Purpose:This file includes the member
  functions of the image editor class
*/

#include <algorithm>//Reverse functions.
#include <iostream>//STDIN/STDOUT
#include <fstream>//File I/O
#include <string>//Use for String
#include <vector>//For vectors
#include "image_editor.h"//Class header file

using namespace std;//Namespace standard

//Function to read numbers from a file and store the numbers 
//into varablies.
void image_editor::read_image(string file_name){
  
  
  ifstream infile;
  int temp;//temp to store values for a short time.
  
  //Opens the file the user types in.
  infile.open(file_name.c_str());
  
  //Reads Image Header	
  infile>>magic_number;
  infile>>width>>height;
  infile>>max_color;
  
  //Priming read to store the color values  
  infile>>temp;
  
  //Loop to store the color values in vectors.
  while (infile){
    //Finish reading first pixel, and stores it in a vector 
    red.push_back(temp);
    infile>>temp;
    green.push_back(temp);
    infile>>temp;
    blue.push_back(temp);
    //Primes for next loop.
    infile>>temp;
  }
  
  infile.close();//Closes the file.
}


//Function to output numbers to a file  
void image_editor::write_image(string file_name){
  
  ofstream outfile;//Declares a variable of ofsteam.
  
  outfile.open(file_name.c_str());//Opens the file that the user inputs.
  
  //Outputs header.
  outfile<<magic_number<<endl;
  outfile<<width<<" "<<height<<endl;
  outfile <<max_color<<endl;

  //loop to out the vector elements to the file with spaces in between them.
  for(int i=0;i<red.size();i++){    
    outfile<<red[i]<<" "<<green[i]<<" "<<blue[i]<<" ";
  }
    
  outfile.close();//Closes the file.
}
 
//Function to find the average of the three values 
//and set the elements equal to the average to greyscale the image.

void image_editor::grey_scale(){
  int avg;
  
  //Loop to find the average of the elements then set the elements 
  //to the average.
  for(int i=0;i<red.size();i++){
    avg=(red[i]+green[i]+blue[i])/3;
    red[i]=avg;
    green[i]=avg;
    blue[i]=avg;
  }
}

//Function to reverse the vectors to "flip the image".
void image_editor::flip_image(){
  
  reverse(red.begin(),red.end());//reverses the red vector.
  reverse(blue.begin(),blue.end());//reverses the blue vector.
  reverse(green.begin(),green.end());//revereses the green vector.
}

//Function to set the elements of blue and green to zero to make 
//the image redscale.
void image_editor::red_only(){

  //Loop to set the elements of blue and green to zero.
  
  for(int i=0;i<green.size();i++){
    blue[i]=0;
    green[i]=0;
  }
}

//Function to set the elements of red and green to zero to make 
//the image bluescale.

void image_editor::blue_only(){
  
  //Loop to set the elements of red and green to zero.
  for(int i=0;i<blue.size();i++){
    red[i]=0;
    green[i]=0;
  }
}

//Function to set the elements of red and blue to zero to make 
//the image greenscale.

void image_editor::green_only(){

  //Loop to set the elements of red and blue to zero.
  for(int i=0;i<green.size();i++){
    blue[i]=0;
    red[i]=0;
  }
}
