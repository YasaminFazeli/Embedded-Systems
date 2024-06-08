// (C) __Your names here: Amin Mahmoudifard, Yasamin Fazelidehkordi, Patrik Samcenko, group: 28 __ (2022) 
// Work package 1 
// Exercise 1
// Submission code: 223344aa (provided by your TA-s) 

// Built-in header file
#include <stdio.h>
// standard input and output library functions
#include <stdlib.h>
#include <stdbool.h>

// main fucntion which gets two parameters
int main(int argc, char *argv[])
{
    // declare an int variable
    int input;
    // Declare an array of char for when the input is 1
    char a[] = "Hello welcome!\n";
    // Declare an array of char for when the input is 2
    char b[] = "Here is the second sentence\n";
    // Declare an array of char for when the input is 3
    char c[] = "Here is the third sentence\n";
    // Declare an array of char for when the input is 4
    char d[] = "Here is the forth sentence\n";
    // Declare an array of char for when the input is 5
    char e[] = "Here is the fifth sentence\n";
    // Here do the following code at least once
    do
    {
        // Show this message to the user for get an input between 1 and 5
        printf("Please type an integer between 1 and 5. \n");
        // Get the input from the user
        scanf("%d", &input);
        // a swtich case which gets input and checks the value in different cases
        switch (input)
        {
        // If the input is 1
        case 1:
        {
            // print the first array which is called a in the console
            printf("%s", a);
            // After printing the string, break and exit the switch case blocks
            break;
        }
        // If the input is 2
        case 2:
        {
            // Print the second array which is called b in the console
            printf("%s", b);
            // After printing the string, break and exit the switch case blocks
            break;
        }
        // if the input is 3
        case 3:
        {
            // print the third string which is called c
            printf("%s", c);
            // After printing the string, break and exit the switch case blocks
            break;
        }
        // If the input is 4
        case 4:
        {
            // Print the fourth string which is called d
            printf("%s", d);
            // After printing the string, break and exit the switch case block
            break;
        }
        // If the input is 5
        case 5:
        {
            // Print the fifth string, which is called e
            printf("%s", e);
            // After printing the string, break and exit the switch case block
            break;
        }
        // In the default case
        default:
        {
            // tell the user that the input is not in range
            printf("The number is not in the range.\n");
            // After printing the statement, break and exit
            break;
        }
        };
        // After doing the above code once check the condition in the while and if its true
        // which means if the input is not in the desired range go into the loop again
    } while ((input > 0 && input < 6));
    // exit the program successfuly
    return 0;
}
