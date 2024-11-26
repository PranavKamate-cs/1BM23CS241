#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node *next;
};
struct node *top=NULL;
void push();
int pop(struct node *top);
void display(struct node *top);

void main(){
    int choice;
    printf("Enter:\n1)Push \n2)Pop \n3)Display \n4)Exit\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    do{
        switch(choice){
            case 1:{
                push();
                break;
            }
            case 2:{
                int n=pop(top);
                if(n!=-1){
                    printf("The poped element =%d\n",n);
                }
                break;
            }
            case 3:{
                display(top);
                break;
            }
        }
    printf("Enter your choice:");
    scanf("%d",&choice);
    }while(choice!=4);
}

void push(){
    int num;
    printf("Enter the element to push:");
    scanf("%d",&num);
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=top;
    top=newnode;
}

int pop(struct node *top){
    if(top==NULL){
        printf("the stack is empty!!\n");
        return -1;
    }
    struct node *ptr=top;
    int a=top->data;
    top=top->next;
    free(ptr);
    return a;
}

void display(struct node *top){
    if(top==NULL){
        printf("the stack is empty!!\n");
        return;
    }
    struct node *ptr=top;
    printf("The stack is : ");
    while(ptr!=NULL){
        printf("%d, ",ptr->data);
        ptr=ptr->next;
    }
    return;
}