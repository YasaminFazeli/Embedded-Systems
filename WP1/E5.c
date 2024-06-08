// (C) __Your names here: Amin Mahmoudifard, Yasamin Fazelidehkordi, Patrik Samcenko, group: 28 __ (2022) 
// Work package 1 
// Exercise 5 
// Submission code: 223344aa (provided by your TA-s) 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100 // Defines the maximum number of the values in the table
#define MAXNUMBER 20 // Defines the maximum value of random numbers


//Initialise variable to hold the actual length of the tab array
int length;

// ------ Function declarations   ----------

// This function generates a set of random numbers
// and fills the table *tab with these numbers

void create_random(int *tab){
    //Set the seed of the pseudo-random generator using current time.
    srand(time(0));
    //Randomly generate the length of the tab array, with possible values between 1 and MAX
    length = (rand() %(MAX- 1 + 1)) + 1;
    //Loop through every element of the tab array to be filled.
    for (int i = 0; i < length; i++){
        //Insert a random value between 1 and MAXNUMBER into the current index of tab.
        tab[i] = (rand() %(MAXNUMBER - 1 + 1)) + 1;
    }
}

// This function takes the *tab of random numbers
// and creates a table with the frequency counts for these numbers
void count_frequency(int *tab, int *freq ){
    //Reset the values of the freq array.
    for (int i = 0; i < MAXNUMBER; i++){
        freq[i] = 0;
    }
    //Loop through the freq array.
    for (int i = 0; i < MAXNUMBER; i++){
        //Loop through the tab array.
        for (int j = 0; j < length; j++){
            //Every time an element of tab is encountered, with the same value as the current index of freq, the current value of freq is increased by one.
            if (tab[j] == i){
                freq[i]++;
            }
        }
    }
}

// This function takes the frequency count table
// and draws a histogram of the values in that frequency table
void draw_histogram(int *freq ){
    //Loop through the freq array.
    for (int i = 0; i < MAXNUMBER; i++){
        //Check whether the frequency of the current index is not 0 (i.e. whether there were any instances of that number in tab).
        if (freq[i] != 0){
            //Print the current index (the number whose frequency is being printed).
            printf("%d", i);
            //Print as many x as the current value of freq.
            for(int j = 0; j < freq[i]; j++){
               printf("x");
            }
            printf("\n");
        }
    }
}

// ------ Function definitions   ----------


// ------ Main   --------------------------

// The main entry point for the program
//
// If you choose to go for the optional part
// Please modify it accordingly
int main (void){

    //Initialise the arrays at their maximum potential length.
    int table[MAX], n;
    int frequency[MAXNUMBER];

    //Call the above functions with the proper arrays.
    create_random(table);
    count_frequency(table, frequency);
    draw_histogram(frequency);
    return 0;
}

