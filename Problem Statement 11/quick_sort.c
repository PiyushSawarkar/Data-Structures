#include<stdio.h>
void quickSort(int a[],int low,int high){
int pivot;
if(low<high){
pivot=partition(a,low,high);
quickSort(a,low,pivot-1);
quickSort(a,pivot+1,high);
}
}
int partition(int a[],int low,int high){
int j,pivot=a[high],i=low-1,t;
for(j=low;j<high;j++){
if(a[j]<=pivot){
i++;
t=a[j];
a[j]=a[i];
a[i]=t;
}
}
t=a[i+1];
a[i+1]=a[high];
a[high]=t;
return(i+1);
}
int main(void){
int a[80],low,high,n,val,i;
printf("Enter Number of elements = ");
scanf("%d",&n);
for(i=0;i<n;i++){
scanf("%d",&a[i]);
}
quickSort(a,0,n-1);
printf("sorted array is:\n");
for(i=0;i<n;i++){
printf("%d",a[i]);
}
return(0);
}
