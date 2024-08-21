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

// Reverse a given string
void reverseString(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
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

// Check if the character is an operand (digit or letter)
int isOperand(char c) {
    return isDigit(c) || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Main function
int main() {
    char infix[] = "3*(2+1)-9/(5-3)";
    char postfix[MAX];
    
    // Reverse the infix expression
    reverseString(infix);
    
    // Swap '(' with ')' and vice versa in the reversed infix expression
    for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }
    
    Stack stack;
    initStack(&stack);
    int j = 0;

    // Process each character in the reversed infix expression
    for (int i = 0; infix[i] != '\0'; i++) {
        char token = infix[i];

        // If the token is an operand, add it to the postfix expression
        if (isOperand(token)) {
            postfix[j++] = token;
        }
        // If the token is '(', push it onto the stack
        else if (token == '(') {
            push(&stack, token);
        }
        // If the token is ')', pop from the stack to the postfix until '(' is found
        else if (token == ')') {
            while (peek(&stack) != '(' && !isEmpty(&stack)) {
                postfix[j++] = pop(&stack);
            }
            pop(&stack);  // Pop the '(' from the stack
        }
        // If the token is an operator
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

    postfix[j] = '\0'; // Null-terminate the postfix expression

    // Reverse the postfix expression to get the prefix expression
    reverseString(postfix);

    // Print the prefix expression
    puts(postfix);

    return 0;
}
