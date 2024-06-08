// (C) __Your names here: Amin Mahmoudifard, Yasamin Fazelidehkordi, Patrik Samcenko, group: 28 __ (2022) 
// Work package 1 
// Exercise 3 
// Submission code: 223344aa (provided by your TA-s) 

#include <stdio.h>
#include <stdlib.h>

//Set the maximum number of guesses
int MAX_NUMBER = 7;

//Create a function to play a single round of the game, for better readability of code.
void playRound(){
    //Generate a random number from 1 to 100
    int rndNum = (rand() %(100 - 1 + 1)) + 1;
    //Print initial instruction for the player
    printf("Alright, here goes. I'm thinking of a very special number. Don't forget, only between 1 and 100.\n");
    printf("Now make your guess:\n");
    int guessNum;
    //Loop MAX_NUMBER of times, limiting the guesses to that number.
    for(int i = 1; i <= MAX_NUMBER; i++) {
        //Take the input number from the user.
        scanf("%d", &guessNum);
        //Check whether number is out of range.
        if (guessNum > 100 || guessNum < 1) {
            //Inform the user their guess is out of bounds.
            printf("C'mon mate, told ya to only guess only between 1 and 100. Don't worry, I won't hold it against you. This once.\n");
            //Decrease the round number, for this guess to not count.
            i--;
        //Check whether the guess is correct.
        } else if (guessNum == rndNum) {
            //Inform the user they won, and in how many guesses (the current value of i)
            printf("You've got it! It took you ");
            printf("%d", i);
            printf(" attempts to guess my number. I'm impressed.\n");
            //Exit the round
            return;
        //Check whether the guess is too high.
        } else if (guessNum > rndNum) {
            //Inform the user the guess is too high.
            printf("Nu-uh, that's not it. You're going way too high.\n");
        //Check whether the guess is too low.
        } else if (guessNum < rndNum) {
            //inform the user the guess is too low.
            printf("Sorry, but no dice. Try a little higher next time.\n");
        }
        //Check if this is not the last round.
        if (i != MAX_NUMBER) {
            //If more rounds are to come, inform the user they have guesses remaining.
            printf("Don't worry though, you can still try again.\n");
        }
    }
    //If the loop finishes, the user didn't guess the number in time. Inform them of their loss.
    printf("Sorry, but that's it. No more guesses for you. You lose.\n");
}

void main() {
    //Print the initial welcome message, telling the user the rules of the game, and their maximum guesses.
    printf("Welcome to the 'Guess A Number Game'. I'll think of a number between 1 and 100, and all you gotta do is guess it. Easy, right? And as a bonus, just for you, I'll even tell you if you were aiming too high or too low when you make a wrong guess. But just so that it's not too simple, you only have ");
    printf("%d", MAX_NUMBER);
    printf(" guesses. Good luck!\n");
    //Loop until the user wishes to exit.
    while(1){
        //Execute the playRound function, as seen above.
        playRound();
        //Once the round finishes, ask the user to play again.
        printf("That was fun. Wanna play again? Just say 1 for yes, and anything else for no.\n");
        int ansNum;
        //Take the user input, to see if they want to play again.
        scanf("%d", &ansNum);
        //Check if the user wishes to exit.
        if (ansNum != 1){
            //Exit the loop.
            return;
        }
    }
}
