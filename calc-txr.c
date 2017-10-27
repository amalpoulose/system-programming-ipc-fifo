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
mkfifo("p",0664);
perror("pipe1");

int i,pd;
struct calc v;
pd=open("p",O_WRONLY);
v.a=atoi(argv[1]);
v.b=atoi(argv[3]);
v.op=argv[2][0];

write(pd,&v,sizeof(struct calc));

printf("   Done  \n");
return 0;
}
 
