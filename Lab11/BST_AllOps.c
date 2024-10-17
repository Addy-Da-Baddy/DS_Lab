#include <stdio.h>
#include <stdbool.h>

typedef struct tnode{
    struct tnode* llink;
    struct tnode* rlink;
    int data;
}tnode;

typedef struct BinaryTree{
    tnode* root;
}BT;

tnode* createNode(int value) {
    tnode* newNode = (tnode*)malloc(sizeof(tnode));
    newNode->data = value;
    newNode->llink = NULL;
    newNode->rlink = NULL;
    return newNode;
}


tnode* insert(tnode* root, int value){
        if  (root==NULL){
            return createNode(value);
        }

        if (value < root->data)
            root->llink = insert(root->llink,value);
        else
            root->rlink = insert(root->rlink,value);
}

tnode* findMin(tnode* root) {
    while (root && root->llink) {
        root = root->llink;
    }
    return root;
}


tnode* deleteNode(tnode* root, int value) {
    if (root == NULL) return root;

    if (value < root->data) {
        root->llink = deleteNode(root->llink, value);
    } else if (value > root->data) {
        root->rlink = deleteNode(root->rlink, value);
    } else {
        if (root->llink == NULL) {
            tnode* temp = root->rlink;
            free(root);
            return temp;
        } else if (root->rlink == NULL) {
            tnode* temp = root->llink;
            free(root);
            return temp;
        }

        tnode* temp = findMin(root->rlink);
        root->data = temp->data;
        root->rlink = deleteNode(root->rlink, temp->data);
    }
    return root;
}


tnode* search(tnode* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return search(root->llink, value);
    }
    return search(root->rlink, value);
}

void printTree(tnode* root) {
    if (root != NULL) {
        printTree(root->llink);
        printf("%d ", root->data);
        printTree(root->rlink);
    }
}


#include <stdio.h>
#include <stdlib.h>

int main() {
    BT tree;
    tree.root = NULL;
    int choice, value;

    while (1) {
        printf("Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Print Tree\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                tree.root = insert(tree.root, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                tree.root = deleteNode(tree.root, value);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(tree.root, value)) {
                    printf("%d found in the tree.\n", value);
                } else {
                    printf("%d not found in the tree.\n", value);
                }
                break;
            case 4:
                printf("In-order traversal: ");
                printTree(tree.root);
                printf("\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}



