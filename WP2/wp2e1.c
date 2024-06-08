// (C) __Your names here: Amin Mahmoudifard, Yasamin Fazelidehkordi, Patrik Samcenko, group: 28 __ (2022) 
// Work package 2 
// Exercise 1
// Submission code: 0202qq (provided by your TA-s) 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// declaration of our enums
enum DIRECTION {N,E,S,W}; 
 
// ##### typedefs    ROBOT      #### 
typedef struct { 
        int xpos; 
        int ypos; 
        enum DIRECTION dir; 
} ROBOT;

// ##### Function declarations   ##### 
char * get_string(char *text);
void turn(ROBOT *robot);
void move(ROBOT *robot);


//###### Main program ####### 
int main(void)
{
    // while loop until we break out of it (with q as quit)
    while (1)
    {
        int x;      // variable declaration for x cordinates that user inputs
        int y;      // variable declaration for x cordinates that user inputs
        char *instruc = get_string("Write down the instructions word: ");      // declare and instantiate instruct and saves the returned value by get_string method
        printf("X cordinate: ");    // prints the message on console asking for X
        scanf("%i", &x);            // scans the input and and saves it in the x variable
        printf("Y cordinate: ");    // prints the message on console asking for Y
        scanf("%i", &y);            // scans the input and and saves it in the x variable
    
        ROBOT *my_robot;            // declare our robot object
        my_robot->xpos = x;         // saves the x in the xpos of the robot
        my_robot->ypos = y;         // saves the y in the ypos of the robot
        my_robot->dir = N;          // puts the initial value of the direction as north


        int current_x = my_robot->xpos;         // instantiate the variable with the value of robot's current x position
        int current_y = my_robot->ypos;         // instantiate the variable with the value of robot's current y position
        char current_dir = my_robot->dir;       // instantiate the variable with the value of robot's current direction
        for (char i = 0, n = strlen(instruc); i < n; i++)     // for all the characters in the instructions array (string)
        {
            if (instruc[i] == 'm'){             // if the character is equal to 'm'
                move(my_robot);                 // call the move method and move the robot by one position
            } else if (instruc[i] == 't')       // if the character is equal to 't'
            {
                turn(my_robot);                 // call the turn method and turn the robot 90 degrees clockwise
            } else if (instruc[i] == 'q')       // if the character is equal to 'q'
            {
                return 0;                       // simply quit the program
            }
        
        }
        // print the new X & Y cordinates in the console
        printf("New X & Y cordinates are %i and %i respectively. For quiting the program you can simply add the character 'q' in your instructions.\n", my_robot->xpos, my_robot->ypos);
        
    }  

}

// ====     End of main   ====================================== 

// moves the given robot (passed in as parameter) based on its current direction
void move(ROBOT *robot)
{
    switch (robot->dir)             // based on the current direction
        {
        case N:                     // if the robot is facing north
            robot->ypos += 1;       // move it +1 vertically
            break;
        case S:                     // if the robot is facing south
            robot->ypos -= 1;       // move it -1 vertically
            break;
        case E:                     // if the robot is facing east
            robot->xpos += 1;       // move it +1 horizontally
            break;
        case W:                     // if the robot is facing west
            robot->xpos -= 1;       // move it -1 horizontally
            break;
            
        default:
            printf("Incorrect direction!");          // if neither, print error message
            break;
        }
}

// turns the given robot (passed in as parameter) 90 degrees clockwise based on its current direction
void turn(ROBOT *robot)
{
    switch (robot->dir)             // based on the current direction
        {
        case N:                     // if the robot is facing north
            robot->dir = E;         // update the direction to east
            break;
        case S:                     // if the robot is facing south
            robot->dir = W;         // update the direction to west
            break;
        case E:                     // if the robot is facing east
            robot->dir = S;         // update the direction to south
            break;
        case W:                     // if the robot is facing west
            robot->dir = N;         // update the direction to north
            break;
            
        default:
            printf("Incorrect direction!");         // if neither, print error message
            break;
        }
}

// gets the string from user and saves it in an char *(string) dynamically  /daynamic array
char * get_string(char *text)
{
    fflush(stdin);              // flushes/clears the stdin
    int n = 0;                  // instantiates int n with intial value of 0
    char c;                     // variable c declaration
    int MAX_SIZE = 10;          // instantiates the variable with intial value of 10 refering to the intial size that an array is gonna be saved in
    char *input = malloc(MAX_SIZE * sizeof(char));       // instantiates a pointer called input and allocates memmory for it in the heap
     if (input == NULL)                        // if the program couldn't allocate memmory
    {
        return NULL;                           // return null
    }
    char *temp = NULL;                         // instantiate the pointer temp initially pointing to nothing

    printf("%s", text);                        // prints the message passed in as a parameter (asking what we want from the user)

    while( (c=getchar())!='\n' && c != EOF){   // as long as you dont face a space or next line (enter)
        if (n > MAX_SIZE - 1)                  // if we're exceeding the initial allowed size
        {
            MAX_SIZE = MAX_SIZE * 2;                // double the allowed size
            temp = realloc(input, MAX_SIZE);        // instantiate the temp pointer with the address of reallocated place of memory in the heap with the new allowd size
            if (!temp) {                            // if unsuccessful
                free(input);                        // free the memory for input
                input = NULL;                       // make the poiter pointing to null
                break;                              // break out of the method
            }
            free(input);                            // if successful, free the initial place of memory for input
            input = temp;                           // make the input pointer to point to where temp is pointing (the new place of memory we created)
        }
        
        input[n]=c;             // put the character in the right place
        n++;                    // increase the value of the n (indicating the number of characters)
    }
    input[n]='\0';              // close the array so to say with adding the end character at the end of the array (string)
    return input;               // return the string 
}