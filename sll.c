#include <stdio.h>
#include <malloc.h>
struct node{
    int data;
    struct node *next;
};
struct node *start=NULL;
struct node *creat_ll(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_at(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_at(struct node *);
void delete(struct node *);

int main(){
    int choice;
    printf("\n1. Create Linked List\n2. Insert at Beginning\n3. Insert at End\n4. Insert at Position\n5. Delete from Beginning\n6. Delete from End\n7. Delete from Position\n8. Display Linked List\n9. Exit\n");
    do{
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:{start=creat_ll(start);
            break;
            }
            case 2:{start=insert_beg(start);
            break;
            }
            case 3:{start=insert_end(start);
            break;
            }
            case 4:{start=insert_at(start);
            break;
            }
            case 5:{start=delete_beg(start);
            break;
            }
            case 6:{start=delete_end(start);
            break;
            }
            case 7:{start=delete_at(start);
            break;
            }
            case 8:{display(start);
            break;
            }
        }
    }while(choice!=9);
}

struct node *creat_ll(struct node *start){
    int num;
    printf("Enter -1 to end.");
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
struct node *insert_beg(struct node *start){
    int num;
    printf("Enter the value to insert at beginning:");
    scanf("%d",&num);
    struct node *new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=num;
    new_node->next=start;
    start=new_node;
    return start;
}

struct node *insert_end(struct node *start){
    int num;
    printf("Enter the value to insert at end:");
    scanf("%d",&num);
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
    return start;
}

struct node *insert_at(struct node *start){
    int num,pos;
    printf("Enter the value to insert:");
    scanf("%d",&num);
    printf("Enter the position to insert:");
    scanf("%d",&pos);
    if(pos==0){
        start=insert_beg(start);
    }
    else{
        struct node *new_node=(struct node *)malloc(sizeof(struct node));
        new_node->data=num;
        new_node->next=NULL;
        struct node *ptr=start;
        for(int i=0;i<pos-1;i++){
            if(ptr==NULL){
                printf("Position out of range.");
                return start;
            }
            ptr=ptr->next;
        }
        new_node->next=ptr->next;
        ptr->next=new_node;
    }
    return start;
}

struct node *delete_beg(struct node *start){
    if(start==NULL){
        printf("List is empty.");
        return start;
    }
    struct node *ptr=start;
    start=start->next;
    printf("Deleted node is: %d\n",ptr->data);
    free(ptr);
    return start;
}

struct node *delete_end(struct node *start){
    if(start==NULL){
        printf("List is empty.");
        return start;
    }
    struct node *ptr=start;
    if(ptr->next==NULL){
        start=NULL;
        printf("Deleted node is: %d\n",ptr->data);
        free(ptr);
        return start;
    }
    while(ptr->next->next!=NULL){
        ptr=ptr->next;
    }
    struct node *temp=ptr->next;
    ptr->next=NULL;
    printf("Deleted node is: %d\n",temp->data);
    free(temp);
    return start;
}

struct node *delete_at(struct node *start){
    int pos;
    printf("Enter the position to delete:");
    scanf("%d",&pos);
    if(pos==0){
        start=delete_beg(start);
    }
    else{
        struct node *ptr=start;
        for(int i=0;i<pos-1;i++){
            if(ptr==NULL || ptr->next==NULL){
                printf("Position out of range.");
                return start;
            }
            ptr=ptr->next;
        }
        struct node *temp=ptr->next;
        ptr->next=ptr->next->next;
        printf("Deleted node is: %d\n",temp->data);
        free(temp);
        return start;
    }
    return start;
}

void display(struct node *start){
    struct node *ptr=start;
    if(ptr==NULL){
        printf("List is empty.");
        return;
    }
    printf("List is: ");
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

