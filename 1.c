#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


int main()
{
	pid_t child;
	child = fork();
	
	printf("\nchild=%d",child);
	if(child == 0)
	{
		printf("\nchild pid=%d\nparent pid=%d\n",getpid(),getppid());
		exit(0);
	}
	else
	{
		wait();
		printf("\nchild pid=%d\nparent pid=%d\n",child,getppid());
	}
	
}
