#include<stdio.h>

#include<stdlib.h>

#define MAX 3
int stack[MAX];
int top = -1;
void displayStack(int stack[]) {
    int i;
    if (top == -1)
        printf("\nStack is empty\n");
    else
        for (i = top; i >= 0; i--)
            printf(" %d ", stack[i]);
}
void peek(int stack[]) {
    int val;
    if (top == -1)
        printf("\nStack UNDERFLOW\n");
    else {
        val = stack[top];
        printf("\n%d is present at top of stack\n", val);
    }
}
void pop(int stack[]) {
    int val;
    if (top == -1)
        printf("\nStack UNDERFLOW\n");
    else {
        val = stack[top];
        top = top - 1;
    }
    printf("\n%d is poped out of stack\n", val);
}
void push(int stack[], int val) {
    if (top == MAX - 1)
        printf("\nStack OVERFLOW\n");
    else {
        top = top + 1;
        stack[top] = val;
    }
}
void menu() {
        int choice, val;
        while (1) {
            printf("\nEnter choice: \n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY STACK\n5.EXIT\n ");
            scanf("%d", & choice);
            switch (choice) {
                case 1:
                    printf("\nEnter value to be pushed onto stack\n ");
                    scanf("%d", & val); 
                    push(stack, val);
                    break;
                case 2:
                    pop(stack);
                    break;
                case 3:
                    peek(stack);
                    break;
                case 4:
                    displayStack(stack);
                    break;
                case 5:
                    exit(0);
                default:
                    printf("\nEnter correct choice\n");
            }
        }
}
int main(void) {
    menu();
    return (0);
}
