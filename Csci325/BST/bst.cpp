/*
  Name-Ricky Hempel
       Tanner Thruman
       Justin Evans
   Date-11/21/14
   File-bst.cpp
   Purpose-Implementation of the bst class
*/
#include "node.h"//node use
#include "bst.h"//bst header
#include <string>//string
#include <iostream>//STD I/O
#include <fstream>//File I/O


using namespace std;

binarysearchtree::binarysearchtree(){
  //creates an empty bst.
  root=NULL;
}
binarysearchtree::~binarysearchtree(){
  //uses destructorhelper to destroy the bst when done. 
  destructorhelper(root);
}
void binarysearchtree::destructorhelper(Node *current){
  if(current!=NULL){
    destructorhelper(current->left);//Go left
    destructorhelper(current->right);//Go right
    delete current;//delete the node to stop memory leaks
  }
}
void binarysearchtree::set(int value,string key){
  if(root==NULL){
    root=new Node(value,key);//adds one item to the bst.
  }
  else{
sethelper(root,value,key);//calls the helper to add more then one item.
  }
}

void binarysearchtree::sethelper(Node *current, int value,string key) {
  if(current->key==key){
    //if the key already exist add one to the value and do not add to the bst. 
    current->data++;
    return;
  } 
  //go left
  if(value<current->data ){
    if(current->left==NULL){
      current->left= new Node (value,key);//adds node to the left subtree.
    }
    
    else 
      sethelper(current->left,value,key);//look for a node whose left is null
  }
  else {
    if(current->right==NULL)
      current->right= new Node (value, key);//adds to the right subtree of bst.
    else{ 
      sethelper(current->right,value,key);//look for a node whose right is null.
    }
  }
}
void binarysearchtree::save_file(string file_name){
  ifstream infile;//file input
  string temp;//stores words
  int data=1;//sets the value to 1 in the bst.
  infile.open(file_name.c_str());
  
  infile>>temp;//priming read.
  
  //filters out commas end marks etc.etc.
  for(unsigned int i=0; i<temp.length();i++){
    if(!isalpha(temp[i])){
      temp.erase(i);
    }
  }
  //loop to read from file.
  while(infile){
    set(data,temp);//stores the data in the bst.
    infile>>temp;
    //same is above loop.
    for(unsigned int i=0; i<temp.length();i++){
      if(!isalpha(temp[i])){
	temp.erase(i);
      }
    }
    
  }
  infile.close();
  
  
}
void binarysearchtree::print(){
  printhelper(root);//calls the helper to print to the screen 
  cout<<endl;//Formatting 
  
}
void binarysearchtree::printhelper(Node *current){
  if(current != NULL){
    printhelper(current->left);//go left subtree
    cout<<"The key of "<<current->key<<" "<<"has the data of " <<current->data<<" "<<endl;//prints the node to the screen
    printhelper(current->right);//go to right subtree
  }
}
void binarysearchtree::deletedata(string key){
  deletehelper(root,key);//calls the helper function 
  
}
void binarysearchtree::deletehelper(Node* &current,string key){
  //Node doesn't exist
  if(current==NULL){
    return;
  }
  //go left
  if(key <current->key){
    deletehelper(current->left,key);
  }
  //go right
  if (key > current->key){
    deletehelper(current->right,key);
  }
  //found!
  else if (current->key==key){
    //left node
    if(current->left==NULL && current->right==NULL){
      Node*temp=current;//go to that node
      current=NULL;//parent to null
      delete temp;//delete the value
     
    }
    //no left subtree
    else if (current->left==NULL && current->right!=NULL){
      Node*temp=current;//go to that node
      current =current->right;//parent points to right subtree 
      delete temp;//delete the node we are on
      
    }
    
    else  if(current->left!=NULL && current->right == NULL){
      Node*temp=current;//go to that node
      current=current->left;//parent points to left  subtree 
      delete temp;//delete the node we are on
      
    }
    
    else{
      Node*temp=current;//go to that node
      // Find node with the greatest key in left subtree
      if(temp->left!=NULL){
 	while(temp->right!=NULL){
 	  temp=temp->right;	  
 	}
	//Copy greatest key to the delete node's data
   	string temp2=temp->key;
 	current->key=temp->key;
 	current->key=temp2;
	

 	delete temp;//Delete the leaf with the greatest key in left subtree

      }
      
    }
    
  }
}
void binarysearchtree::max(){
  maxhelper(root);//calls the helper function to find the largest node in bst. 
}
void binarysearchtree::maxhelper(Node *current){
  if(current ->right!= NULL){     
    //go right until null
    current= current-> right;
    maxhelper(current);
  }
  else
    cout<<"The word in the right most subtree is "<<current->key<<" with has a value of "<<current->data<<endl; //prints the value to the screen
 }

void binarysearchtree::min(){
  minhelper(root);//calls the helper function to find the smallest node in bst.
}
void binarysearchtree::minhelper(Node *current){
  if(current -> left != NULL){
    current= current-> left;
    minhelper(current);
  }
  else
    cout<<"The word in the leftmost subtree is "<<current->key<<" which has the value of "<<current->data<<"."<<endl;//prints the value to the screen. 
}
int binarysearchtree::find(string key){
  
  return findhelper(key,root);//returns the value the helper function finds. 
}
int binarysearchtree::findhelper(string key,Node *current){
  if(current!=NULL){
    
    if(key < current-> key){
      return findhelper(key,current->left);//go left
    }
    else if(key > current-> key){
      return findhelper(key,current->right);//go right
    }
    else if(current->key==key){
      return current->data;// returns the value of the key if found.
    }
  } /*
      returns the max value an int can be which is different values on 
      different computers so if you a big number that means current is null;
     */
    return INFINITY;
}
