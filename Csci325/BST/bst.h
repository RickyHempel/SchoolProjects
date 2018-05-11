/* Name: Ricky Hempel
         Tanner Thurman
         Justin Evans
   Date: 11/20/14
   Purpose:Header information of the binarysearchtree class.
*/ 
#ifndef _bst_h_
#define _bst_h_
#include "node.h"//node header to use nodes.
#include<iostream>//STD I/O
#include <climits>//INT_MAX
 using namespace std;

const int INFINITY=INT_MAX; 
/*
  Creates an global variable that is to highest bounds of int the number will
  change depending on the system you use in on. The reason for the variable is 
  to show if an item is not in an binarysearchtree.
*/


class binarysearchtree{
  Node *root; //Declare a pointer that points to the first item in the tree

  void destructorhelper(Node *current); 
  /*
    Takes in the root of the BST and recursively goings the tree dealloceting 
    memory to avoid memory leaks  .
  */
  void sethelper (Node *current, int value,string key); 
  /*
    Takes in a the the root of the BST an value and a key and recursively goes
    down the tree comparing the data and if keys equal add to the value or 
    goes right if the value is greater or left is less then until a null pointer
    then adds it to the tree.
  */
  int findhelper(string key, Node *current); 
  /*
    Takes in an key and the root then recursively searches the tree looking for 
    the keys to equal if they do return the value of the node else return 
    infinity (see above).

  */
  void printhelper(Node *current); 
  /*
    Declare a function that acts on itself recursively to print out every 
    element in the tree in order
  */
  void maxhelper(Node *current); 
  /*
    Declare a function that acts on itself recursively to print out the max 
    value in the tree
  */
  void minhelper(Node *current); 
  /*
    Declare a function that acts on itself recursively to print out the 
    min value in the tree
  */
  void deletehelper(Node* &current ,string key); 
  /*
    Declare a function that acts on itself recursively to delete nodes in the 
    tree
  */
 public:
  int find (string key); 
  /*
    takes in a string and calls findhelper to find the value of the node
    returns the value if their or infinity(see above)
  */
  binarysearchtree(); 
  /*
    set root to null
  */
  ~binarysearchtree(); 
  /*
    calls destructorhelper to deallocted memory 
  */
  void set(int value,string key); 
  /*
    takes in a value and a key to call sethelper to put in the tree
  */
  void print(); 
  /*
    calls print to print the value of the bst.
  */
  void max(); 
  /*
    calls maxhelper to find the value in the right most subtree.
  */
  void min(); 
  /*
    calls minhelper to find the value in the left most substree.
  */
  void save_file(string file_name); 
  /*
    takes in a file name stores it the bst filtering out whitespace and commas,
    periods, question marks etc etc etc
  */
  void deletedata(string key); 
  /*
    takes in a string and calls delete to delete the first instance of the 
    string in the bst.
   */
};
#endif
