// (C) __Your names here: Amin Mahmoudifard, Yasamin Fazelidehkordi, Patrik Samcenko, group: 28 __ (2022) 
// Work package 3 
// Exercise 6
// Submission code: 0808xx (provided by your TA-s)

// Headers and libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <setjmp.h>
#include <string.h>
#include <ctype.h>

// Define max size as 20
#define MAX 20

// Declare a function that copies a string to another string
// It gets the fisrt string and the string in which we want to copy first one as parameters
void copyString(char string[MAX],char string2[MAX]){
 
  for(int i=0; i<MAX; i++){
     // we get each character in the first string with a for loop 
    // and we put it in the same index number of the other array
    char temp = string[i];
     string2[i]=temp;
  }
}


// main function
int main(int argc, char *argv[]){
  // Define first string as array of characters 
  char s[MAX];
  // Define the second string as an array of characters
  // The first array is going to be copied in the second array using the strcpy function
  char s2 [MAX];
  // Define the third string as an array of characters
  // The third array is going to be copied in the third array using our own function
  char s3 [MAX];
  // Get the input string and puts it in the s variable
  fgets(s,MAX,stdin);
  // strcpy function copies string into the variable called s2
  strcpy(s2,s);
  // print the second string
  printf("%s\n",s2);
  // Copy the first string into the varaible called s3
  copyString(s,s3);
  // print the third array
     printf("%s\n",s3);
     // exit the program
    return 0;
}