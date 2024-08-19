#include <stdio.h>
#include <string.h>

#define MAX 100

// Stack structure for operators
typedef struct {
    char data[MAX];
    int top;
} Stack;

// Initialize the stack
void initStack(Stack *s) {
    s->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Push an element onto the stack
void push(Stack *s, char value) {
    if (s->top < MAX - 1) {
        s->data[++(s->top)] = value;
    } else {
        printf("Stack overflow!\n");
    }
}

// Pop an element from the stack
char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    } else {
        printf("Stack underflow!\n");
        return '\0';
    }
}

// Peek at the top element of the stack
char peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[s->top];
    } else {
        return '\0';
    }
}

// Determine precedence of operators
int precedence(char op) {
    switch(op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

// Check if the character is a digit
int isDigit(char c) {
    return c >= '0' && c <= '9';
}

// Check if the character is an operand
int isOperand(char c) {
    return isDigit(c) || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Main function
int main() {
    char infix[] = "3*(2+1)-9/(5-3)";  // Corrected missing semicolon
    char postfix[MAX];
    Stack stack;
    initStack(&stack);
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char token = infix[i];

        if (isOperand(token)) {
            postfix[j++] = token;  // Append operand directly to postfix
        }
        else if (token == '(') {
            push(&stack, token);
        }
        else if (token == ')') {
            while (peek(&stack) != '(' && !isEmpty(&stack)) {
                postfix[j++] = pop(&stack);
            }
            pop(&stack);  // Pop the '(' from the stack
        }
        else {
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(token)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, token);
        }
    }

    // Pop all remaining operators from the stack
    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';  // Null-terminate the postfix expression

    puts(postfix);  // Print the postfix expression

    return 0;
}



