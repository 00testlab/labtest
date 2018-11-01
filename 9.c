#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int usercount=0;
int ctr=0;
struct USER
{
char dirname[20][20];
char hierarchy[20][20][20];
int uid;
int dircount, filecount[20];
};
void init(struct USER U)
{
int i;
for(i=0;i<20;i++)
memset(U.dirname[i],'\0',20);
U.uid=-1;
U.dircount=0;
}
void moveleft(char A[][20], int pos, int dircount)
{
int i, j;
for(i=pos;i<dircount;i++)
for(j=0;j<20;j++)
A[i][j]=A[i+1][j];
}
void moveleftfiles(char A[][20][20], int pos, int filecount, int dirno)
{
int i, j, k;
for(i=pos;i<filecount;i++)
for(j=0;j<20;j++)
A[dirno][i][j] = A[dirno][i+1][j];
}
fileselect(struct USER *A, int dirno)
{
struct USER user = *A;
int i, j, ch;
char temp[20];
do{
printf("\n 1. View files\t2.Create files\t3.Delete files\t4.Go back\t");
scanf(" %d", &ch);
switch(ch)
{
case 1: if(user.filecount[dirno]<=0){
printf("\n No files exist\n");
break;
}
for(i=0;i<user.filecount[dirno];i++)
printf("\n %d. %s\t",i+1,user.hierarchy[dirno][i]);
break;
case 2: printf("\n Enter the name of the file\t");
scanf(" %s", user.hierarchy[dirno][user.filecount[dirno]]);
user.filecount[dirno]++;
break;
case 3: if(user.filecount[dirno]<=0)
{
printf("\n No files exist\n");
break;
}
printf("\n Enter the name of the file to be deleted\t");
scanf(" %s", temp);
for(i=0;i<user.filecount[dirno];i++)
{
if(strcmp(user.hierarchy[dirno][i],temp)==0)
{
memset(user.hierarchy[dirno][i],'\0',20);
user.filecount[dirno]--;
moveleftfiles(user.hierarchy,i,user.filecount[dirno],dirno);
break;
}
}
break;
case 4: return;
}
*A = user;
}while(ch!=4);
}
int main()
{
int choice, i, j, u, dirch, dirno, pos, flag;
char temp[20], ch;
struct USER user[20];
for(i=0;i<20;i++)
init(user[i]);
while(1)
{
printf("\n1.Create user\t2.Select user\t3.Exit\t");
scanf(" %d", &choice);
if(choice==3)
exit(0);else if(choice==1)
{
user[usercount].uid=++ctr;
usercount++;
printf("\n User created\n");
continue;
}
else if(choice==2)
{
if(usercount<=0)
{
printf("\n No user exists\n");
break;
}
for(i=0;i<usercount;i++)
printf("\n %d.User%d",i+1,user[i].uid);
scanf(" %d", &u);
if(u>usercount || u<=0)
{
printf("\n Invalid\n");
continue;
}
}
do{
printf("\n1.Select Directory\2. Create directory\t3.Delete directory\t4.Go Back\t");
scanf(" %d",&dirch);
switch(dirch)
{
case 1: if(user[u].dircount<=0)
{
printf("\n No directories exist\n");
break;
}
for(i=0;i<user[u].dircount;i++)
printf("\n %d. %s\t",i+1,user[u].dirname[i]);
scanf(" %d", &dirno);
if(dirno<0 || dirno>user[u].dircount)
{
printf("\nInvalid directory\n");
continue;
}
fileselect(&user[u], dirno-1);
break;
case 2:
printf("\n Enter the directory name\t");
scanf(" %s", user[u].dirname[user[u].dircount]);
user[u].dircount++;
break;
case 3:
printf("\n Enter the directory to be deleted\t");scanf(" %s", temp);
for(i=0;i<user[u].dircount;i++)
{
if(strcmp(temp,user[u].dirname[i])==0)
{
memset(user[u].dirname[i],'\0',20);
user[u].filecount[i]=0;
pos = i;
break;
}
}
user[u].dircount--;
moveleft(user[u].dirname,pos, user[u].dircount);
break;
case 4:
break;
default: break;
}
}while(dirch!=4);
}
}
