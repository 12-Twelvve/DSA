#include<iostream>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node NODE;
NODE *start;

void createemptylist(NODE *start){
    start = (NODE *)malloc(sizeof(NODE)); //start =null
}

void insert_at_begin(int item){
    NODE *ptr;
    ptr = (NODE *)malloc(sizeof(NODE));
    ptr->data = item;
    if(start ==(NODE *)NULL){
        ptr->next = (NODE *)NULL;
    }else{
        ptr->next= start;
    }
    start = ptr;
}

void insert_at_end(int item){
    NODE *ptr, *loc;
    ptr = (NODE *)malloc(sizeof(NODE));
    ptr->data = item;
    ptr->next = NULL;
    if(start== NULL){
        start = ptr;
    }
    else{
        loc = start;
        while(loc->next != (NODE *)NULL){
            loc=loc->next;
        }
        loc->next = ptr;
    }
}

void insert_spe(int item, int pos){
    NODE *ptr, *loc;
    int i;
    loc = start;
    ptr= (NODE *) malloc(sizeof(NODE));
    ptr->data = item;
    // finding the position to add new element to the linked list 
    for(i=1; i<pos-1; i++){
        loc = loc->next;
        if(loc ==NULL){
            printf("\n\n there are less than %d elements", pos);
            return;
        }
    }
    ptr->next = loc->next;
    loc->next = ptr;
}

// this function will display all the elements inthe linked list 
void Traverse(NODE *start){
    NODE *temp;
    if(start ==NULL){
        printf("List is empty !\n");
        return;
    }
    else{
        temp = start;
        while(temp!=NULL){
            printf("\n%d\t", temp->data);
            temp=temp->next;
        }
    }
}

void DeleteElement(int item){
    NODE *ptr, *loc;
    if(start->data ==item){
        ptr = start;
        start = start->next;
        free(ptr);
        return;
    }
    loc = start;
    while(loc->next->next != NULL ){
        if(loc->next->data==item){
            ptr = loc->next;
            loc->next = ptr->next;
            free(ptr);
            return;
        }
        loc = loc->next;
    }
    if(loc->next->data ==item){
        ptr = loc->next;
        free(ptr);
        loc->next = NULL;
        return;
    }
    printf("\n\nelement %d not found", item);
}

void SearchElement(int item){
    NODE *ptr= start;
    int pos = 1;
    while(ptr != NULL){
        if(ptr->data==item){
            printf("\n Item %d found at position %d", item, pos);
            return;
        }
        ptr= ptr->next;
        pos++;
    }
    if(ptr==NULL){
        printf(" element! %d not found",item);
    }
}

int main(){
    int choice, item, pos;
    createemptylist(start);

    while(1){
        printf("\n1. insert at begining ");
        printf("\n2. insert at element at end position ");
        printf("\n3. insert at specific position ");
        printf("\n4. traveser all the queue in order ");
        printf("\n5. delete any element ");
        printf("\n6. search any element");
        printf("\n9. quit ");
        printf("\nenter your choice : ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                printf("enter the item to insert : ");
                scanf("%d",&item);
                insert_at_begin(item);
                break;
            case 2:
                printf("enter the item to insert : ");
                scanf("%d",&item);
                insert_at_end(item);
                break;
            case 3:
                printf("enter the item to insert : ");
                scanf("%d",&item);
                printf("enter the position to insert : ");
                scanf("%d",&pos);
                insert_spe(item, pos);
                break;
            case 4:
                Traverse(start);
                break;
            case 5:
                printf("enter the elment to delete : ");
                scanf("%d",&item);
                DeleteElement(item);
                break;
            case 6:
                printf("enter the element to search : ");
                scanf("%d",&item);
                SearchElement(item);
            case 9:
                exit(0);
            default:
                printf("invalid input !");
                break;
        }
    }
}
