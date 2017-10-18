
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(void)
{
	int fd,pd;

	mkfifo("p1",0664);
	perror("Pipe1");

	pd=open("p1",O_RDONLY);
	fd=open("data",O_WRONLY);
	char ch='\0',s[20];

	while(1)
	{
		read(pd,&ch,sizeof(ch));
		if(ch=='\0')
			break;
		printf("character recieved -- %c \n",ch);
		if(ch>96 &&ch<123)
			ch=ch&(~32);
		write(fd,&ch,1);
	}

	printf("\n       Done\n");
	return 0;
}

