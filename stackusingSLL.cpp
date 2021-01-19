#include<iostream>
#include<stdio.h>
#include<stdlib.h>
// structure is created a node
struct node{
    int data;
    struct node *next;
};
// a variable named node is been defined for the structure 
typedef struct node *NODE;

// this function is to perform the push operation
NODE push(NODE top){
    NODE newnode;
    int pushed_item;
    // a new node is created dynamically
    newnode = (NODE) malloc(sizeof(NODE));
    printf("\n input the new value to be pushed on the stack :");
    scanf("%d", &pushed_item);
    newnode->data = pushed_item;
    newnode->next = top;
    top = newnode;
    return(top);
}

NODE pop(NODE top){
    NODE temp;
    if(top==NULL){
        printf("stack is empty");
    }
    else{
        temp = top;
        printf("\npoped element is %d", temp->data);
        top=top->next;
        free(temp);
    }
    return(top);
}

void display(NODE top){
    NODE tmp;
    if(top ==NULL){
        printf("\n Stack is empty !");
    }else{
        tmp = top;
        printf("stack elements are : \n ");
        while(tmp!=NULL){
            printf("%d\n", tmp->data);
            tmp =tmp->next;
        }
    }
}

int main(){
    char opt;
    int choice;
    NODE top =NULL;
    while(1){
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. DISPLAY");
        printf("\n4. EXIT");
        printf("\n Enter the choice :");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                top =push(top);
                break;
            case 2:
                top = pop(top);
                break;  
            case 3 :
                display(top);
                break;
            case 4:
                exit(1);
            default:
                printf("invalid choice");
        }
    }
}