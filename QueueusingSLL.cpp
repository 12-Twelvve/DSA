// a structure is created for the node in queue 
#include<iostream>
#include<stdlib.h>
#include<stdio.h>

struct queue{
    int data;
    struct queue *next;
};
typedef struct queue *NODE;

// enqueue
NODE Enqueue(NODE rear){
    NODE newnode;
    newnode = (NODE) malloc(sizeof(NODE));
    printf("\n Enter the no. to be pushed ");
    scanf("%d", &newnode->data);
    newnode->next =NULL;
    // setting the rear pointer 
    if(rear != NULL){
        rear->next = newnode;
    }
    rear = newnode;
    return (rear);
}
NODE Dequeue(NODE f, NODE r){
    if(f==NULL){
        printf("\n The Queue is empty");
    }else{
        printf("\n The poped element is = %d",f->data);
        if(f!=r){
            f= f->next;
        }else{
            f = NULL;
        }
    }
    return f;
}

void Traverse(NODE fr, NODE re){
    if(fr ==NULL){
        printf("\n The queue is empty ");
    }
    else{
        printf("\n the element are: ");
        while(fr != re){
            printf("%d\n", fr->data);
            fr=fr->next;
        }
        printf("%d\n",fr->data);
    }
}
int main(){
    int choice ;
    NODE front , rear;
    front = rear = NULL;
    while(1){
        printf("\n1.Enqueue");
        printf("\n2.DEqueue");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nenter your choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1 :
                rear = Enqueue(rear);
                if(front==NULL){
                    front=rear;
                }
                break;
            case 2 :
                front =Dequeue(front, rear);
                if(front == NULL){
                    rear = front;
                } 
                break;
            case 3 :
                Traverse(front, rear);
                break;
            case 4:
                exit(1);
            default:
                printf("invalid choice ");
        }
    }
}