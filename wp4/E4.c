// (C) __Your names here: Amin Mahmoudifard, Yasamin Fazelidehkordi, Patrik Samcenko, group: 28 __ (2022) 
// Work package 4 
// Exercise 4
// Submission code: 8989cc (provided by your TA-s) 

// The headers and libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <setjmp.h>
#include <string.h>
#include <ctype.h>

// The function that gets a number, an array of integers and the size of array
// The function retrun the index of a searched number in the array
// If the element does not exist in the array, -1 is returned.
int search_number(int number, int tab[], int size)
{
  
  int index=-1;
  // search the whole array starting from last index 
  for (int i = size - 1; i >= 0; i--)
  {
    if (number == tab[i])   // If number exists in the array
    {
      index = i;            // Get the index of number
    }
  }
  return index;             // Return the index of the number
}

// A function that gets a number as the size of array and array of integers and sort the array
void sort(int number, int tab[])
{
  // Iterate over all the elements in the array
  for (int i = 0; i < number - 1; i++)
  {
    int min = i;    // PUt index i as the index of minimum element in the array
    // Get the element next to index i
    for (int j = i + 1; j < number; j++)
    {
      if (tab[j] < tab[min])   // If the next element is smaller than the element at index i 
      {
        min = j;   // put next index which is j as the index of minimum element
      }
    }
    // Here we swap the elements at index i with the element at index min
    int temp = tab[min];  //put element at index min in temp variable
    tab[min] = tab[i];    //put element and index i at min index
    tab[i] = temp;        //put temp at index i
  }
}

// The main function
int main(int argc, char *argv[])
{ 
  // Declare an integer variable
  int n;
  // Declare an array of integers for testing the sorting function
  int test[] = {1, 2, 34, 5, 67, 3, 23, 12, 13,10};
  // Ask the user to type a number 
  printf("%s\n", "Please type a number");
  // put input number in the variable n
  scanf("%d", &n);
  // Search for the number inside the array and retrun its index in the array
  int value = search_number(n, test, 10);
  //print the index of number in the test array
  printf("%d\n", value);
  // Sort the test function with sort function that has been defined above.
  sort(12, test);
  // print all the elments in the test array to check if they are actually sorted now!
  for (int i = 0; i < 10; i++)
  {
    printf("%d ", test[i]);
  }
  return 0;
}
