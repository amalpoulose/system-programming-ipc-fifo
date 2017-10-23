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

int i,j,k,pd,i_arr[20],c_arr[30];
pd=open("p",O_RDONLY);
char s[20];

read(pd,s,sizeof(s));
printf("string is %s\n",s);
for(i=0,j=0,k=0;s[i];i++)
 if(s[i]>=48 && s[i]<=57)
    i_arr[j++]=s[i]-48;
 else if((s[i]>=65 && s[i]<= 90)||(s[i]>=97 && s[i]<=122))
    c_arr[k++]=s[i];
printf("Character array : ");
for(i=0;i<k;i++)
 printf("%c",c_arr[i]);

printf("\nInteger array  :  ");
for(i=0;i<j;i++)
   printf("%d ,",i_arr[i]);
 
printf("\b  \n   Done  \n");
return 0;
}
 

