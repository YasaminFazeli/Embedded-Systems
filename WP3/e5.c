// (C) __Your names here: Amin Mahmoudifard, Yasamin Fazelidehkordi, Patrik Samcenko, group: 28 __ (2022) 
// Work package 3 
// Exercise 5
// Submission code: 0808xx (provided by your TA-s)

// Headers and libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <setjmp.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Define maximum size of the array
 const int MAX = 4;
    
// The function that creates random integers
int createNum(){
   // We use rand function to create random integers from 1 tp 99.
   return (rand() % (99 - 1 + 1)) + 1;
}

// Main function
int main(int argc, char *argv[]){
   // Use current time as seed for generating random integer
   srand(time(0));
   // Define a pointer to an array of integers
    int *arr[MAX];
    // Define an integer
    int number;
    
    for(int i=0; i<MAX; i++){
      // We creat a random number using creatNum function
     number = createNum();
     // PUt each created number in the array
 arr[i]=number;
 // Print each number
 printf("%d\n",number);
 // Print the size of each number in bytes
 printf("The size of an integer is %d\n",sizeof(number));
    }
    // Print the value of the address of the arr pointer
 printf("The value of the address of the pointer is %d\n", arr );
 // Print the first integer in the array that arr pointer points to
 printf("First interger of the array is : %d\n",arr[0]);
 // Print the last integer in the array that arr pointer points to
 printf("The last integer in the array is %d\n",arr[3]);
 // Print the size of whole array
 printf("The size of the whole array in bytes is %d\n",sizeof(arr));
 
for(int i=0; i<MAX;i++){
   // Get the value of each index of the array that arr is poiting to
   int value=*(arr+i);
   // print the value of each integer
   printf("%d\n",value);
   // print the value multiplied by 2
   printf("%d\n", 2*value);
   }
    return 0;
}