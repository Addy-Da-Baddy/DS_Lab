#include <stdio.h>
#include <string.h>

#define MAX 100

// Stack structure for strings
typedef struct {
    char data[MAX][MAX];
    int top;
} Stack;

// Initialize the stack
void init(Stack *s) {
    s->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Push a string onto the stack
void push(Stack *s, char *value) {
    if (s->top < MAX - 1) {
        strcpy(s->data[++(s->top)], value);
    } else {
        printf("Stack overflow!\n");
    }
}

// Pop a string from the stack
void pop(Stack *s, char *value) {
    if (!isEmpty(s)) {
        strcpy(value, s->data[(s->top)--]);
    } else {
        printf("Stack underflow!\n");
        value[0] = '\0'; // Set to empty string
    }
}

// Determine if the character is an operator
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int main(){
    Stack stack;
    init(&stack);
    char postfix[MAX] = "321*+9-";
    char infix[MAX];
    char temp[MAX];
    
    for (int i = 0; postfix[i] != '\0'; i++) {
        char token = postfix[i];
        
        if (!isOperator(token)) {
            // Push the operand (as a string)
            char operand[2] = {token, '\0'};
            push(&stack, operand);
        } else {
            char val1[MAX];
            char val2[MAX];
            
            // Pop two operands
            pop(&stack, val1);
            pop(&stack, val2);
            
            // Form the new string with the operator
            strcpy(temp, "(");
            strcat(temp, val2);
            char operator[2] = {token, '\0'};
            strcat(temp, operator);
            strcat(temp, val1);
            strcat(temp, ")");
            
            // Push the result back to the stack
            push(&stack, temp);
        }
    }
    
    // Pop the final infix expression
    pop(&stack, infix);
    
    // Print the infix expression
    puts(infix);
    
    return 0;
}

