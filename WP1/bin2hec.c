// (C) __Your names here: Amin Mahmoudifard, Yasamin Fazelidehkordi, Patrik Samcenko, group: 28 __ (2022) 
// Work package 1 
// Exercise 4
// Submission code: 223344aa (provided by your TA-s) 

// Include section/ Includes and uses these libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <setjmp.h>
#include <ctype.h>

// Define section
//defines try/catch functionalities plus the Entry loop and Throw function
// basically mimics the try catch function in other languages
#define TRY do{ jmp_buf ex_buf__; if( !setjmp(ex_buf__) ){    // defines the try block by jmp_buf and setjmp so that when 
                                                              // errors happen it does setjmp and goes to catch block

#define CATCH } else {                                        // defines the catch block

#define ETRY } }while(0)                                      // defines the end of try-catch block

#define THROW longjmp(ex_buf__, 1)                            // defines the throw function for when you want to throw exceptions

// Main method section
int main(int argc, char *argv[])
{
    // variable declaration section
    // creates a string containing the hexadecimal characters and their coresponding indices
    const char *hex_digits = "0123456789ABCDEF";
    // The message for when user passes in wrong/undesired input
    char errorM[] = "Something went wrong! For getting help on how to use the system, rerun the program and pass '-h' as an argument.\n";
    // The helping message
    char helpM[] = "Please enter you name with no spaces in between. Also, you should only enter one name.\n";

    if (!argv[1])
    { // If it doesn't exist, system prints the message below and turns on the code (-h) stage
        printf("%s", errorM);
    }
    else if ((strcmp(argv[1], "-h")) == 0) // Checks if the passed in argument is -h code to get help
    {                        
        printf("%s", helpM); // Prints the helping message
        return 0;            // Exists the program
    }
    else  // If the input is not empty or -h 
    {
        // Tries to execute this and if any error occured, it goes to the catch block and prints the error message 
        TRY
        {
            // Here it checks if there are any characters existing in the input
            char *input = argv[1];                  // Gets the input passed as an argument in command line
            int size_input = strlen(argv[1]);       // Gets the size of the characters of the input
            for (int i = 0; i < size_input; i++)    // For all the characters inside the input (argv[1])
            {
                if (!isdigit((argv[1])[i]) || ((argv[1])[i] != '1' && (argv[1])[i] != '0'))     // Checks if the character in that position is a digit and that is not bigger than 1
                {
                    THROW;       // If an character or a digit bigger than 1, detected throws an exception
                }
            }

            char temp[64];                          // creates a temporary string for the purposes of getting the lenght of the input
            strcpy(temp, argv[1]);                  // copy the input to the temporary array
            int size = strlen(temp)/4 + ((strlen(temp)%4>0)*1);     // devide the lenght of the temporary array by 4, rounding up, 
                                                                    // to determine the lenght of the output and saves it in variable size

            long binary = strtol(input, NULL, 2);       // converts the input to binary
            char output[size];                          // creates an empty array for the output with the appropriate size
            
            for (int i = 0; i < size; ++i)              // loops through the output array
            {
                int last_nibble = binary & 0b1111;              // isolates the last 4 digits of the binary
                output[i] = hex_digits[last_nibble];         // adds the appropriate hexadecimal character
                binary = binary >> 4;                        // right shifts the binary by 4 thus moving to the next nibble
            }
            for (int i = size - 1; i >= 0; i--)              // prints out the output array in reverse order
            {
                printf("%c", output[i]);      // prints that character
            }
        }
        CATCH          // Catch block, these happens when an error occures or when the program fails to convert
        {
            printf("%s", errorM);     // Prints the wrong input message 
            return 2;                 // returns 2
        }
        ETRY;                         // represents the end of try-throw-catch block

        return 0;                     // exits the program
    }
}
