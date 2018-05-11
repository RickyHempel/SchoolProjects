/*****
Name-Ricky Hempel
Date-2/19/2018
Purpose to find the largest number in a array
I think it is printing the largest value 
because it compares one value of the array
to the next and the function returns the larger of the two 
values. 
****/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//array size
#define BUFFER_SIZE 4096
//function to find largest value in array
#define min(a,b) (a>b?a:b)
int main()
{
	int i;
	int loop;
	int largest;
	int array[BUFFER_SIZE];
	//seeds the rand function
	srand(time(0));
	//fills array
	for (i=0;i<BUFFER_SIZE;i++){
        array[i]=rand();
	}
	//The array index 0 is the largest at first
	largest = array[0];
	//loops to find the largest number
	for(loop=1; loop<BUFFER_SIZE;loop++){
        largest=min(array[loop],largest);
	}
	//tells user the largest value
	printf("The largest is %d\n",largest);
    return 0;
}