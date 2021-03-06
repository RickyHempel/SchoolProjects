/******************
Name: Ricky Hempel
      Tanner Thurman
      Justin Evans
Date:9/19/14
File:Float_vector.h
Purpose: This file has the class definition for the float_vector class

********************/
//Microguards
#ifndef _float_vector_h
#define _float_vector_h

//start of class defition.
class float_vector{
 private:

  float *vec_ptr; //Points to the vector's dynamic array
  int current_size, capacity; //Same as size and capacity for std::vector


 public:

  float_vector(void);
  /*
    Creates an empty vector (vec_ptr = NULL) with:
    size = 0;
    capacity = 0;
  */

  ~float_vector(void);
  /*
    Destructor.  Deletes the array to which vec_ptr points.
  */

  int size(void);
  /*
    Returns the current number of elements in the vector (size).
  */


  float at(int pos);
  /*
    Same as std::vector.at(int pos) or std::vector.operator[], returns the element at position pos.
  */


  void push_back(float element);
  /*
    Same as std::vector.push_back(float value), stores value at the end of the vector.
	
    Note: If the current size exceeds the vector's capacity (or the vector is empty), a resize()
    is triggered before the push.
  */
  
  
  void resize(void);
  /*
    Can be called manually, but is triggered by push.  Resize doubles the current array size.
    
    Note: If the array is currently of size zero, initialize first to size 1.
  */

  //overloads the [] operator to retrieve elements only take in an index to return the element
  const float& operator[](unsigned int index) const;

  //overloads the [] operator to store elements only and it takes in an index and returns the element
  float& operator[](unsigned int index);


};
//end of class and endif microgaurd.
#endif
