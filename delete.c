#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to display the linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to delete from front
struct Node* deleteFront(struct Node* head) {
    if (head == NULL) {
        printf("List is empty, cannot delete.\n");
        return head;
    }
    struct Node* temp = head;
    head = head->next;
    printf("Deleted element from front: %d\n", temp->data);
    free(temp);
    return head;
}

// Function to delete from end
struct Node* deleteEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty, cannot delete.\n");
        return head;
    }
    if (head->next == NULL) { // Only one node
        printf("Deleted element from end: %d\n", head->data);
        free(head);
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    printf("Deleted element from end: %d\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
    return head;
}

// Function to delete from any position
struct Node* deleteAtPosition(struct Node* head, int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    if (pos == 1) {
        return deleteFront(head);
    }

    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Position out of range.\n");
        return head;
    }

    struct Node* delNode = temp->next;
    temp->next = delNode->next;
    printf("Deleted element at position %d: %d\n", pos, delNode->data);
    free(delNode);

    return head;
}

int main() {
    struct Node* head = NULL;

    // Creating a sample list: 10 -> 20 -> 30 -> 40 -> NULL
    head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);

    display(head);

    // Delete from front
    head = deleteFront(head);
    display(head);

    // Delete from end
    head = deleteEnd(head);
    display(head);

    // Delete from position (2nd position)
    head = deleteAtPosition(head, 2);
    display(head);

    return 0;
}
