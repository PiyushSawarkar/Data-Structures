#include<stdio.h>
#include<stdlib.h>
#define MAX 3
int front=-1,rear=-1;
int queue[MAX];
void insert(){
int val;
printf("\nEnter element to be inserted = \n");
scanf("%d",&val);
if(rear==MAX-1&&front==0){
printf("Overflow");
}
else if(front==-1&&rear==-1){
front=rear=0;
queue[rear]=val;
}
else if(rear==MAX-1&&front!=0){
rear=0;
queue[rear]=val;
}
else{
rear++;
queue[rear]=val;
}
}
void delete(){
int val;
if(front==-1&&rear==-1){
printf("Underflow");
}
val=queue[front];
if(front==rear){
front=rear=-1;
}
else{
if(front==MAX-1){
front=0;
}
else{
front++;
}
}
printf("%d is Deleted",val);
}
void display(){
int i;
if(front==-1&&rear==-1){
printf("Empty");
}
else{
if(front<=rear){
for(i=front;i<=rear;i++){
printf("%d ",queue[i]);
}
}
else{
for(i=front;i<=MAX-1;i++){
printf(" %d",queue[i]);
}
for(i=0;i<=rear;i++){
printf(" %d",queue[i]);
}
}
}
}
void peek(){
int val;
printf("Underflow");
}
else{
val=queue[front];
printf("%d is present at front",val);
}
}
int main(void){
int opt;
while(1){
printf("\n\nEnter Option\n1.Insert\n2.Delet\n3.peek\n4.Display Queue\n5.Exit\n\n");
scanf("%d",&opt);
switch(opt){
case 1:
insert();
break;
case 2:
delete();
break;
case 3:
peek();
break;
if(front==-1&&rear==-1){
case 4:
display();
break;
case 5:
printf("Program ended succesfully");
exit(0);
default:
printf("Enter Correct Option");
}
}
return(0);
}
