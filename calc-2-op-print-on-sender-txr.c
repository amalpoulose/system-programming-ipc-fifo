/* Basic  calculator   transmitter*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
struct calc
{
 int a,b;
 char op;
};

int main(int argc, char **argv)
{

if(argc != 4)
{
 printf("usage : ./outfile operand1 operator operand\n");
 return;
}
mkfifo("p1",0664);
perror("pipe1");
mkfifo("p2",0664);
perror("pipe2");

int i,pd1,pd2,res;
struct calc v;
pd1=open("p1",O_WRONLY);
pd2=open("p2",O_RDONLY);
v.a=atoi(argv[1]);
v.b=atoi(argv[3]);
v.op=argv[2][0];

write(pd1,&v,sizeof(struct calc));
read(pd2,&res,sizeof(int));

printf("  Result = %d \n",res);
printf("   Done  \n");
return 0;
}
 
