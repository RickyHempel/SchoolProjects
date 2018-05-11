/*
  Name-Ricky Hempel
  Date-12/5/14
  File-Heap.cpp
  Purpose-Implementation of the heap class.
*/
#include "heap.h"//Heap class
#include <vector>//STD Vector
#include <cmath>//Floor
using namespace std;

Heap::Heap(){
  //creates  an empty heap my reserve a vector of 4 
  buffer.reserve(4);
}
int Heap::size(){
  /*returns the size of the heap (vector).
    it is minus on because the root of the heap is at buffer[1] not buffer[0]
  */
  return buffer.size()-1;
  
}
void Heap::insert(int value){
  /*If buffer is empty adds in zero to the buffer then adds the
    the root to the buffer[1] to start the heap
  */
  if(buffer.empty()){
    buffer.push_back(0);
    buffer.push_back(value);
  }
  //else push back the value then go in reorder the heap,
  else{
    buffer.push_back(value);
    for( unsigned int k=2; k<buffer.size(); k++){
      if(buffer[floor (k/2)]<buffer[k]){
	int temp=buffer[floor (k/2)];
	buffer[floor(k/2)]=buffer[k];
	buffer[k]=temp;
      }
    }
  }
}


void Heap::remove_max(){
  //if the buffer reaches buffer[0] tell user it is empty
  if(buffer.size()==1){
    cout<<"Error heap is empty can not remove anything"<<endl;
  }
  else{
    //swap top and bottom of the heap
    int temp=buffer[1];
    buffer[1]=buffer.back();
    buffer.back()=temp;

    buffer.pop_back();//delete last element which is the max.

    //Then reorder the heap
    for(int i =2; i<=size();i++){
      for(int j=(i-1);j<size();j++){
	if(buffer[i]<buffer[j]){
	  int temp=buffer[i];
	  buffer[i]=buffer[j];
	  buffer[j]=temp;
	}
      }
    }
  }
}

int Heap::max(){
  /*returns the first element in the heap which according to the
    order property should be the root or first element.
  */
  return buffer[1];
}


void Heap::print(){
  //Prints the data of the heap to the user starting at the root.
  for(unsigned int i=1; i<buffer.size();i++){
    cout<<buffer[i]<<endl;
  }
  //if buffer has only the buffer[0] element left tell user buffer is empty.
  if(buffer.size()==1){
    cout<<"The heap is empty"<<endl;
  }
}
