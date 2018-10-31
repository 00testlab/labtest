#include<stdio.h>
struct file{
int all[10],max[10],need[10],flag;
};
void main()
{
struct file f[10];
int f1;
int i,j,k,b,n,t,g,id,next,in=0,p;
int avail[10],seq[10];
printf("enter number of process");
scanf("%d",&n);
printf("enter the number of resources");
scanf("%d",&t);
for(i=0;i<n;i++)
{
printf("enter details of p %d",i);
printf("enter the allocation\t\t");
for(j=0;j<t;j++)
{
scanf("%d",&f[i].max[j]);
f[i].flag=0;
}
}
printf("\n enter the available resources \t \t ");
for(i=0;i<t;i++)
scanf("%d",&avail[i]);
printf("enter new request details");
printf("enter pid  \t....\t");
scanf("%d",&id);
printf("enter request for resources  \t");
for(i=0;i<t;i++)
{
avail[i]=avail[id]+next;
}
for(i=0;i<n;i++)
{
for(j=0;j<t;j++)
{
f[i].need[j]=f[i].max[j]-f[i].all[j];
if(f[i].need<0)
f[i].need[j]=0;
}
}
 in=0,f1=0,g=0;
while(in!=n)
{
for(j=0;j<n;j++)
{
b=0;
for(p=0;p<t;p++)
{
if(avail[p]>=f[g].need[0])
b=b+1;
}
if(b==t)
{
printf("p%d is visited",i);
seq[f1++]=i;
f[i].flag=1;
for(k=0;k<t;k++)
avail[k]=avail[k]+f[j].all[k];
in=in+1;
printf("(");
for(k=0;k<t;k++)
printf("%dID",avail[k]);
printf(")");
g=1;
}
else
g=0;
}

in++;
}
if(g==0)
{
printf("\n request not granted,deadlock occured\n");
printf("\nsystem is in unsafe state");
goto y;
}
printf("\n system is in safe state");
printf("\n the safe sequences (....");
for(i=0;i<t;i++)
printf("p%d",seq[i]);
printf(")");
printf("\n process\t allocation\t max\t need\n");
y:
for(i=0;i<n;i++);
printf("p%d\t",i);
for(j=0;j<t;j++)
printf("%6d",f[i].all[j]);
for(j=0;j<t;j++)
printf("%6d",f[i].max[j]);
for(j=0;j<t;j++)
printf("%6d",f[i].need[j]);
printf("\n");
}



