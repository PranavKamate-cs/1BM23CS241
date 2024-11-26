#include<stdio.h>
#include<malloc.h>
struct node{
    int spot;
    int status;
    struct node *next;
};
struct node *B1=NULL;
struct node *B2=NULL;
struct node *creat_parking(struct node *);
struct node *park(struct node *B,int n);
struct node *depart(struct node *B,int n);
int count_empty(struct node *B);

void main(){
    B1=creat_parking(B1);
    B2=creat_parking(B2);
    int choice,n,b;
    printf("Enter :\n1)Park \n2)Depart \n3)count the empty spot\n4)Exit\n");
    do{
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch (choice){
            case 1:{
                printf("Enter the basement number(1 0r 2):");
                scanf("%d",&b);
                printf("Enter the slot number(1 to 25):");
                scanf("%d",&n);
                if(b==1){
                    B1=park(B1,n);
                }
                else{
                    B2=park(B2,n);
                }
                break;
            }
            case 2:{
                printf("Enter the basement number(1 0r 2):");
                scanf("%d",&b);
                printf("Enter the slot number(1 to 25):");
                scanf("%d",&n);
                if(b==1){
                    B1=depart(B1,n);
                }
                else if(b==2){
                    B2=depart(B2,n);
                }
                break;
            }
            case 3:{
                int c=count_empty(B1)+ count_empty(B2);
                printf("The total number of empty parking slots =%d\n\n",c);
                break;
            }
        }
    }while(choice!=4);
}

struct node *creat_parking(struct node *B){
    struct node *ptr;
    for(int i=0;i<25;i++){
        struct node* new_node=(struct node*)malloc(sizeof(struct node));
        new_node->spot=i+1;
        new_node->status=0;
        new_node->next=NULL;
        if(B==NULL){
            B=new_node;
        } 
        else{
            ptr->next=new_node;
        }
        ptr=new_node;
    }
    return B;
}


struct node *park(struct node *B,int n){
    struct node *ptr=B;
    while(ptr->spot!=n && ptr!=NULL){
        ptr=ptr->next;
    }
    if (ptr == NULL){
        printf("Invalid slot number!\n");
        return B;
    }
    ptr->status=1;
    printf("The parking done at spot=%d\n\n",n);
    return B;
}

struct node *depart(struct node *B,int n){
        struct node *ptr=B;
    while(ptr->spot!=n && ptr!=NULL){
        ptr=ptr->next;
    }
    if (ptr==NULL){
        printf("Invalid slot number!\n");
        return B;
    }
    ptr->status=0;
    printf("The departer done at spot=%d\n\n",n);
    return B;
}

int count_empty(struct node *B){
    int c=0;
    struct node *ptr=B;
    while(ptr!=NULL){
        if(ptr->status==0){
            c++;
        }
        ptr=ptr->next;
    }
    return c;
}
