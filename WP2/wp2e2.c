// (C) __Your names here: Amin Mahmoudifard, Yasamin Fazelidehkordi, Patrik Samcenko, group: 28 __ (2022) 
// Work package 2 
// Exercise 2
// Submission code: 0202qq (provided by your TA-s) 
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
 
//#### Constants ##### 
#define MAX 5  
#define MAXNUMBER 100 
 
// ##### typedefs     node     #### 
typedef struct q{ 
        int number; 
        struct q *next; 
        struct q *prev; 
} node; 
 
// ##### Function declarations   ##### 
 
node* random_list(void); 
node* add_first(node* temp, int data); 
 
 
//###### Main program ####### 
int main(int argc, char *argv[]) 
{ 
    // variable/ pointer declaration
    int nr=0; 
 
    node *act_post , *head=NULL; 
 
    srand(time(0));  //   Random seed  
    head=random_list();   // calls the funstion and saves the returned value in head
    act_post=head;        // equals the head to act_post
    // prints all the elements in the list one by one
    while(act_post!=NULL){ 
           printf("\n Post nr %d : %d" , nr++, act_post->number); 
           act_post=act_post->next; 
    }
    printf("\n");
    nr = 0;
 
    act_post = head;                // updates the act_post to head again since it got altered in the above while loop
    act_post = add_first(act_post, 14);      // calls the funstion and gets the returned list in act_post
    // prints all the elements in the list one by one
    while(act_post!=NULL){ 
           printf("\n Post nr %d : %d" , nr++, act_post->number); 
           act_post=act_post->next; 
    }
    printf("\n");
 
 // --- Free the allocated memory  --- 
 
  while((act_post=head)!=NULL){ 
     head=act_post->next; 
     free(act_post); 
  } 
   
                    
 
  return 0; 
} 
 
// ====     End of main   ====================================== 
 
// generates a random double-linked list with random data
node* random_list(void){ 
    // variable declaration
    int nr, i=0; 
    node *top = NULL, *old = NULL, *item = NULL;   // pointers to the first node, most recent one and the item we're creating (respectively)


    // =====      create the very first element ==========================
    top = malloc(sizeof(node));                 // allocate memory for the top node
    if (top == NULL)                            // if unsuccessful
    {
        return NULL;                            // return null
    }
    nr = (rand() %(MAXNUMBER - 1 + 1)) + 1;     // if successful generate a random number and save it in nr
    top->number = nr;                           // update the value of the node's number to the generated number
    top->next = NULL;                           // the next pointer points to nothing (null) cause there's nothing after it
    top->prev = NULL;                           // the previous pointer points to nothing (null) cause there's nothing before it

    old = top;                  // sets our old node (the most recent one) to the top (the one we just created)

    // =====      create the rest of the elements ==========================
    for (i = 0; i < MAX - 1; i++)               // for 4 more times for the rest of the elements
    {
        item = malloc(sizeof(node));            // allocate memory for the item 
        
        if (item == NULL)                       // if not successful 
        {
            return NULL;                        // return null
        }
        
        nr = (rand() %(MAXNUMBER - 1 + 1)) + 1;     // generate a randome number
        item->number = nr;                          // set the value of the item's number to the generated number
        item->next = NULL;                          // the next pints to null cause there's no nodes after this
        item->prev = old;                           // the previous points to the old (most recent) node cause it was the last one and the new node comes after it

        old->next = item;                           // since the old node was pointing to nothing as its next and that we have a new node coming after it, it should poit to our new node as its next node
        old = item;                                 // our old (most recent) node is now item cause it's the latest one we created
    }
    
    
    return(top);                // return top which points to the top element which technically points to the double-linked list
} 
 
//==========================================================                 
 
// adds a new node to the beggining of a list passed as parameters
node* add_first(node* temp, int data){ 
    node *new = malloc(sizeof(node));       // allocate memory for the element we are creating
    if (new == NULL)                        // if unsuccessful
    {
        return NULL;                        // return null
    }
    
    new->number = data;               // set the value of the node's number to the given number through paramenters
    new->next = temp;                 // the next node of this element should be the pointer to the list (or more accuretly to its first node)
    new->prev = NULL;                 // since there are no nodes before it, its previous points to null
    temp = new;                       // the pointer of the list points to this new element since it's its first element 
    return temp;                      // return the list
} 