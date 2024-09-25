#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
};

struct node* head = NULL;

// Circular Doubly Linked List Insertion at Front
void InsertFol() {
    struct node* new;
    int element;
    new = (struct node*)malloc(sizeof(struct node));
    if (new == NULL) {
        printf("Memory is not allocated\n");
        return;
    }

    printf("Enter the element to be inserted in front of the list: ");
    scanf("%d", &element);
    new->data = element;

    if (head == NULL) {
        head = new;
        new->prev = new;
        new->next = new;
    } else {
        new->next = head;
        new->prev = head->prev;
        head->prev->next = new;
        head->prev = new;
        head = new;
    }
}

// Circular Doubly Linked List Insertion at Last Position
void InsertEol() {
    struct node* new;
    int element;
    new = (struct node*)malloc(sizeof(struct node));
    if (new == NULL) {
        printf("Memory is not allocated properly\n");
        return;
    }

    printf("Enter the element to be inserted at the end of the list: ");
    scanf("%d", &element);
    new->data = element;

    if (head == NULL) {
        head = new;
        new->prev = new;
        new->next = new;
    } else {
        new->next = head;
        new->prev = head->prev;
        head->prev->next = new;
        head->prev = new;
    }
}

// Circular Doubly Linked List Insertion at Middle Position
void InsertMol() {
    struct node* new, *temp;
    int element, position, i;
    new = (struct node*)malloc(sizeof(struct node));
    if (new == NULL) {
        printf("Memory is not allocated\n");
        return;
    }

    printf("Enter the position to insert the element: ");
    scanf("%d", &position);
    printf("Enter the element to insert at position %d: ", position);
    scanf("%d", &element);
    new->data = element;

    if (position == 1) {
        InsertFol();
    } else {
        temp = head;
        for (i = 2; i < position && temp->next != head; i++) {
            temp = temp->next;
        }
        if (temp->next != head || i == position) {
            new->next = temp->next;
            new->prev = temp;
            temp->next->prev = new;
            temp->next = new;
        } else {
            printf("Invalid position\n");
        }
    }
}

// Circular Doubly Linked List Deletion at Front
void DeleteFol() {
    struct node* temp;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        temp = head;
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;
        free(temp);
    }
}

// Circular Doubly Linked List Deletion at Last Position
void DeleteEol() {
    struct node* temp;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        temp = head->prev;
        temp->prev->next = head;
        head->prev = temp->prev;
        free(temp);
    }
}

// Circular Doubly Linked List Deletion at Middle Position
void DeleteMol() {
    struct node* temp, *prev;
    int position, i;

    printf("Enter the position to delete the element: ");
    scanf("%d", &position);

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (position == 1) {
        DeleteFol();
    } else {
        temp = head;
        for (i = 2; i <= position && temp->next != head; i++) {
            prev = temp;
            temp = temp->next;
        }
        if (temp != head && i == position) {
            prev->next = temp->next;
            temp->next->prev = prev;
            free(temp);
        } else {
            printf("Invalid position\n");
        }
    }
}

// Circular Doubly Linked List Search
void Search() {
    struct node* temp;
    int element, count = 1, flag = 0;

    printf("Enter the element to search: ");
    scanf("%d", &element);

    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }

    temp = head;
    do {
        if (temp->data == element) {
            flag = 1;
            break;
        }
        temp = temp->next;
        count++;
    } while (temp != head);

    if (flag == 1) {
        printf("The searched element is present at position %d\n", count);
    } else {
        printf("The searched element is not present in the list\n");
    }
}

// Circular Doubly Linked List Display
void display() {
    struct node* temp;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    int choice;
    do {
        printf("\nCircular Doubly Linked List Operations:\n");
        printf("1. Insert at Front\n2. Insert at End\n3. Insert at Position\n4. Delete at Front\n5. Delete at End\n6. Delete at Position\n7. Search\n8. Display\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            InsertFol();
            break;
        case 2:
            InsertEol();
            break;
        case 3:
            InsertMol();
            break;
        case 4:
            DeleteFol();
            break;
        case 5:
            DeleteEol();
            break;
        case 6:
            DeleteMol();
            break;
        case 7:
            Search();
            break;
        case 8:
            display();
            break;
        case 9:
            printf("Exiting program\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 9);

    return 0;
}