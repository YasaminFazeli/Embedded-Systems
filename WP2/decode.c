// (C) __Your names here: Amin Mahmoudifard, Yasamin Fazelidehkordi, Patrik Samcenko, group: 28 __ (2022) 
// Work package 2 
// Exercise 4
// Submission code: 0202qq (provided by your TA-s) 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Array of strings containing all four digit binary numbers, with their value corresponding to their index.
const char * hex_nibbles[] = { "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111" };

//Function to convert a single hexadecimal character into a binary nibble.
const char * hec2bin(unsigned char hex_digit) {
    //Check if the input character is a digit.
    if (hex_digit >= '0' && hex_digit <= '9'){
        //Return the appropriate nibble from the array.
        return (const char *) hex_nibbles[hex_digit - '0'];
    }
    //Check if the input is a letter between A and F (valid hexadecimal non-digit character).
    if (hex_digit >= 'A' && hex_digit <= 'F'){
        //Return the appropriate nibble from the array, adjusted for the fact that A is 10 instead of 0.
        return (const char *) hex_nibbles[10 + hex_digit - 'A'];
    }
    //Repeat the above for lowercase letters.
    if (hex_digit >= 'a' && hex_digit <= 'f'){
        return (const char *) hex_nibbles[10 + hex_digit - 'a'];
    }
    //Return an error value if the input character is not a valid hexadecimal digit.
    return (const char *) "-1";
}

void main(int argc, char *argv[]) {
    //Save the program argument in a variable.
    char *input = argv[1];

    if(!argv[1] || argv[2]) {
        printf("Invalid input. Please enter exactly one argument.");
        return;
    }
    if(!argv[1][1] || argv[1][2]){
        printf("Invalid input. Please exactly two hexadecimal digits.");
        return;
    }
    //Convert the first and second characters of the input array to binary.
    int first_character_binary = strtol(hec2bin(input[0]), NULL, 2);
    int second_character_binary = strtol(hec2bin(input[1]), NULL, 2);

    //Check if either character is not a valid hexadecimal digit, using the hec2bin function.
    if(first_character_binary == -1 || second_character_binary == -1){
        printf("Invalid input. Please enter only valid hexadecimal digits as arguments.");
        return;
    }

    //Bit shift the binary data of each converted character by its position, and apply a mask to isolate the correct number of binary digits for each datum.
    int engine_on = first_character_binary >> 3 & 1;
    int gear_pos =  (first_character_binary >> 2 & 1) * 4 + (first_character_binary >> 1 & 1) * 2 + (first_character_binary & 1);
    int key_pos = second_character_binary >> 2 & 11;
    int brake1 = second_character_binary >> 1 & 1;
    int brake2 = second_character_binary & 1;

    //Print out the output.
    printf("Name\t\tValue\n"
           "----------------------------\n"
           "engine_on\t%d\n"
           "gear_pos\t%d\n"
           "key_pos \t%d\n"
           "brake1  \t%d\n"
           "brake2  \t%d\n",
           engine_on, gear_pos, key_pos, brake1, brake2);
    return;
}