#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *llink, *rlink;
    int lthread, rthread; // Threads: 1 for thread, 0 for child pointer
} node;

// Function to find the inorder successor in a threaded binary tree
node *in_suc(node *ptr) {
    if (ptr->rthread) { // If right link is a thread, return rlink as successor
        return ptr->rlink;
    }

    // Otherwise, go to the leftmost node in the right subtree
    node *temp = ptr->rlink;
    while (!temp->lthread) {
        temp = temp->llink;
    }
    return temp;
}

// Function to traverse a threaded binary tree in inorder
void tinorder(node *head) {
    if (!head) return; // Handle empty tree

    // Find the leftmost node to start traversal
    node *temp = head;
    while (!temp->lthread) {
        temp = temp->llink;
    }

    // Perform inorder traversal until we return to the head
    while (temp != head) {
        printf("%d ", temp->data);
        temp = in_suc(temp);
    }
}
