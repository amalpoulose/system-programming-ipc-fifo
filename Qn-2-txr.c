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

	int i,pd,qd,i_arr[100];
	char c_arr[100];
	pd=open("p",O_WRONLY);
	qd=open("q",O_RDONLY);
	char s[20];

	printf("Enter a string : ");
	scanf("%s",s);

	write(pd,s,strlen(s)+1);
	read(qd,c_arr,sizeof(c_arr));
	printf("sorted character array : %s\n",c_arr);
	
        read(qd,i_arr,sizeof(i_arr));
        printf("sorted integer array : ");
	for(i=1;i<i_arr[0];i++)
           printf("%d, ",i_arr[i]);
        strcpy(c_arr,"Sucess");
	write(pd,s,strlen(c_arr)+1);
	printf("\b  \n   Done  \n");
	return 0;
}

