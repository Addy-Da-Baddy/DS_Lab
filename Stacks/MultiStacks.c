#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE  20
#define NUM_STACK 4

struct MulStack{
    int top[NUM_STACK];
    int arr[MAX_SIZE];
    int boundary[NUM_STACK + 1]; // One more for the last boundary
};

void init (struct MulStack *ms){
    int size = MAX_SIZE / NUM_STACK;
    for (int i = 0; i < NUM_STACK; i++){
        ms->top[i] = size * i - 1;
        ms->boundary[i] = size * (i + 1) - 1; // Set boundaries correctly
    }
    ms->boundary[NUM_STACK] = MAX_SIZE - 1; // Last boundary
}

void push (struct MulStack *ms, int stackNum, int n ){
    bool isFull = (ms->top[stackNum] == ms->boundary[stackNum + 1]) || (ms->top[stackNum] == MAX_SIZE - 1);
    if (isFull){
        printf("Stack %d Full!\n", stackNum);
    } else {
        ms->arr[++ms->top[stackNum]] = n;
    }
}

int pop(struct MulStack *ms, int stackNum){
    bool isEmpty = (ms->top[stackNum] == -1) || (ms->top[stackNum] == ms->boundary[stackNum]);
    if (isEmpty){
        printf("Stack %d Empty\n", stackNum);
        return -1; // Return a sentinel value
    } else {
        return (ms->arr[ms->top[stackNum]--]);
    }
}

int main(){
    struct MulStack ms;
    init(&ms);
    
    push(&ms, 0, 10);
    push(&ms, 1, 20);
    push(&ms, 2, 30);
    push(&ms, 3, 40);
    
    printf("Popped from stack 0: %d\n", pop(&ms, 0));
    printf("Popped from stack 1: %d\n", pop(&ms, 1));
    printf("Popped from stack 2: %d\n", pop(&ms, 2));
    printf("Popped from stack 3: %d\n", pop(&ms, 3));
    
    return 0;
}
