/* Name: Ricky Hempel
         Tanner Thurman
         Justin Evans
   Date: 11/21/14
   Purpose: Header for the Node class.
   File-Node.h
*/

#ifndef _node_h_
#define _node_h_
#include <iostream>
#include <string>//string use.
using namespace std;
class Node{
 public:
  Node *left, *right; //Declares pointers that point to the left and right in the tree.
  string key; //Declares a key that will be used to compare and order the Tree
  int data; //Declares a counter for how many times a word appears in the Tree
  Node(int data,string key); 
  /*
    Function takes in an int and an string then sets the data and key to what is    passed into the function then sets left and right pointers to null.
  */
  
};
#endif
