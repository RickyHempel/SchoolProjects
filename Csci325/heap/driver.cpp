/* Name: Ricky Hempel
   Date: 12/05/14
   Purpose: Driver function for the Heap
   File-driver.cpp
*/
#include "heap.h"//for bst class use.
#include <iostream>//STD I/O
#include <fstream>//File I/O

using namespace std;
int main(){
  
  //Declares variables for the function.
  Heap option; 
  string input_file_name;
  bool loop_control=false;
  char choice;
  fstream infile;
  
  //Welcome message for the user.
  cout<<"Welcome your custom heap!\n"
      <<"Please choose one of the following options."<<endl;
  
  do{//Loop menu for the user also prompts the users for options.
    
    cout<<"\nHere are your possibilities: \n "
        <<"A. Read in a heap from a file.\n"
        <<" B. See what is the max number in the heap.\n"
        <<" C. Print the heap.\n"
        <<" D. Remove the max number in a heap.\n"
        <<" E. See the size of the heap.\n"
	<<" Q. To Exit the program!\n"
        <<"Enter the letter of your selection: ";
    
    cin>>choice;
    cin.ignore();//Moves buffer for getlines.
    cout<<endl;//Newline for Format 
    choice=toupper(choice);// changes to the upper case.
    
    //If the user doesn't quit or types invalid choice. 
    if(choice=='A'||choice=='B'||choice== 'C'||choice=='D'||choice=='E'){
      
      if(choice=='A'){//if user enters A.
	
	cout<<"Please enter a file to read from.\n";
	
	getline(cin,input_file_name);//Gets file name
	
	infile.open(input_file_name.c_str());
	//Stores the file in the heap.
	int temp;
	infile>>temp;
	while(infile){
	  option.insert(temp);
	  infile>>temp;
	}
	infile.close();
	
	cout<<"\nIt is done! We hope you enjoy! "<<endl;//Finish message.
	
      }
      
      else if(choice=='B'){//If user types in B.
	
	cout<<"The max number in the heap is "<<option.max()<<endl;
      }
      
      else if(choice=='C'){//If user types in a C.
	
	option.print();//prints the bst to screen.
	
	cout<<"\nIt is done! We hope you enjoy! "<<endl;//Finish message
	
      }
      
      else if (choice=='D'){//if user enters choice D.
	
	option.remove_max();
	cout<<"\nIt is done! We hope you enjoy! "<<endl;//Finish message
	
	
      }
      
      else if(choice=='E'){//If the user enters choice E.
	
	
	cout<<"The size of the heap is "<<option.size()<<endl;
	
      }
      
    }
    
    else if(choice=='Q'){//If the user enter a Q.
      
      cout<<"\nGoodbye have an blessed day!"<<endl;//Message that exits program.
      
      loop_control=true;//Changes the value of loop control to exit the loop.
    }
    
    else//If the user enters an invalid choice.
      
      cout<<"\nYou entered an invalid selection.\n"
	  <<"You must enter an A,B,C,D,E,or Q. Try again.\n";
    
  }
  
  while(!loop_control);//Loop continues until loop control is true.
  
  
  
  return 0;
}
