/* Basic  calculator   receiver*/
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
int main(void)
{
	mkfifo("p1",0664);
	perror("pipe1");
	mkfifo("p2",0664);
	perror("pipe2");
	struct calc v;
	int pd1,pd2,res;
	pd1=open("p1",O_RDONLY);
	pd2=open("p2",O_WRONLY);
	read(pd1,&v,sizeof(struct calc));
	switch(v.op)
	{
		case '+' : res=v.a + v.b;
			   break;
		case '-' : res=v.a - v.b;
			   break;
		case '*' : res=v.a * v.b;
			   break;
		case '/' : res=v.a / v.b;
			   break;
		default :printf("Invalid operator\n");
	}
        write(pd2,&res,sizeof(int));

	printf("\b  \n   Done  \n");
	return 0;
}
 

