// program to implement QUEUE using arrays
#include<iostream>
#include<stdlib.h>

#define MAX 50

int queue_arr[MAX];
int rear = -1;
int front = -1;

// this function will insert an element to the queue
void Enqueue(){
    int added_item;
    if(rear == MAX-1){
        printf("Queue is full !");
        return;
    }
    else{
        if(front == -1) //if queue is initially empty 
        {
            printf("queue is empty you are going to create an queue .");
            front = 0;
        }
        printf("\nEnter the element for adding in queue : ");
        scanf("%d", &added_item);
        rear = rear + 1;
        queue_arr[rear] = added_item;
    }
}

// This function will delete an element from the queue
void Dequeue(){
    if(front == -1){//or rear == -1
        printf("Queue is empty !\n");
        return;
    }
    else{
        if(front==rear){
            printf("\npoping only element is %d\n ", queue_arr[front]);
            front= -1;
            rear = -1;
        }
        else{
            printf("\npoping element is : %d\n ", queue_arr[front]);
            front+=1;
        }
    }
}
// This function will show all the element from the queue
void Traverse(){
    if(front == -1){
        printf("Queue is EMpty !");
        return ;
    }
    else{
        printf("\nThe queue element are as follows : \n");
        for(int i=front ; i<=rear ;i++){
            printf("%d\t", queue_arr[i]);
        }
    }
}
// main funtion

int main(){
    int choice;
    while(1){
        // menu options
        printf("\n1. Enqueue\n");
        printf("\n2. Dequeue\n");
        printf("\n3. Traverse\n");
        printf("\n4. Size\n");
        printf("\n5. Quit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                Enqueue();
                break;
            case 2:
                Dequeue();
                break;
                
            case 3:
                Traverse();
                break;
            case 4:
                printf("the size of Stack is : %d\n", rear-front+1);
                break;
            case 5:
                exit(1);
            default:
                printf("Invalid choice :(");
        }
    }
    return 0;
}
