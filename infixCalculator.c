// Infix calculator

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void initStack(Stack *s);
int isEmpty(Stack *s);
int isFull(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);
int precedence(char op);
int isOperator(char ch);
int evaluatePostfix(char *postfix);
void infixToPostfix(char *infix, char *postfix);

int main() {
    char infix[MAX], postfix[MAX];
    
    while (printf("Enter expression: "), fgets(infix, MAX, stdin) != NULL) {
        infix[strcspn(infix, "\n")] = 0;

        infixToPostfix(infix, postfix);
        int result = evaluatePostfix(postfix);

        printf("Result: %d\n", result);
    }

    return 0;
}

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, int value) {
    if (!isFull(s)) {
        s->data[++(s->top)] = value;
    }
}

int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return -1; 
}

int peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[s->top];
    }
    return -1; 
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        default:
            return 0;
    }
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%');
}


void infixToPostfix(char *infix, char *postfix) {
    Stack s;
    initStack(&s);
    int i = 0, j = 0;
    char ch;
    
    while ((ch = infix[i++]) != '\0') {
        if (isdigit(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(&s, ch);
        } else if (ch == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s);
        } else if (isOperator(ch)) {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)) {
                postfix[j++] = pop(&s);
            }
            push(&s, ch);
        }
    }

    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0';
}


int evaluatePostfix(char *postfix) {
    Stack s;
    initStack(&s);
    int i = 0;
    char ch;

    while ((ch = postfix[i++]) != '\0') {
        if (isdigit(ch)) {
            push(&s, ch - '0');
        } else if (isOperator(ch)) {
            int val2 = pop(&s);
            int val1 = pop(&s);
            switch (ch) {
                case '+': push(&s, val1 + val2); break;
                case '-': push(&s, val1 - val2); break;
                case '*': push(&s, val1 * val2); break;
                case '/': push(&s, val1 / val2); break;
                case '%': push(&s, val1 % val2); break;
            }
        }
    }

    return pop(&s);
}