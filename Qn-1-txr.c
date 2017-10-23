/*1.a)Process1 will send one string to process2?
b) process2 recieve the string and store alaphetes in one array and digits(Numeric characters) in
another array?
Ex: i/p: vector41872india
o/p : vectorindia ------->char array
41872 ---------->integer array*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(void)
{
mkfifo("p",0664);
perror("pipe1");

int i,pd;
pd=open("p",O_WRONLY);
char s[20];

printf("Enter a string : ");
scanf("%s",s);

write(pd,s,strlen(s)+1);

printf("   Done  \n");
return 0;
}
 
