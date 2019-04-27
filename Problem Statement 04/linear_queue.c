#include<stdio.h>
#include<stdlib.h>
#define MAX 3
int queue[MAX];
int front=-1,rear=-1;
void insert(){
int val;
printf("Enter an Element to be inserted = ");
scanf("%d",&val);
if(rear==MAX-1){
printf("\nOverflow\n");
}
else{
if(front==-1&&rear==-1){
front=rear=0;
queue[rear]=val;
}
else{
rear++;
queue[rear]=val;
}
}
}
void delete(){
int val;
if(front==-1||front>rear){
printf("Underflow");
}
else{
val=queue[front];
printf("\n%d is deleted form queue\n",val);
front++;
if(front>rear){
front=rear=-1;
}
}
}
void display(){
int i;
if(front==-1||front>rear){
printf("\nQueue Empty\n");
}
else{
for(i=front;i<=rear;i++){
printf("%d ",queue[i]);
}
}
}
void peek(){
int val;
if(front==-1||front>rear){
printf("\nQueue Empty\n");
}
else{
val=queue[front];
printf("At front the value is %d",val);
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
