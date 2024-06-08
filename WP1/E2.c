// (C) __Your names here: Amin Mahmoudifard, Yasamin Fazelidehkordi, Patrik Samcenko, group: 28 __ (2022) 
// Work package 1 
// Exercise 2 
// Submission code: 223344aa (provided by your TA-s) 

// Include section/ Includes and uses these libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Main programm section

// Main function in the program
void main(int argc, char *argv[])
{

    // Variable declaration
    char *a = argv[1];   // Initialization of the passed in argument/ gets the passed in number by the user as an argument
    int shift = atoi(a); // Initialization of the shifting number/ converts it to its integer form

    // runs forever until user exists the program by e.g. ctrl + c
    while (1)
    {
        char text[100];                                                                // Initialization of the written text by the user
        printf("Write down the text (max 100 characters) you want to be encypted:\n"); // prints the welcome message and asks for the text from the user
        scanf("%100s", text);                                                          // scans/gets the text and saves in in the text variable
        int lenght = strlen(text);                                                     // Initialization of lenght of the text/ gets the lenght of the passed in text

        // for all the characters in the text
        for (int i = 0; i < lenght; i++)
        {
            int code = ((int)text[i]); // converts the character to its code on ASCII table
            if (code >= 65 && code <= 90)  // if it's in the capital range
            {
                int newCode = code + shift; // gives that character a new code by adding the shift number to it.
                if (newCode > 90)
                {
                    int remainder = newCode - 90;   // gets the remainder of after number 90
                    newCode = 64 + (remainder % 26);   // starts over from 64
                }
                text[i] = ((char)newCode); // replaces the new character in the text
            }
            else if (code >= 97 && code <= 122)  // if it's in the small range
            {
                int newCode = code + shift; // gives that character a new code by adding the shift number to it.
                if (newCode > 122)
                {
                    int remainder = newCode - 122;    // gets the remainder of after number 90
                    newCode = 96 + (remainder % 26);  // starts over from 64
                }
                text[i] = ((char)newCode); // replaces the new character in the text
            }
            else
            {
                printf("please only enter letters");  // prints the error message
                return;
            }
        }

        printf("Here is your encrypted text: %s\n", text); // prints the encrpted text
    }
}