#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

// Stack definition
struct stack {
    char arr[MAX_SIZE];
    int top;
};

// Initialize the stack
void init(struct stack* s) {
    s->top = -1;
}

// Check if the stack is full
bool isFull(struct stack* s) {
    return s->top == MAX_SIZE - 1;
}

// Check if the stack is empty
bool isEmpty(struct stack* s) {
    return s->top == -1;
}

// Push an element onto the stack
void push(struct stack* s, char c) {
    if (isFull(s)) {
        printf("Stack overflow!\n");
    } else {
        s->arr[++s->top] = c;
    }
}

// Pop an element from the stack
char pop(struct stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow!\n");
        return '\0';
    } else {
        return s->arr[s->top--];
    }
}

// Function to check if a string is a palindrome using a stack
bool isPalindrome(char* str) {
    int length = strlen(str);
    struct stack s;
    init(&s);

    // Push all characters of the string onto the stack
    for (int i = 0; i < length; i++) {
        push(&s, str[i]);
    }

    // Pop characters from the stack and compare with the original string
    for (int i = 0; i < length; i++) {
        if (str[i] != pop(&s)) {
            return false;
        }
    }

    return true;
}

int main() {
    char str[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str)) {
        printf("The string is a palindrome\n");
    } else {
        printf("The string is not a palindrome\n");
    }

    return 0;
}
