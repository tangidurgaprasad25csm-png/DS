#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;


void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = c;
    }
}


char pop(void) {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    }

    return stack[top--];
}


int precedence(char ch) {
    if (ch == '^') {
        return 3;
    } else if (ch == '*' || ch == '/') {
        return 2;
    } else if (ch == '+' || ch == '-') {
        return 1;
    }

    return -1;
}


int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' ||
           ch == '/' || ch == '^';
}


void infixToPostfix(char infix[], char postfix[]) {
    int i;
    int j = 0;
    char ch;

    top = -1;

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (isalnum((unsigned char)ch)) {
            
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }

            if (top != -1 && stack[top] == '(') {
                pop(); 
            } else {
                printf("Error: mismatched parentheses.\n");
                postfix[0] = '\0';
                return;
            }
        } else if (isOperator(ch)) {
            while (top != -1 && stack[top] != '(' &&
                   (precedence(stack[top]) > precedence(ch) ||
                   (precedence(stack[top]) == precedence(ch) && ch != '^'))) {
                postfix[j++] = pop();
            }

            push(ch);
        } else {
            printf("Error: invalid character '%c'.\n", ch);
            postfix[0] = '\0';
            return;
        }
    }

    while (top != -1) {
        if (stack[top] == '(') {
            printf("Error: mismatched parentheses.\n");
            postfix[0] = '\0';
            return;
        }

        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int main(void) {
    char infix[MAX];
    char postfix[MAX];

    printf("Enter infix expression (without spaces): ");

    if (scanf("%99s", infix) != 1) {
        printf("Input error.\n");
        return 1;
    }

    infixToPostfix(infix, postfix);

    if (postfix[0] != '\0') {
        printf("Postfix expression: %s\n", postfix);
    }

    return 0;
}







