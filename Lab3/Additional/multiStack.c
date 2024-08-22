#include <stdio.h>
#include <stdbool.h>
#define MAXSIZE 20
#define NUMSTACKS 4

struct multiStack {
    int top[NUMSTACKS];
    int boundary[NUMSTACKS + 1];
    int items[MAXSIZE];
};


void init(struct multiStack* ms) {
    int size = MAXSIZE / NUMSTACKS;
    for (int i = 0; i < NUMSTACKS; i++) {
        ms->top[i] = ms->boundary[i] = i * size - 1;
    }
    ms->boundary[NUMSTACKS] = MAXSIZE;
}

bool isFull(struct multiStack* ms, int stack_index) {
    return (ms->top[stack_index] == ms->boundary[stack_index + 1]);
}

bool isEmpty(struct multiStack* ms, int stack_index) {
    return (ms->top[stack_index] == ms->boundary[stack_index]);
}

void push(struct multiStack* ms, int stack_index, int num) {
    if (isFull(ms, stack_index)) {
        printf("Stack %d Overflow\n", stack_index);
    } else {
        ms->items[++ms->top[stack_index]] = num;
    }
}

int pop(struct multiStack* ms, int stack_index) {
    if (isEmpty(ms, stack_index)) {
        printf("Stack %d Underflow\n", stack_index);
        return -999999;
    } else {
        return ms->items[ms->top[stack_index]--];
    }
}

int main() {
    struct multiStack ms;
    init(&ms);

    push(&ms, 0, 10);
    push(&ms, 0, 20);
    push(&ms, 1, 30);
    push(&ms, 1, 40);

    printf("Popped from stack 0: %d\n", pop(&ms, 0));
    printf("Popped from stack 1: %d\n", pop(&ms, 1));
    printf("Popped from stack 0: %d\n", pop(&ms, 0));
    printf("Popped from stack 0: %d\n", pop(&ms, 0));

    return 0;
}


