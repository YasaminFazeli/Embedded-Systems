// (C) __Your names here: Amin Mahmoudifard, Yasamin Fazelidehkordi, Patrik Samcenko, group: 28 __ (2022) 
// Work package 2 
// Exercise 3
// Submission code: 0202qq (provided by your TA-s) 
#include <stdlib.h> 
#include <stdio.h> 
#include <string.h>
 
// -----typedefs  PERSON------- 
typedef struct { 
        char firstname[20]; 
        char famname[20]; 
        char pers_number[13]; // yyyymmddnnnn
} PERSON; 
 
// Function declaration   
PERSON input_record(void);             // Reads a person’s record. 
void write_new_file(PERSON *inrecord);  // Creates a file and  
// writes the first record 
void printfile(void);     // Prints out all persons in the file 
void search_by_firstname(char *name); // Prints out the person if    
// in list  
void append_file(PERSON *inrecord);    // appends a new person to the file 
void search_by_lastname(char *name);

//###### Main program ####### 
int main(void){ 
    // instantiate the welcome message
    char message[] = "Welcome, Please choose an option from below: \n   1 Create a new and delete the old file.\n   2 Add a new person to the file.\n   3 Search for a person in the file.\n   4 Print out all in the file.\n   5 Exit the program.\n";

    PERSON *ppost = malloc(sizeof(PERSON));            // allocate memory for the ppost in the heap
    if (ppost == NULL)                      // if unsuccessful
    {
        return 1;                           // exit the program
    }
    // set dummy data for the ppost
    strcpy(ppost->firstname, "amin");       
    strcpy(ppost->famname, "mahmoudi");
    strcpy(ppost->pers_number, "000000000000");

    // declares the variable for the input users enters
    int input;
    // as long as the inputet value is between 1 and 5 do the below
    do
    {
        printf("%s", message);          // print the welcome message
        scanf("%d", &input);            // scan the inputed number from user
        switch (input)                  // based on the input
        {
        case 1:
        {
            write_new_file(ppost);      // calls the method 
            break;
        }
        case 2:
        {
             // calls the methods
            PERSON my_person = input_record();     
            append_file(&my_person);                
            break;
        }
        case 3:
        {
            // variable declaration
            int option;
            char name[20];
            char last_name[20];
            // asks the user for how they want to search the data
            printf("For seraching by name enter 1 and for searching by last-name enter 2:\n");
            scanf("%d", &option);               // scans the input and saves it in the option
            switch (option)       // based on the input
            {
            case 1:             // if by firstname
                printf("Please enter the first name:\n");           // asks for the name
                scanf("%s", name);                                  // saves the name in name
                search_by_firstname(name);                          // calls the method and gives the name
                break;
            case 2:             // if by lastname
                printf("Please enter the last name:\n");            // asks for the name
                scanf("%s",last_name);                              // saves the name in name
                search_by_lastname(last_name);                      // calls the method and gives the name
                break;
            default:
                printf("The number is not in the range.\n");        // if neither prints the error message
                break;
            }
            
            break;
        }
        case 4:
        {
            // calls the method
            printfile();
            break;
        }
        case 5:
        {
            // exits the program
            return 0;
            break;
        }
        default:
        {
            printf("The number is not in the range.\n");            // if neither prints the error message
            break;
        }
        }

    } while (input > 0 && input < 6);
    
    
    return(0);     
} 

// ====     End of main   ====================================== 

// creates a new file
void write_new_file(PERSON *inrecord)
{
    FILE *file = fopen("people.bin", "wb");             // craetes a new file called "people.bin" 
    if (file != NULL)                                   // if successful
    {
        fwrite(inrecord, sizeof(PERSON), 1, file);      // writes the passed in person information in the file
        fclose(file);                                   // closes the file
    }

}

// asks for data and creates a new person object and returns it
PERSON input_record(void)
{
    // variable declaration
    char name[20];
    char last_name[20];
    char ssn[13];

    // asks and saves the information in the declared variables
    printf("Please enter the first-name: ");
    scanf("%s", name);
    printf("\nPlease enter the last-name: ");
    scanf("%s", last_name);
    printf("\nPlease enter the social security number: ");
    scanf("%s", ssn);

    // declares a new person object and sets its sub values to the values we got above
    PERSON temp;
    strcpy(temp.firstname, name);
    strcpy(temp.famname, last_name);
    strcpy(temp.pers_number, ssn);

    return temp;        // returns the data
}

// appends the given person object to the file
void append_file(PERSON *inrecord)
{
    FILE *file = fopen("people.bin", "ab");         // opens the file for appending data
    if (file != NULL)                               // if successful 
    {
        fwrite(inrecord, sizeof(PERSON), 1, file);  // writes (adds) the person object
    } else
    {
        printf("The file doesn't exist.\n");        // if unsuccessful prints the error message
    }
    fclose(file);       // closes the file
}

// serachs data by the firstname
void search_by_firstname(char *name)
{
    FILE *file = fopen("people.bin", "rb");     // opens the file for reading binary
    if (file != NULL)                           // if successful
    {
        fseek(file, 0, SEEK_END);               // goes to the end of the file
        if (ftell(file) == 0)                   // if nothing there (empty)
        {
            printf("The file is empty.\n");     // prints error message
        }
        fseek(file, 0, SEEK_SET);               // if not empty moves back to the begining of the file
        while (1)       // do until you break out
        {
            PERSON *temp = malloc(sizeof(PERSON));                          // instantiate and allocate memory for the object in the heap
            fread(&temp->firstname, sizeof(temp->firstname), 1, file);      // reads the firstname
            fread(&temp->famname, sizeof(temp->famname), 1, file);          // reads the lastname
            fread(&temp->pers_number, sizeof(temp->pers_number), 1, file);  // reads the ssn
            
            if (feof(file))     // if reached the end of the file
            {
                break;          // break out
            }
            int cmp = strcmp(temp->firstname, name);   // compares the value of the current's object's firstname with the name user is looking for
            if (cmp == 0)           // if equal prints the text below which includes the data they were looking for
            {
                printf("name: %s, lastname: %s, ssn: %s\n", temp->firstname, temp->famname, temp->pers_number);
            }
            free(temp);             // free the allocated memory
        }
    } else          // if unsuccessful to open the file
    {
        printf("The file doesn't exist.\n");        // prints the error message
    }
    fclose(file);           // closes the file
}

// serachs data by the firstname
void search_by_lastname(char *name)
{
    FILE *file = fopen("people.bin", "rb");     // opens the file for reading binary
    if (file != NULL)                           // if successful
    {
        fseek(file, 0, SEEK_END);               // goes to the end of the file
        if (ftell(file) == 0)                   // if nothing there (empty)
        {
            printf("The file is empty.\n");     // prints error message
        }
        fseek(file, 0, SEEK_SET);               // if not empty moves back to the begining of the file
        while (1)       // do until you break out
        {
            PERSON *temp = malloc(sizeof(PERSON));                          // instantiate and allocate memory for the object in the heap
            fread(&temp->firstname, sizeof(temp->firstname), 1, file);      // reads the firstname
            fread(&temp->famname, sizeof(temp->famname), 1, file);          // reads the lastname
            fread(&temp->pers_number, sizeof(temp->pers_number), 1, file);  // reads the ssn
            
            if (feof(file))     // if reached the end of the file
            {
                break;          // break out
            }
            int cmp = strcmp(temp->famname, name);  // compares the value of the current's object's firstname with the name user is looking for
            if (cmp == 0)       // if equal prints the text below which includes the data they were looking for
            {
                printf("name: %s, lastname: %s, ssn: %s\n", temp->firstname, temp->famname, temp->pers_number);
            }
            free(temp);         // free the allocated memory
        }
    } else          // if unsuccessful to open the file
    {
        printf("The file doesn't exist.\n");        // prints the error message
    }
    fclose(file);       // closes the file
}

// prints everything in the file
void printfile(void)
{
    FILE *file = fopen("people.bin", "rb");     // opens the file for reading binary
    if (file != NULL)                           // if successful
    {
        fseek(file, 0, SEEK_END);               // goes to the end of the file
        if (ftell(file) == 0)                   // if nothing there (empty)
        {
            printf("The file is empty.\n");     // prints error message
        }
        fseek(file, 0, SEEK_SET);               // if not empty moves back to the begining of the file
        
        while (1)        // do until you break out
        {
            PERSON *temp = malloc(sizeof(PERSON));                          // instantiate and allocate memory for the object in the heap
            fread(&temp->firstname, sizeof(temp->firstname), 1, file);      // reads the firstname
            fread(&temp->famname, sizeof(temp->famname), 1, file);          // reads the lastname
            fread(&temp->pers_number, sizeof(temp->pers_number), 1, file);  // reads the ssn
            
            if (feof(file))     // if reached the end of the file
            {
                break;           // break out
            }
            // prints the data of that person like below
            printf("name: %s, lastname: %s, ssn: %s\n", temp->firstname, temp->famname, temp->pers_number);
            free(temp);         // free the allocated memory
        }
    } else              // if unsuccessful to open the file
    {
        printf("The file doesn't exist.\n");        // prints the error message
    }
    fclose(file);       // closes the file
}