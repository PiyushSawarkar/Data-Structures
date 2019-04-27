#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
int data;
struct node *next;
};
struct node *top=NULL;
void push();
void pop();
void peek();
void display();
void push(){
struct node *newNode,*ptr;
int val;
newNode=(struct node*)malloc(sizeof(struct node));
if(newNode==NULL){
printf("No Memory available\n");
}
else{
printf("Enter element to be pushed = ");
scanf("%d",&val);
printf("\n");
newNode->data=val;
if(top==NULL){
top=newNode;
newNode->next=NULL;
}
else{
newNode->next=top;
top=newNode;
}
}
}
void pop(){
struct node *ptr;
if(top==NULL){
printf("Underflow\n");
}
else{
ptr=top;
 printf("%d is deleted.",top->data);
top=top->next;free(ptr);
}
}
void peek(){
struct node *ptr;
if(top==NULL){
printf("Underflow\n");
}
else{
printf("%d is at Top.\n",top->data);
}
}
void display(){
struct node *ptr=top;
if(top==NULL){
printf("Stack is empty\n");
}
else{
 while(ptr!=NULL){
 printf(" %d ",ptr->data);
 ptr=ptr->next;
 }
}
}
int main(void){
int opt;
while(1){
printf("\nStack ADT\n\nEnter option\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\
n");
scanf("%d",&opt);
switch(opt){
case 1:
push();
break;
case 2:
pop();
break;
case 3:
peek();
break;
case 4:
display();
break;
case 5:
printf("Program ended Successfully\n\n");
exit(0);
default:
 printf("Enter correct option\n\n");
}
}
return(0);
}
