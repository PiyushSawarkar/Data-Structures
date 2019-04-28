#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include<ctype.h>

#define MAX 50
char st[MAX];
int top = -1;
char pop(char st[]) {
    char val;
    if (top == -1) {
        printf("Stack Underflow");
        exit(1);
    } else {
        val = st[top];
        top = top - 1;
        return (val);
    }
}
void push(char st[], char val) {
    if (top == MAX - 1) {
        printf("Stack Overflow");
        exit(1);
    } else {
        top = top + 1;
        st[top] = val;
    }
}
int getPriority(char src) {
    if (src == '+' || src == '-') {
        return (0);
    }
    if (src == '*' || src == '/' || src == '%') {
        return (1);
    }
}
void InfixToPostfix(char source[], char target[]) {
    int i = 0, j = 0;
    char temp;
    strcpy(target, "");
    while (source[i] != '\0') {
        if (source[i] == '(') {
            push(st, source[i]);
            i++;
        } else if (source[i] == ')') {
            while (top != -1 && st[top] != '(') {
                target[j] = pop(st);
                j++;
            }
            if (top == -1) {
                printf("Invalid expresion");
                exit(1);
            }
            temp = pop(st);
            i++;
        } else if (isdigit(source[i]) || isalpha(source[i])) {
            target[j] = source[i];
            i++;
            j++;
        } else if (source[i] == '+' || source[i] == '-' || source[i] == '*' || source[i] == '/' || source[i] == '%') {
            while (top != -1 && st[top] != '(' && getPriority(st[top]) >= getPriority(source[i])) {
                target[j] = pop(st);
                j++;
            }
            push(st, source[i]);
            i++;
        } else {
            printf("Incorrect Expression");
            exit(0);
        }
    } //end of while()
    while (top != -1 && st[top] != '(') {
        target[j] = pop(st);
        j++;
    }
    target[j] = '\0';
}
int main(void) {
    char infix[80], postfix[80];
    printf("Enter an Expression\n");
    scanf("%s", infix);
    strcpy(postfix, "");
    InfixToPostfix(infix, postfix);
    printf("Corresponding Postfix expression is : %s", postfix);
    return (0);
}
