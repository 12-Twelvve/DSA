#include<iostream>
#include<conio.h>

// defining the maximum size of the stack 
#define MAXSIZE 100
// declaring the stack  array and top  variable in a structure
struct stack {
    int stack[MAXSIZE];
    int Top;
};

// type defination alllows the user to define an identifier that would represent
// an existing data type . The user-defined data type identifier can later be used to declare variables.

typedef struct stack NODE;

// this function will add/insert an element to top of the stack

void push(NODE *pu){
    int item;
    // if the top pointer already reached the maximum allowed size then we can say that the  stack is full or overflow
    if(pu->Top == MAXSIZE-1){
        printf("\n The stack is Full");
        exit(0);
    }
    // otherwise an element can be added or inserted by increasing the stack pointer top as follows
    else{
        printf("Enter the Element to be inserted : ");
        scanf("%d", &item);
        pu->stack[++pu->Top]= item;
    }
}

// this function will delete an element from top of the stack 
void pop(NODE *pop){
    int item;
    // if the top pointer points to NULL , then the stack is empty that is NO elment is there in the stack to delete or pop
    if(pop->Top == -1){
        printf("stact is empty ");
        exit(0);
    }
    // otherwise top element is pop out and top element is decremented
    else{
        item = pop->stack[pop->Top--];
        printf("\nThe deleted Element is : %d", item);
    }
}

// this function to print all the existing elements in the stack 
void traverse(NODE *pt){
    int i ;
    // if the top pointer poinst to the NULL , then the stack is empty that is no elment is tthere to delete or pop
    if(pt->Top == -1){
        printf("\n the stack is empty");
    }
    // otherwise all the elements are printed;
    else{
        printf("\n\n The elements in the stack(s) are : ");
        for(i=0; i<=pt->Top ; i++){
            printf("\n %d", pt->stack[i]);
        }
    }
}

int main(){
    int choice;
    int check = 1;
    // declaring an pointer variable to the structure
    NODE *ps;
    ps = (NODE * )calloc(100, sizeof(NODE));
    // intitialize the Top pointer to NULL
    ps->Top=-1;
    do{
        // Amenu for the stack operations 
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. TRAVERSE");
        printf("\n Enter your choice = ");
        scanf("%d", &choice);
        switch(choice){
            case 1://calling push function by passing the structure pointer to the function 
                    push(ps);
                    break;
            case 2://calling pop function by passing the structure pointer to the function
                    pop(ps);
                    break;
            case 3://calling traverse function 
                    traverse(ps);
                    break;
            default:
                    printf("\nyou entered invalid input :(");
                    break;
        }
        printf("\npress 1 for continuity and 2 to Exit : ");
        scanf("%d", &check);
    }
    while(check !=2);
    return 0;
}