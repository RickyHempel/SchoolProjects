/*
  Name-Ricky Hempel
  Date-10/04/14
  File-main.cpp
  Purpose:To prompt the user the 
  choices to edit and .ppm image 
*/

#include <iostream>//STDIN/STDOUT.
#include <string>//String use.
#include "image_editor.h"//Header for the class.

using namespace std;//Standard namespace.  

//Main function.
int main (){
  //Declares variables for the function.
  image_editor option; 
  string input_file_name;
  string output_file_name;
  bool loop_control=false;
  char choice;

  //Welcome message for the user.
  cout<<"Welcome to the .PPM editor 100!\n"
      <<"Please choose how you would like the edit your image!"<<endl;
  
  do{//Loop menu for the user also prompts the users for options.
    
    cout<<"\nHere are your editing possibilities: \n "
        <<"A. To convert an image to a greyscale image.\n"
        <<" B. To flip an image.\n"
        <<" C. To convert an image to an redscale image.\n"
        <<" D. To convert an image to an greenscale image.\n"
        <<" E. To convert an image to an bluescale image.\n"
        <<" Q. To exit.\n"
        <<"Enter the letter of your selection: ";
    
    cin>>choice;//User enters choice.
    
    cin.get();//To move buffer for getline.
    
    choice=toupper(choice);// changes to the upper case.
    
    //If the user doesn't quit or types invalid choice. 
    if(choice=='A'||choice=='B'||choice== 'C'||choice=='D'||choice=='E'){ 
      
      cout<<"Please enter a file to read from:\n";//user enters file.
      
      getline(cin,input_file_name);//Use getline so user can enter file.
      
      option.read_image(input_file_name);//Calls function read the image.
      
      cout<<"Please enter a file to write to "<<endl;//users enters filename.
      
      getline (cin,output_file_name);//Use to getline.
      
      if(choice=='A'){//if user enters A. 
	option.grey_scale();//calls greyscale function.
	
	
	option.write_image(output_file_name);//function to output to a file.

	cout<<"It is done! We hope you enjoy! "<<endl;//Finish message.

      }

      else if(choice=='B'){//If user types in B.
	
	option.flip_image();//Calls the flip image function.
	
	option.write_image(output_file_name);//outputs numbers to a file
	
	cout<<"It is done! We hope you enjoy! "<<endl;//Finish message.
      }

      else if(choice=='C'){//If user types in a C.
	option.red_only();//Calls the red only function.
	
	option.write_image(output_file_name);//outputs numbers to a file.
	
	cout<<"It is done! We hope you enjoy! "<<endl;//Finish message
      }

      else if (choice=='D'){//if user enters choice D.
	
	option.green_only();//Calls the green only.
	
	option.write_image(output_file_name);//outputs numbers to a file

	cout<<"It is done! We hope you enjoy! "<<endl;//Finish message.
      }

      else if(choice=='E'){//If the user enters choice E.

	option.blue_only();//Calls the blue only function.
	
	option.write_image(output_file_name);//outputs numbers to a file

	cout<<"It is done! We hope you enjoy! "<<endl;//Finish message
      }
    }
    else if(choice=='Q'){//If the user enter a Q.
      
      cout<<"\nGoodbye have an blessed day!"<<endl;//Message that exits program.
      
      loop_control=true;//Changes the value of loop control to exit the loop.
    }
    
    else//If the user enters an invalid choice.
      
      cout<<"\nYou entered an invalid selection.\n"
	  <<"You must enter an A,B,C,D,E, or Q. Try again.\n";
    
  }

  while(!loop_control);//Loop continues until loop control is true.
  
  return 0;
  
}//Ends main function.

