#include <stdio.h>

#define SIZE 10 // m = number of memory locations

int hashTable[SIZE];

/* Function to initialize hash table */
void initialize() {
    int i;
    for (i = 0; i < SIZE; i++) {
        hashTable[i] = -1; // -1 means empty
    }
}

/* Hash function */
int hashFunction(int key) {
    return key % SIZE; // H(K) = K mod m
}

/* Insert key using Linear Probing */
void insert(int key) {
    int index = hashFunction(key);

    // Linear probing in case of collision
    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
    }

    hashTable[index] = key;
}

/* Display hash table */
void display() {
    int i;
    printf("\nHash Table:\n");
    for (i = 0; i < SIZE; i++) {
        if (hashTable[i] == -1)
            printf("Index %d : Empty\n", i);
        else
            printf("Index %d : %d\n", i, hashTable[i]);
    }
}

int main() {
    int n, key, i;

    initialize();

    printf("Enter number of employee records: ");
    scanf("%d", &n);

    printf("Enter employee keys:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(key);
    }

    display();

    return 0;
}
