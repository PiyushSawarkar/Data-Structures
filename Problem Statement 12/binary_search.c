#include<stdio.h>
int a[80];
void bubbleSort(int a[],int n){
int i,j,t;
for(i=0;i<n;i++){
for(j=0;j<n-1-i;j++){
if(a[j]>a[j+1]){
t=a[j];
a[j]=a[j+1];
a[j+1]=t;
}
}
}
for(i=0;i<n;i++){
printf("%d ",a[i]);
}
}
int main(void){
int n,i,first,last,middle,pos=-1,val;
printf("\nEnter Number of values = ");
scanf("%d",&n);
printf("\nEnter Elements :\n");
first=0;
last=n-1;
middle=(first+last)/2;
for(i=0;i<n;i++){
scanf("%d",&a[i]);
}
printf("\nenter the value to be searched = ");
scanf("%d",&val);
bubbleSort(a,n);
while(first<=last){
if(val>a[middle]){
first=middle+1;
last=n-1;
middle=(first+last)/2;
}
else if(val<a[middle]){
first=0;
last=middle-1;
middle=(first+last)/2;
}
else if(val==a[middle]){
pos=middle;
printf("\nValue found at Position %d and is equal
to %d",pos,val);
break;
}
}
if(pos==-1){
printf("\nValue Not Present");
}
return(0);
}
