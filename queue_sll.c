#include<stdio.h>
#include<malloc.h>
struct node {
    int data;
    struct node *next;
};
struct node *front=NULL,*rear=NULL;
void insert(struct node *rear);
int delete(struct node *front);
void display(struct node *front);

void main(){
    int choice;
    printf("Enter:\n1)Insert \n2)Delete \n3)Display \n4)Exit\n");
    printf("Enter your choice :");
    scanf("%d",&choice);
    do{
        switch(choice){
            case 1:{
                insert(rear);
                break;
            }
            case 2:{
                int temp=delete(front);
                if(temp!=-1){
                    printf("Deleted element is %d\n",temp);
                    break;
                }
                break;
            }
            case 3:{
                display(front);
                break;
            }
        }
    printf("Enter your choice :");
    scanf("%d",&choice);
    }while(choice!=4);
}

void insert(struct node *rear){
    int num;
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data to be inserted :");
    scanf("%d",&num);
    newnode->data=num;
    newnode->next=NULL;
    rear->next=newnode;
    rear=newnode;
}

int delete(struct node *front){
    if(front==NULL){
        printf("Queue is empty\n");
        return -1;
    }
    struct node *ptr=front;
    int n=ptr->data;
    front=front->next;
    free(ptr);
    return n;
}

void display(struct node *front){
    if(front==NULL){
        printf("Queue is empty\n");
        return;
    }
    struct node *ptr=front;
    printf("The queue is :");
    while(ptr!=NULL){
        printf("%d, ",ptr->data);
        ptr=ptr->next;
    }
    return;
}