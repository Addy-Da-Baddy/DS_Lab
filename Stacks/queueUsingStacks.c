#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Define stack structure
typedef struct Stack {
    int top;
    int items[MAX];
} Stack;

// Function to initialize a stack
void initializeStack(Stack *s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to check if the stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Function to push an element onto the stack
void push(Stack *s, int item) {
    if (isFull(s)) {
        printf("Stack is full!\n");
        return;
    }
    s->items[++(s->top)] = item;
}

// Function to pop an element from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->items[(s->top)--];
}

// Queue structure using two stacks
typedef struct Queue {
    Stack stack1;
    Stack stack2;
} Queue;

// Function to initialize a queue
void initializeQueue(Queue *q) {
    initializeStack(&q->stack1);
    initializeStack(&q->stack2);
}

// Function to enqueue an element into the queue
void enqueue(Queue *q, int item) {
    push(&q->stack1, item);
}

// Function to dequeue an element from the queue
int dequeue(Queue *q) {
    int item;
    // If stack2 is empty, transfer all elements from stack1 to stack2
    if (isEmpty(&q->stack2)) {
        while (!isEmpty(&q->stack1)) {
            push(&q->stack2, pop(&q->stack1));
        }
    }
    // Pop the element from stack2
    item = pop(&q->stack2);
    return item;
}

// Main function to test the queue implementation
int main() {
    Queue q;
    initializeQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    enqueue(&q, 40);
    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    return 0;
}
