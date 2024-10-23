#include<stdio.h>
# define MAX 3
int q[MAX],front=-1,rear=-1,val;
void insert(int val);
int delete();
void newqueue();
void display();

void main(){
    int n=0;
    printf("1-> Insert\n2->Delete\n3->Display\n4->New Queue\n5->Exit\n");
    while(n!=5){
        printf("\nEnter your choise:");
        scanf("%d",&n);
        printf("\n");
        switch (n)
        {
            case 1:{
                printf("Enter the number to be inserted:");
                scanf("%d",&val);
                printf("\n");
                insert(val);
                break;
            }
            case 2:{
                val=delete();
                if (val!=-1){
                    printf("The deleted element is:%d\n\n",val);
                }
                break;
            }
            case 3:{
                display();
                break;
            }
            case 4:{
                newqueue();
                printf("New queue is created.\n");
                break;
            }
            case 5:{
                printf("Exiting...\n");
                break;
            }
            default:{
                printf("Wrong option!!\n");
            }
        }

    }
}
void insert(int val){
    if (front==-1&&rear==-1){
        front=0;
        rear=0;
        q[rear]=val;
        return;
    }
    else if(rear==MAX-1){
        printf("The Queue is full.\n");
        return;
    }
    else{
        q[++rear]=val;
        return;
    }
}
int delete(){
    if(front==-1||front>rear){
        printf("The queue is empty.\n");
        return -1;
    }
    else{
        val=q[front++];
    }
}
void newqueue(){
    rear=-1;
    front=-1;
    return;
}
void display(){
    if(rear==-1||front>rear){
        printf("Queue is empty.\n");
    }
    else{
        printf("The queue is:");
        for(int i=front;i<=rear;i++){
            printf("%d ",q[i]);
        }
        printf("\n\n");
    }
}
