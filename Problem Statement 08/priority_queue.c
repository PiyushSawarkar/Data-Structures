#include<stdio.h>

#include<stdlib.h>

#include<malloc.h>

struct node {
    int elemPriority;
    int data;
    struct node * next;
};
//elemPriority = Element Priority .
struct node * start = '\0';
void enqueue(); //enqueueIntoPriorityQueue
void dequeue(); //dequeueOutOfPriorityQueue
void display(); //displayPriorityQueue
void enqueue() {
    struct node * newNode, * ptr;
    int val, priority;
    printf("Enter the value to be inserted = ");
    scanf("%d", & val);
    printf("\n");
    printf("Enter priority of the Element = ");
    scanf("%d", & priority);
    printf("\n");
    newNode = (struct node * ) malloc(sizeof(struct node));
    if (newNode == '\0') {
        printf("No Memory Available\n");
    } else {
        newNode->data = val;
        newNode->elemPriority = priority;
        if (start == '\0' || newNode->elemPriority < start->elemPriority) {
            newNode->next = start;
            start = newNode;
        } else {
            ptr = start;
            while (ptr->next != '\0' && ptr->next->elemPriority <= newNode->elemPriority) {
                ptr = ptr->next;
            }
            newNode->next = ptr->next;
            ptr->next = newNode;
        }
    }
}
void dequeue() {
    struct node * ptr;
    if (start == '\0') {
        printf("Queue Empty\n");
    } else {
        ptr = start;
        printf("%d is deleted.", start->data);
        start = start->next;
        free(ptr);
    }
}
void display() {
    struct node * ptr;
    if (start == '\0') {
        printf("Queue Empty\n");
    } else {
        ptr = start;
        printf("format: element(Priority)\n");
        while (ptr != '\0') {
            printf(" %d[ %d ] ", ptr->data, ptr->elemPriority);
            ptr = ptr->next;
        }
    }
}
int main(void) {
    int opt;
    while (1) {
        printf("\n\nPriority Queue :\n\nEnter Option: \n1.Enqueue\ n2.Dequeue\ n3.Display\ n4.Exit\ n\ n ");
            scanf("%d", & opt);
            switch (opt) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Program Ended Successfully.\n\n");
                exit(0);
            default:
                printf("Enter correct Option\n\n");
            }
        }
    return (0);
}
