/***************************************************
Name-Ricky Hempel
Date-9/9/14
File : Corrections.cpp 
Purpose of Program-To make up any lost credit
on  the entrance quiz on problems 1-3 and to show understanding of 
arrys and declaring memory dynamically.  
***************************************************/

#include <iostream> //STDIN,STDOUT.
using namespace std;

//Constant to know at compile time and to be used for arry size,functions and loops.
const int ARRY_SIZE=5;

//Function prototype of functions that print the values of the arrys to the screen. 
void print_arry(int n,int arry[]);
void print_arry2(int m, int int_arry[]);

//main function.
int main(){
 
  //Problem 1a & 2a Statically declares an arry of ARRY_SIZE ints. 
  int int_arry[ARRY_SIZE];

  //Problem 2b.declares an arry of ARRY_SIZE ints dynamically.
  int *arry=new int[ARRY_SIZE];

  //For loop to populate the dynamically and statically  declared arry.
  for(int i =0;i<ARRY_SIZE;i++){
    arry[i]=i;
    int_arry[i]=i;
  } 
 
  //Problem 1b $ 2b.. Function call that takes an number and an arry  to print arry values to screen.
  print_arry(ARRY_SIZE,arry);
  print_arry2(ARRY_SIZE,int_arry);

  //Problem 3. Deallocates (I thinks deallcate is spell right I checked it but emacs says it is wrong) memory of arry using delete.
  delete[]  arry;

  //Returns  a zero.
  return 0;
}

//Problem 2c.Function that returns nothing but prints the values of the dynamically declared arry to the screen.
void print_arry(int n, int arry[]){
  for (int i=0;i<n;i++)
  cout<<arry[i]<<endl;
  cout<<endl;
  //Learn in CS222 by Mr.Coalter to put return to show you are done with that function.
  return;
}
 
//Problem 1c.Function that returns nothing but prints the values of the statically declared arry to the screen.
void print_arry2(int m,int int_arry[]){
  for(int j=0;j<m;j++)
    cout<<int_arry[j]<<endl;
  //return to show I done with the function.
  return;
}
