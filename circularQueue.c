#include<stdio.h>
#include<stdlib.h>
# define SIZE 5
int front=-1,rear=-1,val;
int queue[SIZE];
void enqueue(int i);
int dequeue();
void display();
int isfull(){
    if(front==(rear+1)%SIZE){
        printf("Queue is full.\n\n");
        return 1;
    }
    return 0;
}
int isempty(){
    if(front==-1&&rear==-1){
        printf("Queue is empty.\n\n");
        return 1;
    }
    return 0;
}
void main(){
    int choice=0;
    printf("\n1->Insert\n2->Delete\n3->Display\n4->Exit\n");
    while(choice!=4){
        printf("Enter your choice:");
        scanf("%d",&choice);
        printf("\n");
        switch(choice){
            case 1:{
                printf("Enter the number to insert:");
                scanf("%d",&val);
                printf("\n\n");
                enqueue(val);
                break;
            }
            case 2:{
                val=dequeue();
                if(val==-1){
                    break;
                }
                else{
                    printf("The deleated element is:%d\n\n",val);
                    break;
                }
            }
            case 3:{
                display();
                break;
            }
            case 4:{printf("******Exit*******");
                break;
                }

            default:printf("Invalid choice!!\n\n");
        }
    }
}
void enqueue(int i){
    if(isfull()){
        return;
    }
    else if(front==-1&&rear==-1){
        front=0;
        rear=0;
        queue[rear]=i;
        return;
    }
    else{
        rear=(rear+1)%SIZE;
        queue[rear]=val;
        return;
    }
}
int dequeue(){
    if(isempty()){
        return -1;
    }
    else{
        val=queue[front];
        if(front==rear){
            rear=-1;
            front=-1;
        }
        else{
            front=(front+1)%SIZE;
        }
        return val;
    }
}
void display(){
    if(isempty()){
        return;
    }
    else{
        int i;
        printf("The queue is:");
        for(i=front;i!=rear;i=(i+1)%SIZE){
            printf("%d  ",queue[i]);
        }
        printf("%d\n\n",queue[i]);
        return;
    }
}
