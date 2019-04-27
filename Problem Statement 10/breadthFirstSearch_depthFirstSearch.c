#include<stdio.h>
int q[20],top=-1,front=-1,rear=-1,a[20][20],vis[20],stack[20];
int dequeue();
void enqueue(int item);
void bfs(int s,int n);
void dfs(int s,int n);
void push(int item);
int pop();
void main()
{
int n,i,s,ch,j;
char c,dummy;
printf("ENTER THE NUMBER OF VERTICES ");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
printf("enter 1 if %d has a node with %d else 0 ",i,j);
scanf("%d",&a[i][j]);
}
}
printf("THE ADJACENCY MATRIX IS\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
printf(" %d",a[i][j]);
}
printf("\n");
}
do
{
for(i=1;i<=n;i++)
vis[i]=0;
printf("\n*****MENU*****");
printf("\n1.BINARY FIRST SEARCH");
printf("\n2.DEPTH FIRST BINARY SEARCH");
printf("\nENTER YOUR CHOICE");
scanf("%d",&ch);
printf("ENTER THE SOU
else
{
if(rear==-1)
{
q[++rear]=item;
front++;
}
else
q[++rear]=item;}
}
int dequeue()
{
int k;if((front>rear)||(front==-1))
return(0);
else
{
k=q[front++];
return(k);
}
}
void dfs(int s,int n)
{
int i,k;
push(s);
vis[s]=1;
k=pop();
if(k!=0)
printf(" %d ",k);
while(k!=0)
{
for(i=1;i<=n;i++)
if((a[k][i]!=0)&&(vis[i]==0))
{
push(i);
vis[i]=1;
}
k=pop();
if(k!=0)
printf(" %d ",k);
}
for(i=1;i<=n;i++)
if(vis[i]==0)
dfs(i,n);
}
void push(int item)
{
if(top==19)
printf("STACK OVERFLOW");
else
stack[++top]=item;
}
int pop()
{
int k;
if(top==-1)return(0);
else
{
k=stack[top--];
return(k);
}
