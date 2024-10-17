#include <stdio.h>
#include <stdbool.h>
#define MAXSIZE 100
typedef struct tnode{
    struct tnode* llink;
    struct tnode* rlink;
    int data;
}tnode;

typedef struct BinaryTree{
    tnode* root;
}BT;


typedef struct stack{
    int top;
    tnode* items[MAXSIZE];

}stack;

void initStack(stack *s){
    s->top=-1;
}

void push(stack* s, tnode* node){
    if (s->top<MAXSIZE-1){
        s->items[++s->top] = node;
    }
}

tnode* pop(stack* s){
    if (s->top>-1){
        return s->items[s->top--];
    }
    return NULL;
}

void inOrder(BT* tree){
    stack s;
    initStack(&s);
    tnode* curr = tree->root;
    while (curr!=NULL || s.top!=-1){
        while (curr!=NULL){
            push(&s,curr);
            curr = curr->llink;
        }
        curr = pop(&s);
        printf("%d " , curr->data);
        curr = curr->rlink;
    }
}

void preOrder(BT *tree){
    stack s;
    initStack(&s);
    push(&s, tree->root);
    while (s.top!=-1){
        tnode* curr = pop(&s);
        printf("%d ", curr->data);
        if (curr->rlink) push(&s, curr->rlink);
        if (curr->llink) push(&s, curr->llink);
    }
}

void postOrder(BT* tree){
    stack s1,s2;
    initStack(&s1);
    initStack(&s2);
    push(&s1, tree->root);
    while (s1.top!=-1){
        tnode* curr = pop(&s1);
        push(&s2,curr);
        if (curr->llink) push(&s1, curr->llink);
        if (curr->rlink) push(&s1, curr->rlink);
    }
    while (s2.top!=-1){
        tnode* curr = pop(&s2);
        printf("%d " , curr->data);
    }
}

tnode* findParent(tnode *root, int value, tnode* parent){
        if (root==NULL){
            return NULL;
        }
        if (root->data==value){
            return parent;
        }
        tnode* left = findParent(root->llink, value, root);
        if (left!=NULL){
            return left;
        }
        return findParent(root->rlink, value, root);
}

bool printAncestors(tnode* root, int value) {
    if (root == NULL) {
        return false;
    }
    if (root->data == value) {
        return true;
    }
    if (printAncestors(root->llink, value) || printAncestors(root->rlink, value)) {
        printf("%d ", root->data);
        return true;
    }
    return false;
}


int countLeaf(tnode* root){
    if (root==NULL){
        return 0;
    }
    if (root->llink==NULL && root->rlink==NULL){
        return 1;
    }
    return countLeaf(root->llink) + countLeaf(root->rlink);

}

int findDepth(tnode* root){
    if (root==NULL){
        return 0;
    }
    int left = findDepth(root->llink);
    int right = findDepth(root->rlink);
    return (left>right?left:right) + 1;
}

int main() {
    BT tree;
    tnode node1, node2, node3, node4, node5;

    node1.data = 1; node1.llink = &node2; node1.rlink = &node3;
    node2.data = 2; node2.llink = NULL; node2.rlink = NULL;
    node3.data = 3; node3.llink = &node4; node3.rlink = &node5;
    node4.data = 4; node4.llink = NULL; node4.rlink = NULL;
    node5.data = 5; node5.llink = NULL; node5.rlink = NULL;

    tree.root = &node1;

    int choice, valueToFind;

    while (true) {
        printf("\nMenu:\n");
        printf("1. In-Order Traversal\n");
        printf("2. Pre-Order Traversal\n");
        printf("3. Post-Order Traversal\n");
        printf("4. Find Parent of a Node\n");
        printf("5. Print Ancestors of a Node\n");
        printf("6. Count Leaf Nodes\n");
        printf("7. Find Depth of Tree\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("In-Order Traversal: ");
                inOrder(&tree);
                break;
            case 2:
                printf("Pre-Order Traversal: ");
                preOrder(&tree);
                break;
            case 3:
                printf("Post-Order Traversal: ");
                postOrder(&tree);
                break;
            case 4:
                printf("Enter node value to find its parent: ");
                scanf("%d", &valueToFind);
                tnode* parent = findParent(tree.root, valueToFind, NULL);
                if (parent) {
                    printf("Parent of %d is %d\n", valueToFind, parent->data);
                } else {
                    printf("Node %d does not have a parent or does not exist in the tree.\n", valueToFind);
                }
                break;
            case 5:
                printf("Enter node value to find its ancestors: ");
                scanf("%d", &valueToFind);
                printf("Ancestors of %d: ", valueToFind);
                if (!printAncestors(tree.root, valueToFind)) {
                    printf("No ancestors found or the node does not exist.\n");
                }
                break;
            case 6:
                printf("Number of leaf nodes: %d\n", countLeaf(tree.root));
                break;
            case 7:
                printf("Depth of the tree: %d\n", findDepth(tree.root));
                break;
            case 8:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
