/* Name: Ricky Hempel
         Tanner Thurman
         Justin Evans
  Date: 11/21/14
  Purpose: Driver function for the BST
  Fil-driver.cpp
*/
#include "bst.h"//for bst class use.
#include <iostream>//STD I/O

using namespace std;
int main(){
  
  //Declares variables for the function.
  binarysearchtree option; 
  string input_file_name;
  string search;
  bool loop_control=false;
  char choice;
  
  //Welcome message for the user.
  cout<<"Welcome your custom binary search tree!\n"
      <<"Please choose one of the following options."<<endl;
  
  do{//Loop menu for the user also prompts the users for options.
    
    cout<<"\nHere are your possibilities: \n "
        <<"A. Read in a BST from a file.\n"
        <<" B. Find the word used the least times in the file.\n"
        <<" C. Print the BST.\n"
        <<" D. Search for how many times a word was used in the file.\n"
        <<" E. Search for the word used the most times in the file.\n"
	<<" F. Delete a word form the BST.\n"
	<<" Q. To Exit the program!\n"
        <<"Enter the letter of your selection: ";
    
    cin>>choice;
    cin.ignore();//Moves buffer for getlines.
    cout<<endl;//Newline for Format 
    choice=toupper(choice);// changes to the upper case.
    
    //If the user doesn't quit or types invalid choice. 
    if(choice=='A'||choice=='B'||choice== 'C'||choice=='D'||choice=='E'|| choice=='F'){
      
      if(choice=='A'){//if user enters A.
	
	cout<<"Please enter a file to read from.\n";
	
	getline(cin,input_file_name);
	
	option.save_file(input_file_name);//stores file in bst.
	
	cout<<"\nIt is done! We hope you enjoy! "<<endl;//Finish message.
	
      }
      
      else if(choice=='B'){//If user types in B.
	
	option.min();//prints out the value in the leftmost subtree.
 	
      }
      
      else if(choice=='C'){//If user types in a C.
	
	option.print();//prints the bst to screen.
	
	cout<<"\nIt is done! We hope you enjoy! "<<endl;//Finish message
	
      }
      
      else if (choice=='D'){//if user enters choice D.
	
	cout<<"Please enter a title to search for:\n";
	
	getline(cin,search);
	
	cout<<"You searched for "<<search<<" which has an value of "<<option.find(search)<<endl;//Prints the word in how many times it appears in the bst.
	
      }
      
      else if(choice=='E'){//If the user enters choice E.
	
	
	option.max();//prints the value in the rightmost subtree
	
      }
      else if (choice=='F'){//If choice is F.
	cout<<"Please enter a word to delete."<<endl;
	cin>>search;
	option.deletedata(search);//Prompts user to delete a word form the bst.	
	
      }
      
    }
    
    else if(choice=='Q'){//If the user enter a Q.
      
      cout<<"\nGoodbye have an blessed day!"<<endl;//Message that exits program.
      
      loop_control=true;//Changes the value of loop control to exit the loop.
    }
    
    else//If the user enters an invalid choice.
      
      cout<<"\nYou entered an invalid selection.\n"
	  <<"You must enter an A,B,C,D,E,F,G or Q. Try again.\n";
    
  }
  
  while(!loop_control);//Loop continues until loop control is true.
  
  
  
  return 0;
}
