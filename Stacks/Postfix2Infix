#include <stdio.h>
#include <string.h>

#define MAX 100

// Stack structure for strings
typedef struct {
    char data[MAX][MAX];
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
    }
}

// Determine if the character is an operator
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Concatenate strings
void concatStrings(char *result, char *str1, char op, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i, j;

    // Add '('
    result[0] = '(';
    
    // Copy str2
    for (i = 1; i <= len2; i++) {
        result[i] = str2[i - 1];
    }
    
    // Add operator
    result[i++] = op;
    
    // Copy str1
    for (j = 0; j < len1; j++) {
        result[i++] = str1[j];
    }
    
    // Add ')'
    result[i] = ')';
    result[i + 1] = '\0';
}

// Convert postfix expression to infix expression
void postfixToInfix(char *postfix, char *infix) {
    Stack stack;
    initStack(&stack);
    char temp[MAX];
    
    for (int i = 0; postfix[i] != '\0'; i++) {
        char token = postfix[i];
        
        if (isOperator(token)) {
            // Pop two operands from the stack
            char op1[MAX], op2[MAX];
            pop(&stack, op1);
            pop(&stack, op2);
            
            // Create a new string in the form "(op2 operator op1)"
            concatStrings(temp, op2, token, op1);
            
            // Push the new string back onto the stack
            push(&stack, temp);
        } else {
            // Operand: push it onto the stack
            temp[0] = token;
            temp[1] = '\0';
            push(&stack, temp);
        }
    }
    
    // The final infix expression will be the top of the stack
    pop(&stack, infix);
}

int main() {
    char postfix[MAX] = "321*+9-";
    char infix[MAX];
    
    postfixToInfix(postfix, infix);
    printf("Infix expression: %s\n", infix);
    
    return 0;
}
