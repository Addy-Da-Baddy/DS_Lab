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

int areTreesEqual(tnode* tree1, tnode* tree2) {
    if (tree1 == NULL && tree2 == NULL) {
        return 1;
    }
    if (tree1 == NULL || tree2 == NULL) {
        return 0;
    }
    return (tree1->data == tree2->data) &&
           areTreesEqual(tree1->llink, tree2->llink) &&
           areTreesEqual(tree1->rlink, tree2->rlink);
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
    tnode* tree1 = createNode(1);
    tree1->llink = createNode(2);
    tree1->rlink = createNode(3);
    tree1->llink->llink = createNode(4);
    tree1->llink->rlink = createNode(5);

    tnode* tree2 = createNode(1);
    tree2->llink = createNode(2);
    tree2->rlink = createNode(3);
    tree2->llink->llink = createNode(4);
    tree2->llink->rlink = createNode(5);

    tnode* tree3 = createNode(1);
    tree3->llink = createNode(2);
    tree3->rlink = createNode(3);
    tree3->llink->llink = createNode(6);

    if (areTreesEqual(tree1, tree2)) {
        printf("Tree 1 and Tree 2 are equal.\n");
    } else {
        printf("Tree 1 and Tree 2 are not equal.\n");
    }

    if (areTreesEqual(tree1, tree3)) {
        printf("Tree 1 and Tree 3 are equal.\n");
    } else {
        printf("Tree 1 and Tree 3 are not equal.\n");
    }

    printf("In-Order Traversal of Tree 1: ");
    printTree(tree1);
    printf("\n");

    printf("In-Order Traversal of Tree 2: ");
    printTree(tree2);
    printf("\n");

    printf("In-Order Traversal of Tree 3: ");
    printTree(tree3);
    printf("\n");


    return 0;
}
