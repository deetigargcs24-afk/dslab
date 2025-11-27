#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at end (to easily create list)
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Insert a new node to the LEFT of a node with specific value
void insertLeft(struct Node** head, int value, int newData) {
    struct Node* newNode = createNode(newData);

    struct Node* temp = *head;

    // Find the node with the given value
    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value %d not found!\n", value);
        free(newNode);
        return;
    }

    // If inserting to the left of head
    if (temp->prev == NULL) {
        newNode->next = temp;
        temp->prev = newNode;
        *head = newNode;
        return;
    }

    // Normal insertion in the middle
    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    temp->prev = newNode;
}

// Delete node based on value
void deleteValue(struct Node** head, int value) {
    struct Node* temp = *head;

    // Find the node
    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value %d not found!\n", value);
        return;
    }

    // If node is head
    if (temp->prev == NULL) {
        *head = temp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
    }
    // If node is last
    else if (temp->next == NULL) {
        temp->prev->next = NULL;
    }
    // Node in the middle
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Deleted value %d\n", value);
}

// Display list
void display(struct Node* head) {
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Create list
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);

    display(head);

    insertLeft(&head, 30, 25);
    display(head);

    deleteValue(&head, 20);
    display(head);

    return 0;
}
