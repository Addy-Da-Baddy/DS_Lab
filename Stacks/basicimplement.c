#include <stdio.h>

#include <stdbool.h>

#define MAX_SIZE 10

struct stack {
  int arr[MAX_SIZE];
  int top;
};

void init(struct stack * s) {
  s -> top = -1;
}

bool isFull(struct stack * s) {
  return (s -> top == (MAX_SIZE - 1));
}

bool isEmpty(struct stack * s) {
  return (s -> top == -1);
}

void push(struct stack * s, int n) {
  if (isFull(s)) {
    printf("Stack overflow!");
  } else {
    s -> arr[++s -> top] = n;
  }
}

int pop(struct stack * s) {
  if (isEmpty(s)) {
    printf("Stack underflow!");
    return (-99999);
  } else
    return (s -> arr[s -> top--]);
}

void display(struct stack * s) {
  if (isEmpty(s)) {
    printf("Empty!");
  } else {
    for (int i = 0; i <= s -> top; i++) {
      printf("%d ", s -> arr[i]);
    }
  }
}

int main() {
  struct stack s;
  struct stack * sp = & s;
  init(sp);
  push(sp, 4);
  push(sp, 5);
  push(sp, 2);
  push(sp, 1);
  display(sp);
  printf("\n");
  printf("%d", pop(sp));
  printf("\n");
  printf("%d", pop(sp));
  printf("\n");
  display(sp);
  return 0;
}