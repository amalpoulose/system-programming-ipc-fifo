/*3.process1 will send directory name to process2.
Process2 after recieving directory name,open directory and count no.of files.and that result send
back to process1.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("Usage:./outfile dirpath\n");
		return;
	}
	mkfifo("p1",0664);
	perror("pipe1");
	mkfifo("p2",0664);
	perror("pipe2");
	if(opendir(argv[1])==0)
	{
		perror("opendir");
		return;
	}
        int pd1,pd2,count;
	pd1=open("p1",O_WRONLY);
	pd2=open("p2",O_RDONLY);
        write(pd1,argv[1],strlen(argv[1])+1);
        read(pd2,&count,sizeof(count));
        printf("Number of File : %d\n",count);
	printf("  Done\n");
        return 0;
}

