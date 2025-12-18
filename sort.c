#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

/* Create a new node */
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/* Insert at end */
struct node* insertEnd(struct node* head, int data) {
    struct node* temp = createNode(data);
    if (head == NULL)
        return temp;

    struct node* curr = head;
    while (curr->next != NULL)
        curr = curr->next;

    curr->next = temp;
    return head;
}

/* Display list */
void display(struct node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

/* Reverse linked list */
struct node* reverse(struct node* head) {
    struct node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

/* Sort linked list (Bubble Sort) */
struct node* sort(struct node* head) {
    struct node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    return head;
}

/* Concatenate two linked lists */
struct node* concatenate(struct node* head1, struct node* head2) {
    if (head1 == NULL)
        return head2;

    struct node* temp = head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    return head1;
}

/* Main function */
int main() {
    struct node *list1 = NULL, *list2 = NULL;

    list1 = insertEnd(list1, 3);
    list1 = insertEnd(list1, 1);
    list1 = insertEnd(list1, 5);

    list2 = insertEnd(list2, 4);
    list2 = insertEnd(list2, 2);

    printf("List 1: ");
    display(list1);

    printf("List 2: ");
    display(list2);

    list1 = sort(list1);
    printf("Sorted List 1: ");
    display(list1);

    list1 = reverse(list1);
    printf("Reversed List 1: ");
    display(list1);

    list1 = concatenate(list1, list2);
    printf("Concatenated List: ");
    display(list1);

    return 0;
}
