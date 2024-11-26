#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node *next;
};
struct node *start1=NULL;
struct node *start2=NULL;
struct node *create_ll(struct node *);
struct node *reverse(struct node *);
struct node *concantanate(struct node *S1,struct node *S2);
struct node *sort(struct node *);
void display(struct node *);
void main(){
    int choice;
    struct node *start;
    printf("1)create linked list\n2)reverse list\n3)concantanate list\n4)sort list\n5)display list\n6)delete the ll\n7)exit\n");
    printf("enter your choice:");
    scanf("%d",&choice);
    do{
        switch(choice){
            case 1:{
                printf("create first list:\n");
                start1=create_ll(start1);
                printf("create second list:\n");
                start2=create_ll(start2);
                break;
            }
            case 2:{
                printf("reverse first list:");
                start=reverse(start1);
                display(start);
                break;
            }
            case 3:{
                start=concantanate(start1,start2);
                printf("the concantanated list:");
                display(start);
                break;
            }
            case 4:{
                printf("sort first list:");
                start=sort(start1);
                display(start);
                break;
            }
            case 5:{
                printf("display first list :");
                display(start1);
                printf("display second list :");
                display(start2);
                break;
            }
            case 6:{
                printf("deleate the linked list.\n");
                start1=NULL;
                start2=NULL;
                break;
            }
        }
        printf("enter your choice:");
        scanf("%d",&choice);
    }while(choice!=7);
}

struct node *create_ll(struct node *start){
    int num;
    printf("Enter -1 to end.\n");
    printf("Enter the value of nood:");
    scanf("%d",&num);
    while(num!=-1){
        struct node *new_node=(struct node *)malloc(sizeof(struct node));
        new_node->data=num;
        new_node->next=NULL;
        if(start==NULL){
            start=new_node;
        }
        else{
            struct node *ptr=start;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=new_node;
        }
        printf("Enter the value of nood:");
        scanf("%d",&num);
    }
    return start;
}

struct node *reverse(struct node *start){
    struct node *ptr, *start3;
    ptr=start;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    start3=ptr;
    while(start->next!=NULL){
        ptr=start;
        while((ptr->next)->next!=NULL){
            ptr=ptr->next;
        }
        (ptr->next)->next=ptr;
        ptr->next=NULL;
    }
    start1=start3;
    return start3;
}

struct node *concantanate(struct node *S1,struct node *S2){
    if(S1==NULL){
        return S2;
    }
    if(S2==NULL){
        return S1;
    }
    struct node *ptr=S1;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=S2;
    return S1;
}

struct node *sort(struct node *start){
    struct node *ptr1,*ptr2;
    int temp;
    ptr1=start;
    while(ptr1!=NULL){
        ptr2 = ptr1->next;
        while(ptr2!=NULL){
            if(ptr1->data>ptr2->data){
                temp=ptr1->data;
                ptr1->data=ptr2->data;
                ptr2->data=temp;
            }
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
    return start;
}

void display(struct node *start){
    if(start==NULL){
        printf("List is empty.\n");
        return;
    }
    struct node *ptr;
    ptr=start;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}