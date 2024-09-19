#include <stdio.h>
#include <stdlib.h>

typedef struct DoubleLLNode {
    int data;
    struct DoubleLLNode* rlink;
    struct DoubleLLNode* llink;
} Node;

typedef struct DoublyLinkedList {
    Node* head;
} DLL;


void initList(DLL* list);
Node* createNode(int data);
void insertRear(int data, DLL* list);
void printList(DLL* list);
void concatenateLists(DLL* X1, DLL* X2);

int main() {
    DLL X1, X2;
    initList(&X1);
    initList(&X2);

    insertRear(1, &X1);
    insertRear(2, &X1);
    insertRear(3, &X1);

    insertRear(4, &X2);
    insertRear(5, &X2);
    insertRear(6, &X2);

    concatenateLists(&X1, &X2);

    printf("Concatenated List: ");
    printList(&X1);

    return 0;
}

void initList(DLL* list) {
    list->head = NULL;
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->llink = newNode->rlink = NULL;
    return newNode;
}

void insertRear(int data, DLL* list) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* temp = list->head;
        while (temp->rlink != NULL) {
            temp = temp->rlink;
        }
        temp->rlink = newNode;
        newNode->llink = temp;
    }
}

void printList(DLL* list) {
    Node* temp = list->head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->rlink;
    }
    printf("\n");
}

void concatenateLists(DLL* X1, DLL* X2) {
    if (X1->head == NULL) {
        X1->head = X2->head;
        return;
    }
    if (X2->head == NULL) {
        return;
    }

    Node* lastNodeX1 = X1->head;
    while (lastNodeX1->rlink != NULL) {
        lastNodeX1 = lastNodeX1->rlink;
    }

    lastNodeX1->rlink = X2->head;
    X2->head->llink = lastNodeX1;
}
