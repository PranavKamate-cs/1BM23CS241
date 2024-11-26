#include <stdio.h>
#include <stdlib.h>

struct node {
    int spot;
    int status; // 0 for empty, 1 for occupied
    struct node *next;
};

struct node *create_parking(struct node *B, int total_spots);
struct node *park(struct node *B, int n);
struct node *depart(struct node *B, int n);
int count_empty(struct node *B);

void main() {
    struct node *B1 = NULL;
    struct node *B2 = NULL;

    // Create two basements with 25 spots each
    B1 = create_parking(B1, 25);
    B2 = create_parking(B2, 25);

    int choice, n, b;

    printf("Enter:\n1) Park\n2) Depart\n3) Count empty spots\n4) Exit\n");
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the basement number (1 or 2): ");
                scanf("%d", &b);
                printf("Enter the slot number (1 to 25): ");
                scanf("%d", &n);
                if (b == 1) {
                    B1 = park(B1, n);
                } else if (b == 2) {
                    B2 = park(B2, n);
                } else {
                    printf("Invalid basement number!\n");
                }
                break;

            case 2:
                printf("Enter the basement number (1 or 2): ");
                scanf("%d", &b);
                printf("Enter the slot number (1 to 25): ");
                scanf("%d", &n);
                if (b == 1) {
                    B1 = depart(B1, n);
                } else if (b == 2) {
                    B2 = depart(B2, n);
                } else {
                    printf("Invalid basement number!\n");
                }
                break;

            case 3:
                printf("The total number of empty parking slots = %d\n", count_empty(B1) + count_empty(B2));
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 4);

    return ;
}

struct node *create_parking(struct node *B, int total_spots) {
    struct node *ptr = NULL, *temp = NULL;
    for (int i = 1; i <= total_spots; i++) {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->spot = i;
        new_node->status = 0; // Initially all spots are empty
        new_node->next = NULL;

        if (B == NULL) {
            B = new_node;
        } else {
            ptr->next = new_node;
        }
        ptr = new_node;
    }
    return B;
}

struct node *park(struct node *B, int n) {
    struct node *ptr = B;
    while (ptr != NULL && ptr->spot != n) {
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        printf("Invalid slot number!\n");
        return B;
    }
    if (ptr->status == 1) {
        printf("The slot is already occupied!\n");
        return B;
    }
    ptr->status = 1;
    printf("Parking done at slot %d\n", n);
    return B;
}

struct node *depart(struct node *B, int n) {
    struct node *ptr = B;
    while (ptr != NULL && ptr->spot != n) {
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        printf("Invalid slot number!\n");
        return B;
    }
    if (ptr->status == 0) {
        printf("The slot is already empty!\n");
        return B;
    }
    ptr->status = 0;
    printf("Slot %d is now free.\n", n);
    return B;
}

int count_empty(struct node *B) {
    int count = 0;
    struct node *ptr = B;
    while (ptr != NULL) {
        if (ptr->status == 0) {
            count++;
        }
        ptr = ptr->next;
    }
    return count;
}
