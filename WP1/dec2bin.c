// (C) __Your names here: Amin Mahmoudifard, Yasamin Fazelidehkordi, Patrik Samcenko, group: 28 __ (2022) 
// Work package 1 
// Exercise 4
// Submission code: 223344aa (provided by your TA-s) 

// Include section/ Includes and uses these libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <setjmp.h>
#include <string.h>
#include <ctype.h>

// Define section
//defines try/catch functionalities plus the Entry loop and Throw function
// basically mimics the try catch function in other languages
#define TRY do{ jmp_buf ex_buf__; if( !setjmp(ex_buf__) ){    // defines the try block by jmp_buf and setjmp so that when 
                                                              // errors happen it does setjmp and goes to catch block

#define CATCH } else {                                        // defines the catch block

#define ETRY } }while(0)                                      // defines the end of try-catch block

#define THROW longjmp(ex_buf__, 1)                            // defines the throw function for when you want to throw exceptions


// Methods section

// Counts the number of bits needed to express the input decimal number into binary
int count_no_bits(int number)
{
  // Takes the log base 2 of the number and returns it
  return (int)log2(number) + 1;
}

// calculates the closest multipule of 8 graeter than a given number
int get_multiple_eight(int number)
{
  // takes the input number, substracts the remainder after when it's devided by 8 and then adds 8 and returns it
  return (int)(number - (number % 8) + 8);
}


// Main method section
int main(int argc, char *argv[])
{

  // The message for when user passes in wrong/undesired input
  char errorM[] = "Something went wrong! For getting help on how to use the system, rerun the program and pass '-h' as an argument.\n";
  // The helping message
  char helpM[] = "Please make sure that you enter a decimal number with no character and no spaces in between.\n";

  if (!argv[1])
  { // If it doesn't exist, system prints the message below 
    printf("%s", errorM);
  }
  // If the user enters -h 
  else if ((strcmp(argv[1], "-h")) == 0) // Checks if the passed in argument is -h code to get help
  {                      
    printf("%s", helpM); // Prints the helping message
    return 0;            // Exists the program
  }
  else // If the input is not empty or -h 
  {
    // Tries to execute this and if any error occured, it goes to the catch block and prints the error message 
    TRY 
    {

      char *number = argv[1];       // Gets the input passed as an argument in command line
      long num = atoi(number);      // Converts the input to a long/int since the input is an array of characters at first

      long result;                  // Declares the result variable for the binary result
      int c = count_no_bits(num);         // Calls the function and saves the result in variable c
      int loops = get_multiple_eight(c);    // Calls the function and saves the result in variable loops

      // Here it checks if there are any characters existing in the input
      int size = strlen(argv[1]);         // Gets the size of the characters of the input
      for (int i = 0; i < size; i++)      // For all the characters inside the input (argv[1])
      {
        if (!isdigit((argv[1])[i]))       // Checks if the character in that position is a digit or not
        {
          THROW;        // If an character detected throws an exception
        }
      }

      for (int i = loops - 1; i >= 0; i--)      // For the desired size of the ouput, does the below starting from the end
      {
        result = num >> i;      // Shifts the binary code to its right placement in the output

        if (result & 1)         // Compares the result with 1. So if both bits are 1, then it prints 1
          printf("1");          // Prints number 1
        else                    // Otherwise
          printf("0");          // Prints 0
      }

      printf("\n");             // Enters an space (next line)
    }
    CATCH    // Catch block, these happens when an error occures or when the program fails to convert
    {
      printf("%s", errorM);     // Prints the wrong input message 
      return 2;                 // returns 2
    }
    ETRY;                       // represents the end of try-throw-catch block

    return 0;                   // exits the program
  }
}