#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    struct Node* head;
} LL;

void initList(LL* list) {
    list->head = NULL;
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void appendNode(LL* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void mergeLists(LL* list1, LL* list2, LL* list3) {
    initList(list3);
    Node* temp1 = list1->head;
    Node* temp2 = list2->head;
    
    while (temp1 != NULL && temp2 != NULL) {
        // Append from list1
        appendNode(list3, temp1->data);
        temp1 = temp1->next;

        // Append from list2
        appendNode(list3, temp2->data);
        temp2 = temp2->next;
    }
    
    // If list1 still has remaining nodes
    while (temp1 != NULL) {
        appendNode(list3, temp1->data);
        temp1 = temp1->next;
    }
    
    // If list2 still has remaining nodes
    while (temp2 != NULL) {
        appendNode(list3, temp2->data);
        temp2 = temp2->next;
    }
}

void printList(LL* list) {
    Node* temp = list->head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    LL list1, list2, list3;

    initList(&list1);
    initList(&list2);
    
    appendNode(&list1, 1);
    appendNode(&list1, 3);
    appendNode(&list1, 5);

    appendNode(&list2, 2);
    appendNode(&list2, 4);
    appendNode(&list2, 6);

    mergeLists(&list1, &list2, &list3);

    printf("Merged List: ");
    printList(&list3);

    return 0;
}
