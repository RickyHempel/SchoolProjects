/* Name: Ricky Hempel
   Date: 11/7/14
   Purpose: Create a dvd_collection class that works with dvd.
   File: dvd_collection.h
*/

//MicroGuards.
#ifndef dvd_collection_h
#define dvd_collection_h

#include <string>//String Use.
#include <list>//For the linked list
#include "dvd.h"//Header for book struct. 
using namespace std;

class dvd_collection{
  list <dvd> dvds;//list of dvds
    
 public:
  
  void insert_sorted(dvd node);
  /*
    Description:
    Inserts nodes in alphabetical order.
  */

  void find_title(string Title);
  /*
    Description:
    Finds the title of a dvd in the dvd_collectionand prints all the 
    information of all dvds that contain the title.
    
    Postconditions:
    The information of the dvd's with that title have been printed to STDOUT.
  */
  
  void find_director(string Director);
  /*
    Description:
    Finds the director of a dvdin the dvd_collectionand prints all the 
    information of all dvds that contain the director.
    
    Postconditions:
    The information of the dvd's with that director have been printed to STDOUT.
  */

  void print_database(); 
  /*
    Description:
    Prints the entire collection.

    Postconditions:
    Prints the information of the dvd_collectionto STDOUT.

  */

  void read_from_file(string file_name); 
  /*
    Description:
    Reads dvd's from a file_name, and stores them in a link list.

  */

  void write_to_file(string file_name); 
  /*
    Description:
    Writes the dvd_collectioninto to a file.

  */

  void add_dvd();
  /*
    Description:  
    Ask for a new dvd's information then
    adds a dvdnode to the dvd_collection list.
  */

  void delete_dvd(string Director, string Title);
  /*
    Description:
    Ask the user for an title and an director's name and  
    searches the list and if such a record exists 
    delete first dvd with a matching director and title.
  */
  
};
#endif
