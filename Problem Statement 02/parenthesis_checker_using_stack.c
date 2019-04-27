#include<stdio.h>
#define MAX 40
char stack[MAX];
int top=-1;
void push(char val,char stack[])
{
if(top==MAX-1)
{
printf("Stack OVERFLOW");
}
else
{
top=top+1;
stack[top]=val;
}
}
char pop(char stack[])
{
char temp;
if(top==-1)
{
printf("Stack UNDERFLOW");
}
else
{
temp=stack[top];
top=top-1;
}
}
int main(void)
{
char exp[80],temp;
int i=0,flag=1;
printf("Enter an expresion\n");
scanf("%s",exp);
for(i=0;exp[i]!='\0';i++)
{
if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
{
push(exp[i],stack);
}
if(exp[i]==')'||exp[i]=='}'||exp[i]==']')
{
if(top==-1)
{
flag=0;
}
else
{
temp=pop(stack);
if( exp[i]==')'&& ( temp=='{' || temp=='[' ) )
{
flag=0;
}
if( exp[i]=='}'&& ( temp=='(' || temp=='[' ) )
{
flag=0;
}
if( exp[i]==']'&& ( temp=='(' || temp=='{' ) )
{
flag=0;
}
}
}
}
if(top>=0)
{
flag=0;
}
if(flag==1)
{
printf("Valid expression");
}
if(flag==0)
{
printf("Invalid expression");
}
return(0);
}
