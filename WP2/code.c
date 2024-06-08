// (C) __Your names here: Amin Mahmoudifard, Yasamin Fazelidehkordi, Patrik Samcenko, group: 28 __ (2022) 
// Work package 2 
// Exercise 4
// Submission code: 0202qq (provided by your TA-s) 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//String containing the hexadecimal digits at their appropriate indices.
const char *hex_digits = "0123456789ABCDEF";

//Function to convert the first four bits into a hexadecimal character.
char getFirstHexChar(char engine_on[], char gear_pos[]){
    //Convert the inputs from strings into digits.
    int engine_on_digit = atoi(engine_on);
    int gear_pos_digit = atoi(gear_pos);
    //Bitshift the individual components by the appropriate amount according to their intended position within the nibble.
    int hex_digit = (engine_on_digit << 3) + gear_pos_digit;
    //Return the appropriate hexadecimal character by taking the index of the hex_digits string.
    return hex_digits[hex_digit];
}

//Function to convert the last four bits into a hexadecimal character.
char getSecondHexChar(char key_pos[], char brake1[], char brake2[]){
    //Convert the inputs from strings into digits.
    int key_pos_digit = atoi(key_pos);
    int brake1_digit = atoi(brake1);
    int brake2_digit = atoi(brake2);
    //Bitshift the individual components by the appropriate amount according to their intended position within the nibble.
    int hex_digit = (key_pos_digit << 2) + (brake1_digit << 1) + brake2_digit;
    //Return the appropriate hexadecimal character by taking the index of the hex_digits string.
    return hex_digits[hex_digit];
}

void main(int argc, char *argv[]) {
    //------------------------------CHECK IF INPUT IS VALID------------------------------------
    //Check for the correct amount of inputs. (Argument 5 must exist, but argument 6 must not).
    if(!argv[5] || argv[6]) {
        printf("Invalid input. Please enter exactly five arguments.");
        return;
        //TODO throw exception.
    }
    //Check if all inputs are single digits.
    for(int i = 1; i < 6; i++){
        //If there is a second character to any argument, or the first character is not a digit.
        if(argv[i][1] || !isdigit(argv[i][0])){
            printf("Invalid input. Please enter only digits as arguments.");
            return;
        }
    }
    //Check if all inputs are within specified boundaries.
    if(argv[1][0] > '1' || argv[2][0] > '4' || argv[3][0] > '2' || argv[4][0] > '1' || argv[5][0] > '1'){
        printf("Invalid input. Argument values out of bounds.");
        return;
    }
    //------------------------------END INPUT CHECKS------------------------------------------------


    //Call the functions to generate hexadecimal characters, using the program inputs as arguments.
    char first_char = getFirstHexChar(argv[1], argv[2]);
    char second_char = getSecondHexChar(argv[3], argv[4], argv[5]);
    //Print out the obtained characters.
    printf("%c%c", first_char, second_char);
    return;
}