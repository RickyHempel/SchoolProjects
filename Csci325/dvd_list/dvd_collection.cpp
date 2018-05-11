/*
  Name-Ricky Hempel,
  Date-11/7/14
  File-dvd_collection.cpp
  Purpose- Implementation for the link list of dvds
*/

#include "dvd_collection.h"//dvd_collection class.
#include "dvd.h"//dvd node.
#include <string>//String class
#include <list>//Linked List
#include <fstream>//File input/output
#include <iostream>//STDIN/STDOUT

using namespace std;

void dvd_collection::insert_sorted(dvd node){

  //If the list is empty adds a node to the list
  if(dvds.empty()){
    dvds.push_back(node);
  }

  //If list has one item inserts to the top or bottom.
  else if (dvds.size()==1){
    for(list<dvd>::iterator it =dvds.begin(); it!=dvds.end(); it++){

      //If greater adds to bottom.
      if(it->Title < node.Title){
	dvds.push_back(node);
	return;
      }
      else{
	//Adds to top.
	dvds.push_front(node);
      }
    }
  }

  else{//List has many items

    for(list<dvd>::iterator it=dvds.begin();it!=dvds.end();it++){

      //Compares titles
      if(it->Title < node.Title){
	//Finds position to insert
	while(it->Title < node.Title && it!=dvds.end()){
	  it++;
	}
	dvds.insert(it,node);
	return;
      }
      //else just insert
      else if (it->Title > node.Title){
	dvds.insert(it,node);
	return;
      }
    }
  }

}
void dvd_collection::find_title(string Title){
  
  int counter=0;//Counter to see if the title is the list.
  
   //Message for the user.
  cout<<"\nAll the dvds that start with the title "
      <<Title<<" are as followed: \n"<<endl;
  
   //Searches for the title.
  
  for(list<dvd>::iterator it=dvds.begin();it!=dvds.end(); it++){
    if (!it->Title.find(Title)){
      //prints the information of all dvd's by the given author 
      cout<<"The title of the dvd is "<<it->Title<<"."<<endl 
   	  <<"The director of the dvd is "<<it->Director<<"."<<endl
   	  <<"The release year of the dvd is "<<it->Release_Year
   	  <<"."<<endl
   	  <<"The dvd's rating is " <<it->Rating<<"."<<endl
   	  <<"The runtime of the dvd is "
   	  <<it->Runtime<<" minutes."<<endl<<endl;
      counter++;//Adds to the counter if title is found.
    }  
    
  }
  
   //If no titles exist. 
  if(counter==0){
    cout<<"Sorry there are no matching results for the title: "
   	<<Title<<"."<<endl<<endl;
  }
}


void dvd_collection::find_director(string Director){
  
  int counter=0;//Counter to see if the author is the list.
  
  //Message for the user.
  cout<<"\nThe director you search for was "<<Director
      <<" and the results are:\n "<<endl;
  
  //Searches for the author in the list. 
  for(list<dvd>::iterator it=dvds.begin();it!=dvds.end(); it++){
    
      //prints the information of all dvd's by the given author 
    if(it->Director==Director){
      cout<<"The title of the dvd is "<<it->Title<<"."<<endl 
 	  <<"The director of the dvd is "<<it->Director<<"."<<endl
  	  <<"The release year of the dvd is "<<it->Release_Year
   	  <<"."<<endl
   	  <<"The dvd's rating is " <<it->Rating<<"."<<endl
  	  <<"The runtime of the dvd is "
   	  <<it->Runtime<<" minutes."<<endl<<endl;
      counter++;//Adds to the counter if title is found.
    }  
  }

 //If the director is not in the database.
  if(counter==0){
    cout<<"Sorry we could not find any results for the director: "<<Director
   	<<"."<<endl<<endl;
  } 
}

void dvd_collection::print_database(){
  
  cout<<endl;//Format
  //Prints the list to the screen. 
  for(list<dvd>::iterator it=dvds.begin();it!=dvds.end(); it++){
    cout<<"The title of the dvd is "<<it->Title<<"."<<endl
	<<"The director of the dvd is "<<it->Director<<"."<<endl
	<<"The release year of the dvd is "<<it->Release_Year
	<<"."<<endl
	<<"The dvd's rating is " <<it->Rating<<"."<<endl
	<<"The runtime of the dvd is "<<it->Runtime
	<<" minutes."<<endl<<endl;
  }

}

void dvd_collection::read_from_file(string file_name){
  dvd temp;
  ifstream infile;
  infile.open (file_name.c_str());
  
  //Priming  read to get the title
  getline(infile,temp.Title);

  //Loop to get the dvds information form file and add to link list.
  while(infile){
    getline(infile,temp.Director);
    infile>>temp.Release_Year;
    infile>>temp.Rating;
    infile>>temp.Runtime;
    infile.ignore();
    insert_sorted(temp);
    getline(infile,temp.Title);
  }

  infile.close();
}

void dvd_collection::write_to_file(string file_name){
  ofstream outfile;
  
  
  outfile.open(file_name.c_str());
  
  //Prints a header to the file.
  outfile<<"The dvds of the dvd_collection are as followed:\n"<<endl;
  //Prints all the dvd's information to a file.
  for(list<dvd>::iterator it=dvds.begin();it!=dvds.end(); it++){
    outfile<<"The title of the dvd is "<<it->Title<<"."<<endl
   	   <<"The director of the dvd is "<<it->Director<<"."<<endl
   	   <<"The release year of the dvd is "<<it->Release_Year
   	   <<"."<<endl
   	   <<"The dvd's rating is " <<it->Rating<<"."<<endl
   	   <<"The runtime the dvd is "
   	   <<it->Runtime<<" minutes ."<<endl<<endl;
  }
  outfile.close();
}

void dvd_collection::add_dvd(){

  dvd temp;

  //Prompts the user for information then adds it to the link list.
  cout<<"What is the dvd's title?"<<endl;
  getline(cin,temp.Title);

  cout<<"Who is the dvd's director?"<<endl;
  getline(cin,temp.Director);

  cout<<"What is the release year of the dvd?"<<endl;
  cin>>temp.Release_Year;

  cout<<"What is the dvd's rating ?"<<endl;
  cin>>temp.Rating;

  cout<<"What is the runtime of the movie in minutes?"<<endl;
  cin>>temp.Runtime;

  cin.ignore();//Moves buffer.

  insert_sorted(temp);//Adds dvd to the list.

  cout<<"\nIt is done we hope you enjoy!"<<endl;

}

void dvd_collection::delete_dvd(string Director,string Title){

  //If list if empty.
  if(dvds.empty()){
    cout<<"The collection is empty  please add dvds to the collection. "<<endl;
    return;
  }
  //If the collection is not empty.
  else{
    int counter =0;//See if dvd is in the database
    //Searches for the node
    for(list<dvd>::iterator it=dvds.begin();it!=dvds.end();it++){
      if(it->Director ==Director && it->Title==Title){
	dvds.erase(it);
	counter++;
	cout<<"The dvd you searched for was deleted."<<endl;
	return;
      }
    
    }
    //If not in database
    if(counter==0){
      cout<<"Sorry the dvd you search for was not in the collection please try again."<<endl;
    }
  }
}
