#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, j,bus[10], i,ct[10],tat[10],wt[10], p[10];
    int temp, sum=0, pos;
    float avg=0, atat=0;
    printf("\nenter total no of process:");
    scanf("%d",&n);
    printf("\n enter the process burst time\n");
    for(i=0;i<n;i++)
    {
        printf("p[%d] :",i+1);
        scanf("%d", &bus[i]);
        p[i]=i+1;
    }
     for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bus[j]<bus[pos])
                pos=j;
        }
 
        temp=bus[i];
        bus[i]=bus[pos];
        bus[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
        
    
    for (i=0;i<n;i++)
    {
    ct[i]=bus[i]+sum;
    sum=ct[i];
    }
       for (i=0;i<n;i++)
    {
        tat[i]=ct[i];
        wt[i]=tat[i]-bus[i];
       }

    printf("process\tburst\tCT\ttat\twt\n");
           
        for (i=0;i<n;i++)
    {  
    printf(" %d\t%d\t%d\t%d\t%d\n",p[i],bus[i],ct[i],tat[i],wt[i]);
    }
       
 for (i=0;i<n;i++)
 {
 avg = wt[i]+ avg;
 atat = tat[i]+ atat;
 }
 printf("\n avg waiting time is : %f\n avg tat is %f",avg/n, atat/n);
 

return 0;
}
