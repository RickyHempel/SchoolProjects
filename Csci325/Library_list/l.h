
#ifndef library_h
#define libray_h
#include <string>
#include "book.h"
using namespace std;
class library{

  book *head;
  
 public:
  library();
  ~library();
  void insert_sorted(book node);
  void find_title(string Title);
  void find_author(string Author);
  void print_database();
  void read_from_file(string file_name);
  void write_to_file(string file_name);
  void add_book();
  void delete_book(string Author, string Title);
};
#endif
