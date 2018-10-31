#include<stdio.h>
enum{thinking,hungry,eating} state[5];
int self[5];
int signal()
{
	return eating; 
}
int wait()
{
	return hungry; 
}
void init(int n)
{
	int i;
	for(i=0;i<n;i++)
	state[i] = thinking;
}
void test(int i, int n)
{
	if(state[(i+n-1)%n]!= eating && state[i]==hungry && state[(i+1)%n]!=eating)
	{
		state[i] = eating;
		self[i] = signal();
	}
}
void putdown(int i,int n)
{
	state[i] = thinking;
	printf("\n Philospher %d to thinking state\n", i+1);
	test((i+n-1)%n,n);
	test((i+1)%n,n);
}
void pickup(int i,int n)
{
	state[i] = hungry;
	test(i,n);
	if(state[i]!=eating)
	{
		self[i] = wait();
		printf("\n Philosopher %d waiting i.e. hungry",i+1);
	}
else printf("\n Philosopher %d eating",i+1);
}
void showstate(int n)
{
	int i=0;
	for(;i<n;i++)
	{
		if(state[i]==thinking)
		printf("\n Philosopher %d is thinking",i+1);
		else if(state[i]==hungry)
		printf("\n Philosopher %d is hungry",i+1);
		else printf("\n Philosopher %d is eating",i+1);
	}
}
int main()
{
	int i=0,n=5;
	printf("\n Enter the number of philosophers\t");
	scanf(" %d", &n);
	init(n);
	while(1)
	{
		printf("\n1.Pickup\t2.Putdown\t3.Showstate\t4.Exit\t");
		scanf(" %d",&i);
		switch(i)
		{
			case 1: printf("\n Enter the philosopher number\t");
			scanf(" %d",&i);
			pickup(i-1,n);
			break;
			case 2: printf("\n Enter the philosopher number\t");
			scanf(" %d",&i);
			putdown(i-1,n);
			break;
			case 3: showstate(n);
			break;
			case 4: return;
		}
	}
}
