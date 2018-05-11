/*
  Name-Ricky Hempel,
  Justin Evans,Tanner Thurman.
  Date-10/19/14
  File-library.cpp
  Purpose- Implementation for the link list of library
*/

#include "library.h"//Library class.
#include "book.h"//Book node.
#include <string>//String class
#include <fstream>//File input/output
#include <iostream>//STDIN/STDOUT

using namespace std;

library::library(){
  //creates a empty list. 
  head=NULL;
}

library::~library(){
  book *temp; 
  if(head==NULL){
    delete head;//Deletes the head of the list.
  }

  //Deletes all nodes of the list.
  while(head!=NULL){
    temp=head;
    head=head->next;
    delete temp;
  }
}


void library::insert_sorted( book node){
  //Creates a node to insert.
  book *insert=new book;

  //Pointers to search the list.
  book *temp,*temp2;
  
  //Copies the data from what is being passed  to insert.
  insert->Title=node.Title;
  insert->Author=node.Author;
  insert->Copyright_Year=node.Copyright_Year;
  insert->Edition=node.Edition;
  insert->Number_of_Pages=node.Number_of_Pages;
  insert->next=NULL;

  temp=head;//Set temp to head to compare the strings.
 
  //Adds one node to the front of the list.
  if(head==NULL){
    head=insert;
  }
  
  //Compares the titles and sorts them alphabetically.
  
  //Compares the titles and pushes front if necessary.
  else if(insert->Title < head->Title){
    insert->next=head;
    head=insert;
  }
  
  //Compares the titles and adds to back if necessary.
  else if (insert->Title > head->next->Title){

    //Looks for the last node.
    while(temp->next!=NULL)
      temp=temp->next;

    //Adds to the end.
    temp->next=insert;
  }
  
  //Compares titles and inserts the nodes in the middle if necessary.
  else {

    temp=head;
    //Looks for the node to insert.
    while(temp->next!=NULL && temp->next->Title > insert->Title && temp->next->Title < insert->Title){
      temp=temp->next;
    }

    //If the node is found inserts it.
    if(temp->next!=NULL){

      temp2=temp->next;
      temp->next=insert;
      insert->next=temp2;

    }
  }
}

void library::find_title(string Title){

  book *printer;//Creates pointer to search the list.

  printer=head;

  int counter=0;//Counter to see if the title is the list.
  
  //Message for the user.
  cout<<"\nAll the books that start with the title "
      <<Title<<" are as followed: \n"<<endl;

  //Searches for the title.
  while(printer!=NULL){ 

    if (!printer->Title.find(Title)){
      //prints the information of all book's by the given author 
      cout<<"The title of the book is "<<printer->Title<<"."<<endl 
	  <<"The author of the book is "<<printer->Author<<"."<<endl
	  <<"The copyright year of the book is "<<printer->Copyright_Year
	  <<"."<<endl
	  <<"The book's edition is " <<printer->Edition<<" edition."<<endl
	  <<"The number of pages the book has is "
	  <<printer->Number_of_Pages<<" pages."<<endl<<endl;
      counter++;//Adds to the counter if title is found.
    }  
    printer=printer->next;//Moves pointer.
  }

  //If no titles exist. 
  if(counter==0){
    cout<<"Sorry there are no matching results for  the title: "
	<<Title<<"."<<endl<<endl;
  }
}

void library::find_author(string Author){

  book *printer;//Creates pointer to print to user.
  printer=head;

  int counter=0;//Counter to see if the author is the list.

  //Message for the user.
  cout<<"\nThe Author you search for was "<<Author
      <<" and the results are:\n "<<endl;
  
  //Searches for the author in the list. 
  while(printer!= NULL){

    //prints the information of all book's by the given author 
    if(printer->Author==Author){
      cout<<"The title of the book is "<<printer->Title<<"."<<endl 
	  <<"The author of the book is "<<printer->Author<<"."<<endl
	  <<"The copyright year of the book is "<<printer->Copyright_Year
	  <<"."<<endl
	  <<"The book's edition is " <<printer->Edition<<" edition."<<endl
	  <<"The number of pages the book has is "
	  <<printer->Number_of_Pages<<" pages."<<endl<<endl;
      counter++;//Adds to the counter if title is found.
    }  
    printer=printer->next;//Moves pointer.
  }

  //If the author is not in the database.
  if(counter==0){
    cout<<"Sorry we could not find any results for the author: "<<Author
	<<"."<<endl<<endl;
  } 
}

void library::print_database(){

  book *printer;//Creates pointer to print to user.
  printer=head;

  cout<<endl;//outputs a newline for format to screen.

  //prints the information of all books in the list.
  while(printer!=NULL){
    cout<<"The title of the book is "<<printer->Title<<"."<<endl
	<<"The author of the book is "<<printer->Author<<"."<<endl
	<<"The copyright year of the book is "<<printer->Copyright_Year
	<<"."<<endl
	<<"The book's edition is " <<printer->Edition<<" edition."<<endl
	<<"The number of pages the book has is "<<printer->Number_of_Pages
	<<" pages."<<endl<<endl;
    printer=printer->next;//Moves pointer.
  }
}

void library::read_from_file(string file_name){
  book temp;
  ifstream infile;
  infile.open (file_name.c_str());
  
  //Priming  read to get the title
  getline(infile,temp.Title);

  //Loop to get the books information form file and add to link list.
  while(infile){
    getline(infile,temp.Author);
    infile>>temp.Copyright_Year;
    infile>>temp.Edition;
    infile>>temp.Number_of_Pages;
    infile.ignore();
    insert_sorted(temp);
    getline(infile,temp.Title);
  }

  infile.close();
}

void library::write_to_file(string file_name){
  ofstream outfile;

  book *printer;//Makes a pointer to print to the file.
  printer=head;

  outfile.open(file_name.c_str());

  //Prints a header to the file.
  outfile<<"The books of the library are as followed:\n"<<endl;
  //Prints all the book's information to a file.
  while(printer!=NULL){
    outfile<<"The title of the book is "<<printer->Title<<"."<<endl
	   <<"The author of the book is "<<printer->Author<<"."<<endl
	   <<"The copyright year of the book is "<<printer->Copyright_Year
	   <<"."<<endl
	   <<"The book's edition is " <<printer->Edition<<" edition."<<endl
	   <<"The number of pages the book has is "
	   <<printer->Number_of_Pages<<" pages."<<endl<<endl;
    printer=printer->next;
  }
  outfile.close();
}

void library::add_book(){
  book temp;

  //Prompts the user for information then adds it to the link list.
  cout<<"What is the book's title?"<<endl;
  getline(cin,temp.Title);

  cout<<"What is the book's author's name?"<<endl;
  getline(cin,temp.Author);

  cout<<"What is the copyright year of the book?"<<endl;
  cin>>temp.Copyright_Year;

  cout<<"What is the book's edition ?"<<endl;
  cin>>temp.Edition;

  cout<<"How many pages does the book have?"<<endl;
  cin>>temp.Number_of_Pages;

  cin.ignore();//Moves buffer.

  insert_sorted(temp);//Adds book to the list.

  cout<<"\nIt is done we hope you enjoy!"<<endl;

}

void library::delete_book(string Author,string Title){
  book *temp, *eraser;//Two pointers to delete node in the list.

  //If list if empty.
  if(head==NULL)
    return;
  //If list has one item.

  else if (head->Author==Author && head->Title==Title){
    eraser=head;
    head=head->next;
    delete eraser;
  }

  //List has many items.
  else{
    temp=head;

    //Searches for node to delete
    while(temp->next!=NULL && temp->next->Author!=Author && temp->next->Title!=Title){
      temp=temp->next;
    }

    //If node is found.
    if(temp->next!=NULL){
      eraser=temp->next;
      temp->next=eraser->next;
      delete eraser;
    }
  }
}

