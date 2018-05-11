/* Name: Ricky Hempel
   Justin Evans
   Tanner Thurman
   Date: 10/21/14
   Purpose: Create a library class that works with books.
   File: library.h
*/

//MicroGuards.
#ifndef library_h
#define libray_h

#include <string>//String Use.
#include "book.h"//Header for book struct. 
 using namespace std;

class library{
  
  book *head; //Declares a pointer that points to the first node in the list.
  
 public:

  library();
  /*
    Description: 
    Default Constructor creates an empty head.
  */

  ~library();
  /*
    Description:
    Default Destructor deletes all nodes of the list and the head.
  */

  void insert_sorted(book node);
  /*
    Description:
    Inserts nodes in alphabetical order.
  */

  void find_title(string Title);
  /*
    Description:
    Finds the title of a book in the library and prints all the 
    information of all books that contain the title.
    
    Postconditions:
    The information of the book's with that title have been printed to STDOUT.
  */
  
  void find_author(string Author);
  /*
    Description:
    Finds the author of a book in the library and prints all the 
    information of all books that contain the author.
    
    Postconditions:
    The information of the book's with that author have been printed to STDOUT.
  */

  void print_database(); 
  /*
    Description:
    Prints the entire library.

    Postconditions:
    Prints the information of the library to STDOUT.

  */

  void read_from_file(string file_name); 
  /*
    Description:
    Reads books from a file_name, and stores them in a link list.

  */

  void write_to_file(string file_name); 
  /*
    Description:
    Writes the library into a file.

  */

  void add_book();
  /*
    Description:  
    Ask for a new book's information then
    adds a book node to the library list.
  */

  void delete_book(string Author, string Title);
  /*
    Description:
    Ask the user for an title and an author's name and  
    searches the list and if such a record exists 
    delete first book with a matching artist and title.
  */

};
#endif
