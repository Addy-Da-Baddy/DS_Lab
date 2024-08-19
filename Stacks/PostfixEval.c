#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 25

struct stack {
    int top;
    int arr[MAXSIZE];
};

typedef struct stack st;

void init(st* s){
    s->top = -1;
}

bool isFull(st* s){
    return (s->top == MAXSIZE - 1);
}

bool isEmpty(st *s){
    return (s->top == -1);
}

void push(st *s, int n){
    if (!isFull(s)){
        s->top++;
        s->arr[s->top] = n;
    }
    else {
        printf("Full!\n");
    }
}

int pop(st *s){
    if (!isEmpty(s)){
        int x = s->arr[s->top];
        s->top--;
        return x;
    }
    printf("Stack Underflow\n");
    return -9999999;
}

int main() {
    st eval;
    init(&eval);
    char exp[] = "231*+9-";
    for (int i = 0; exp[i]!='\0'; i++){
        if (exp[i]>='0' && exp[i] <= '9'){
            push(&eval, exp[i] - '0');
        }
        else {
            int val1 = pop(&eval);
            int val2 = pop(&eval);
            switch (exp[i]) {
                case '+': push(&eval, val2 + val1); break;
                case '-': push(&eval, val2 - val1); break;
                case '*': push(&eval, val2 * val1); break;
                case '/': push(&eval, val2 / val1); break;
                default: printf("Invalid operator!\n"); return -1;
            }
        }
    }
    
    printf("%d", pop(&eval));
    
    return 0;
}
