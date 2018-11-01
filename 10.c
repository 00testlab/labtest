#include<stdio.h>
int main()
{
int cylinders[10],n,current,total=0,i,j,temp,range,start,t;
printf("\nEnter no of cylinders\n");
scanf("%d",&n);
printf("\nEnter range\n");
scanf("%d",&range);
printf("\nEnter the cylinders\n");
for(i=0;i<n;i++)
scanf("%d",&cylinders[i]);
for(i=0;i<n-1;i++)
for(j=0;j<n-1-i;j++)
if(cylinders[j+1]<cylinders[j])
{
temp=cylinders[j+1];
cylinders[j+1]=cylinders[j];
cylinders[j]=temp;
}
printf("\nEnter current location\n");
scanf("%d",&current);
t=current;
printf("%d",current);
for(i=0;i<n;i++)
if(cylinders[i]>current)
{
total+=cylinders[i]-t;
t=cylinders[i];
printf("-->%d",cylinders[i]);
}
total+=range-cylinders[i-1];
printf("-->%d",range);
for(i=0;i<n;i++)
if(cylinders[i]>current)
{
start=i-1;
break;
}
t=cylinders[start];
printf("-->%d",t);
total+=range-cylinders[start];
for(j=start-1;j>=0;j--)
{total+=t-cylinders[j];
t=cylinders[j];
printf("-->%d",cylinders[j]);
}
printf("\nTotal is %d\n",total);
}
