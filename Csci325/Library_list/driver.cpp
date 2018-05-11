/*Name-Ricky Hempel
  Justin Evans, Tanner Thurman.
  Date-10/19/14
  File-main.cpp
  Purpose:To prompt the user the 
  choices to edit and their library data base. 
*/

#include <iostream>//STDIN/STDOUT.
#include <string>//String use.
#include "library.h"//Header for the class.

using namespace std;  

//Main function.
int main (){
  
  //Declares variables for the function.
  library option; 
  string input_file_name;
  string output_file_name;
  bool loop_control=false;
  string findvalue;
  char choice;
  
  //Welcome message for the user.
  cout<<"Welcome to your custom BST.\n"
      <<"Please choose one of the following options."<<endl;
  
  do{//Loop menu for the user also prompts the users for options.

    
    cout<<"\nHere are your possibilities: \n "
        <<"A. Read text from a file.\n"
        <<" B. Print the BST.\n"
        <<" C. Search for the  word that has the max value.\n"
        <<" D. Search for the word that has the minimum.\n"
        <<" E. To find how many times a word is the file.\n"
	<<" F. Delete a word from the BST.\n"
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

	option.save_file(input_file_name);
	
	cout<<"\nIt is done! We hope you enjoy! "<<endl;//Finish message.

      }

      else if(choice=='B'){//If user types in B.

	option.print():
 	
	cout<<"\nIt is done! We hope you enjoy! "<<endl;//Finish message.

      }

      else if(choice=='C'){//If user types in a C.
	
	option.max();
	
	cout<<"\nIt is done! We hope you enjoy! "<<endl;//Finish message

      }

      else if (choice=='D'){//if user enters choice D.
	
	option.min();

	cout<<"It is done! We hope you enjoy!"<<endl;//Finish message.
      }

      else if(choice=='E'){//If the user enters choice E.

	cout<<"Please enter an Author to search for.\n";

	getline(cin,Author);

	option.find(Author);

	cout<<"It is done! We hope you enjoy! "<<endl;//Finish message
      }
      else if (choice=='F'){//If choice is F.

	option.add_book();//Prompts user to add a book to the linked list.	
  
      }
      else if(choice=='G'){

	cout<<"Please enter an author and title to delete from the library.\n";

	cout<<"First enter an author's name. "<<endl;
	getline(cin,Author);

	cout<<"Now enter a title name. "<<endl;
	getline(cin,Title);

	option.deletedata(Author);

	cout<<"\nIt is done! We hope you enjoy!"<<endl;
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
  
}//Ends main function.

