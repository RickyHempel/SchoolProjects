/* Name:    Ricky Hempel
            Tanner Thurman
            Justin Evans
   Date:    11/21/14
   Purpose: Implementation of the node class
   File-Node.cpp
*/
#include <iostream>
#include <string>//string use.
#include "node.h"//node header
using namespace std;

//Declare node constructor
Node::Node(int value, string newkey){
  left=NULL;  //Set the left pointer to NULL
  right=NULL; //Set the right pointer to NULL
  data=value; //Set data to equal value
  key=newkey; //Set key equal to newkey
}
 
