/*3.process1 will send directory name to process2.
Process2 after recieving directory name,open directory and count no.of files.and that result send
back to process1.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<dirent.h>
#include<fcntl.h>

int main(void)
{
	mkfifo("p1",0664);
	perror("pipe1");
	mkfifo("p2",0664);
	perror("pipe2");
	int pd1,pd2,count=0;
	char s[100];
	pd1=open("p1",O_RDONLY);
	pd2=open("p2",O_WRONLY);
	read(pd1,s,sizeof(s));
        printf("path = %s\n",s);
	DIR *dp;
	dp=opendir(s);
	struct dirent *v;
	while(v=readdir(dp))
	{
		if(v->d_name[0]=='.')
			continue;
		count++;
	}
	write(pd2,&count,sizeof(count));
	return 0;
}
