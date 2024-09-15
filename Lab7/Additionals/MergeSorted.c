#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the List structure
typedef struct List {
    int currentSize;
    Node* head;
} List;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize a list
void initList(List* list) {
    list->currentSize = 0;
    list->head = NULL;
}

// Function to append one list to another
void appendList(List* listA, List* listB) {
    if (listA->head == NULL) {
        listA->head = listB->head;
    } else {
        Node* temp = listA->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = listB->head;
    }
    listA->currentSize += listB->currentSize;
    listB->head = NULL; // Make listB empty after appending
    listB->currentSize = 0;
}

// Function to sort the linked list using Bubble Sort
void bubbleSort(List* list) {
    if (list->head == NULL) return;

    int swapped;
    Node *ptr1;
    Node *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = list->head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                // Swap data of nodes
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Function to print the linked list
void printList(List* list) {
    Node* temp = list->head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    // Initialize lists
    List listX, listY;
    initList(&listX);
    initList(&listY);

    // Create and append nodes to listX
    listX.head = createNode(1);
    listX.head->next = createNode(3);
    listX.head->next->next = createNode(5);
    listX.currentSize = 3;

    // Create and append nodes to listY
    listY.head = createNode(2);
    listY.head->next = createNode(4);
    listY.head->next->next = createNode(6);
    listY.currentSize = 3;

    // Append listY to listX
    appendList(&listX, &listY);

    // Sort the combined list
    bubbleSort(&listX);

    printf("Sorted Merged List: ");
    printList(&listX);

    return 0;
}
