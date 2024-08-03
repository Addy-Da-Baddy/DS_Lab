#include <stdio.h>
#include <stdbool.h>

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

// Check if the character is an opening parenthesis
bool isOpening(char c) {
    return c == '(' || c == '{' || c == '[';
}

// Check if the character is a closing parenthesis
bool isClosing(char c) {
    return c == ')' || c == '}' || c == ']';
}

// Check if the pair of parentheses match
bool isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

// Check if the expression has balanced parentheses
bool isValidExpression(char* expression) {
    struct stack s;
    init(&s);

    for (int i = 0; expression[i] != '\0'; i++) {
        char c = expression[i];
        if (isOpening(c)) {
            push(&s, c);
        } else if (isClosing(c)) {
            if (isEmpty(&s) || !isMatchingPair(pop(&s), c)) {
                return false;
            }
        }
    }

    return isEmpty(&s);
}

int main() {
    char expression[MAX_SIZE];
    printf("Enter an expression: ");
    scanf("%s", expression);

    if (isValidExpression(expression)) {
        printf("The expression is valid\n");
    } else {
        printf("The expression is not valid\n");
    }

    return 0;
}
