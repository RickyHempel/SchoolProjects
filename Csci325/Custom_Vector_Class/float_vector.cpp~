/*****************
Name: Ricky Hempel
      Tanner Thurman
      Justin Evans
File:float_vector.cpp
Date:9/19/14
Purpose:This file has the member functions for the float vector class.

********************/
#include <iostream>//input/output
#include "float_vector.h"//header file for the float_vector class
using namespace std;//standard namespace

//Destructor that deletes the arry to which vec_ptr points.
float_vector::~float_vector(void){
  delete [] vec_ptr;
}

//Constructor that creates and empty vector and sets size and capacity to zero.
float_vector::float_vector(){
  current_size=0;
  capacity=0;
  vec_ptr=NULL;
}

//Member function that returns the current number of elements in the vector.
int float_vector:: size(){
  
  return current_size;
  
}

//Member function that returns the element at posititon pos.
float float_vector:: at(int pos){
  return vec_ptr[pos];
}

//Member function that doubles the current array size and if the array is of size zero, initialize first size to 1
void float_vector::resize(){
  //if vec_ptr is null intialize the first size to 1 then increase capacity plus one
  if(vec_ptr==NULL){
    vec_ptr= new float[1];
    capacity++;
  }
   //else statement to make a temp array then copy elements from the vec_ptr to temp and make temp and vec_ptr equal
   //then increases capacity itself times two
  else{
    float *temp;
    temp=new float[capacity*2];  
    for(int i=0;i<current_size;i++)
      temp[i]=vec_ptr[i];
    delete[]vec_ptr;
    vec_ptr=temp;
    capacity=capacity*2;
  }
  
}

//Member function that stores values at the end of the vector,but if the current size exceeds the vector's capacity a resize() is triggered before the push
void float_vector::push_back(float element){
  //if current is equal to capacity or current_size is equal to 0 call the resize function.
  if(current_size== capacity || current_size==0){  
    resize();
  }
//stores the element at the end of the array then increases size by 1
  vec_ptr[current_size]=element;
  current_size++;
  
}

//Function that overloads the operator [] to give the vector more array like functionality; this function is used to retrieve elements only
const float& float_vector::operator[](unsigned int index) const {
  
  return vec_ptr[index];
  
}

//Function that overloads the [] operator; this function is for storing elements 
float& float_vector::operator [](unsigned int index){

  return vec_ptr[index];
  
}
