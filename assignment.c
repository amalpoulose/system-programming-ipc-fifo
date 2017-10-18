#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc,char **argv)
{
if(argc!=2)
{
printf("Usage : ./a.out filename\n");
 return;
}
int fd,pd;

mkfifo("p1",0664);
perror("Pipe1");

char ch;
pd=open("p1",O_WRONLY);

fd=open(argv[1],O_RDONLY);
if(fd<0)
{
  perror("File open");
  return ;
}

while((read(fd,&ch,1))!=0)
{
 write(pd,&ch,1);
 printf("sucessfull transmition of %c\n",ch);
}

 ch='\0';
 write(pd,&ch,1);  
printf("\n       Done\n");
return 0;
}

