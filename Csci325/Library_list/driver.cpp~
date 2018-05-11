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
  string Title;
  string Author;
  char choice;
  
  //Welcome message for the user.
  cout<<"Welcome to the Library.\n"
      <<"Please choose one of the following options."<<endl;
  
  do{//Loop menu for the user also prompts the users for options.
    
    cout<<"\nHere are your possibilities: \n "
        <<"A. Read in a library from a file.\n"
        <<" B. Write the library to a file.\n"
        <<" C. Print the library.\n"
        <<" D. Search for a book by title.\n"
        <<" E. Search for a book by a author.\n"
        <<" F. Add a book to the library.\n"
	<<" G. Delete a book from the library.\n"
	<<" Q. To Exit the program!\n"
        <<"Enter the letter of your selection: ";
    
    cin>>choice;
    cin.ignore();//Moves buffer for getlines.
    cout<<endl;//Newline for Format 
    choice=toupper(choice);// changes to the upper case.
    
    //If the user doesn't quit or types invalid choice. 
    if(choice=='A'||choice=='B'||choice== 'C'||choice=='D'||choice=='E'|| choice=='F' || choice=='G'){
      
      if(choice=='A'){//if user enters A.
 
	cout<<"Please enter a file to read from.\n";

	getline(cin,input_file_name);

	option.read_from_file(input_file_name);
	
	cout<<"\nIt is done! We hope you enjoy! "<<endl;//Finish message.

      }

      else if(choice=='B'){//If user types in B.

	cout<<"Please enter a file to write to.\n";

	getline(cin,output_file_name);
	
	option.write_to_file(output_file_name);
 	
	cout<<"\nIt is done! We hope you enjoy! "<<endl;//Finish message.

      }

      else if(choice=='C'){//If user types in a C.
	
	option.print_database();
	
	cout<<"\nIt is done! We hope you enjoy! "<<endl;//Finish message

      }

      else if (choice=='D'){//if user enters choice D.
	
	cout<<"Please enter a title to search for:\n";
	
	getline(cin,Title);
	
	option.find_title(Title);

	cout<<"It is done! We hope you enjoy!"<<endl;//Finish message.
      }

      else if(choice=='E'){//If the user enters choice E.

	cout<<"Please enter an Author to search for.\n";

	getline(cin,Author);
  
	option.find_author(Author);

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

	option.delete_book(Author,Title);

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

