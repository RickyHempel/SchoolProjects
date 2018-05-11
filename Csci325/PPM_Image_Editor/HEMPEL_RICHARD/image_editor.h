/*
Name-Ricky Hempel
Date-10/04/14
File-image_editor.h
Purpose-To store header information for the image
editor class.

 */


#ifndef image_editor_h//Micoguard.
#define image_editor_h//Micoguard.
#include <iostream>//STDOUT/STDIN.
#include <string>//To use stings.
#include <vector>//To use vectors.

using namespace std;//Namsespace standard 

class image_editor{//Declares the class.
  //private: by default 
  string magic_number;//The 3 number stored in a string.
  int width,height,max_color;//The width height and max color stored in ints
  vector<int> red,green,blue;//The red green and blue values for each pixel stored in vectors of ints.

  public:
   void read_image(string file_name);
   /*
     Returns:Nothing 
    
     Takes in an a string of the file name to input values
     
     Function:Reads in numbers from a file and stores them in above elements  
             Also stores the red green and blue values for each pixel in a vector.


    */

  void write_image(string file_name);
  /*
    Returns:Nothing.
    
    Takes in a name of the to output the values to, to make an image.
    
    Function:Outputs the numbers to a file and vectors in order with spaces between them.
   */

  void grey_scale();
  /*
  Returns:Nothing
  
  Takes in Nothing.
  
  Function:Finds the average of the three vector elements and 
           elements to the average.

  */
  void flip_image();
  /*
    Returns:Nothing.
    
    Takes in Nothing.
    
    Function:Reverses the vectors to "flip the image".

   */
  void red_only();
  /*
    Returns:Nothing.
    
    Takes in Nothing.
    
    Function:Zeros out the blue and green values to make the image redscale.
 
   */
  void green_only();
  /* 
    Returns:Nothing.
    
    Takes in nothing.

   Function:Zeros out the blue and red values to make the image greenscale.
   */

  void blue_only();
  /*
    Returns:Nothing
    
    Takes in nothing.
 
    Function:Zeros out the red and green values to make the image  bluescale.


  */

};//End of class.
#endif//End Micoguard.
