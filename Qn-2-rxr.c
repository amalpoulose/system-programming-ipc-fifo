/*2.modify above programm in such a way that sort the data according to descending order.then send
back the o/p to process1.
O/p:
vtroniiedca
87421*/
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
	mkfifo("q",0664);
	perror("pipe2");

	int i,j,k,l,pd,qd,i_arr[20];
	pd=open("p",O_RDONLY);
	qd=open("q",O_WRONLY);
	char s[100],c_arr[100];

	read(pd,s,sizeof(s));
	printf("string is %s\n",s);
	for(i=0,j=1,k=0;s[i];i++)
		if(s[i]>=48 && s[i]<=57)
			i_arr[j++]=s[i]-48;
		else if((s[i]>=65 && s[i]<= 90)||(s[i]>=97 && s[i]<=122))
			c_arr[k++]=s[i];
        i_arr[0]=j;
	printf("Character array : ");
	for(i=0;i<k;i++)
		printf("%c",c_arr[i]);

	printf("\nInteger array  :  ");
	for(i=1;i<j;i++)
		printf("%d ,",i_arr[i]);

	for(i=0;i<k-1;i++)
	for(l=0;l<k-i-1;l++)
		if(c_arr[l]<c_arr[l+1])
			c_arr[l]=c_arr[l]+c_arr[l+1]-(c_arr[l+1]=c_arr[l]);
	c_arr[k]='\0';
	write(qd,c_arr,strlen(c_arr)+1);
	for(i=1;i<=j-1;i++)
	for(l=1;l<=j-i-1;l++)
		if(i_arr[l]<i_arr[l+1])
			i_arr[l]=i_arr[l]+i_arr[l+1]-(i_arr[l+1]=i_arr[l]);
               
	write(qd,i_arr,sizeof(int)*(i_arr[0]+1));
	read(pd,s,sizeof(s));
	printf("\b  \n  Done  \n");
	return 0;
}

