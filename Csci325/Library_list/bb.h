/*




*/

#ifndef book_h_
#define book_h_
#include <string>
using namespace std;
struct book{
  book *next;
  string Title;
  string Author;
  int Copyright_Year;
  int Edition;
  int Number_of_Pages;
};
#endif
