/*
  Name-Ricky Hempel
  Date-12/5/14
  File-heap.h
  Purpose-Header file for the heap class
*/
#ifndef _heap_h_
#define _heap_h_
#include <iostream>//STD I/O
#include <vector>//STD Vector use
 using namespace std;

class Heap{
  
  vector<int>buffer;//vector of ints to store the values for the hep.
 public:
  Heap();
  /*
    Creates an empty heap by asking the system to reserve a vector of size 4 
    Also the Constructor for the heap class 
    
    
  */
  int size();
  /*
    Function to return the size of the heap (vector).
    Returns an int which is the size.
    Takes in nothing.
    
    
  */
  
  void insert(int value);
  /*
    Function that if empty adds an zero to the front so the root starts at 
    buffer[1] then pushes the value back lastly reorders the heap
    Takes in a int which is the value to be stored.
    Returns nothing.
    
    
  */
  void remove_max();
  /*
    Removes the max number which is the top of the heap by switching the top
    value with the bottom value, poping off the end then reordering the heap
    Takes in nothing 
    Returns nothing
    
    
    
  */
  int max();
  /*
    Function to return the top of the heap(vector) which is the highest
    number best on the order property.
    Takes in nothing.
    Returns an int which is the max number of the heap.
    
    
  */
  void print();
  /*
    Function to print the data in the heap.
    Takes in nothing.
    Returns nothing.    
  */
};
#endif
