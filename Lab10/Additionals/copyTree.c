#include <stdio.h>
#include <stdlib.h>

typedef struct tnode {
    struct tnode* llink;
    struct tnode* rlink;
    int data;
} tnode;

tnode* createNode(int value) {
    tnode* newNode = (tnode*)malloc(sizeof(tnode));
    newNode->data = value;
    newNode->llink = NULL;
    newNode->rlink = NULL;
    return newNode;
}

tnode* copyTree(tnode* root) {
    if (root == NULL) {
        return NULL;
    }
    tnode* newNode = createNode(root->data);
    newNode->llink = copyTree(root->llink);
    newNode->rlink = copyTree(root->rlink);
    return newNode;
}

void printTree(tnode* root) {
    if (root == NULL) {
        return;
    }
    printTree(root->llink);
    printf("%d ", root->data);
    printTree(root->rlink);
}

int main() {
    tnode* originalTree = createNode(1);
    originalTree->llink = createNode(2);
    originalTree->rlink = createNode(3);
    originalTree->llink->llink = createNode(4);
    originalTree->llink->rlink = createNode(5);

    tnode* copiedTree = copyTree(originalTree);

    printf("In-Order Traversal of Original Tree: ");
    printTree(originalTree);
    printf("\n");

    printf("In-Order Traversal of Copied Tree: ");
    printTree(copiedTree);
    printf("\n");

    return 0;
}
