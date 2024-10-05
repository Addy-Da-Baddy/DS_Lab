#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* llink; // Left link
    struct Node* rlink; // Right link
} Node;

typedef struct Tree {
    Node* root; // Root of the tree
    int size;   // Number of nodes in the tree
} Tree;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->llink = NULL; // Initialize left link
    newNode->rlink = NULL; // Initialize right link
    return newNode;
}

// Function to initialize the tree
void initializeTree(Tree* tree) {
    tree->root = NULL;
    tree->size = 0;
}

// Function to insert a node based on direction vector
void insertNode(Tree* tree, int data, const char* direction) {
    if (tree->root == NULL) {
        tree->root = createNode(data);
        tree->size++;
        return;
    }
    
    Node* current = tree->root;
    for (int i = 0; direction[i] != '\0'; i++) {
        if (direction[i] == 'l') {
            if (current->llink == NULL) {
                current->llink = createNode(0); // Create a placeholder node if null
            }
            current = current->llink;
        } else if (direction[i] == 'r') {
            if (current->rlink == NULL) {
                current->rlink = createNode(0); // Create a placeholder node if null
            }
            current = current->rlink;
        } else {
            printf("Invalid direction: %c\n", direction[i]);
            return; // Exit if an invalid direction is encountered
        }
    }
    
    current->data = data; // Set the actual data at the last node
    tree->size++;
}

// Preorder traversal
void preorder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->llink);
    preorder(root->rlink);
}

// Inorder traversal
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->llink);
    printf("%d ", root->data);
    inorder(root->rlink);
}

// Postorder traversal
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->llink);
    postorder(root->rlink);
    printf("%d ", root->data);
}

// Example usage
int main() {
    Tree tree;
    initializeTree(&tree);

    // Create a sample tree with depth 3 and 6 elements
    insertNode(&tree, 1, "");       // Root
    insertNode(&tree, 2, "l");      // Left of root
    insertNode(&tree, 3, "r");      // Right of root
    insertNode(&tree, 4, "ll");     // Left of left
    insertNode(&tree, 5, "lr");     // Right of left
    insertNode(&tree, 6, "rl");     // Left of right

    // Insert the 7th element
    insertNode(&tree, 7, "rr");      // Right of right

    // Output the traversals
    printf("Preorder traversal: ");
    preorder(tree.root);
    printf("\n");

    printf("Inorder traversal: ");
    inorder(tree.root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(tree.root);
    printf("\n");

    // Output tree size
    printf("Tree size: %d\n", tree.size);

    // Free allocated memory (optional in this small example)
    // Memory freeing code would go here

    return 0;
}
