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
	mkfifo("p",0664);
	perror("pipe1");
	struct calc v;
	int pd;
	pd=open("p",O_RDONLY);
	read(pd,&v,sizeof(struct calc));
	switch(v.op)
	{
		case '+' : printf("%d + %d = %d\n",v.a,v.b,v.a + v.b);
			   break;
		case '-' : printf("%d - %d = %d\n",v.a,v.b,v.a - v.b);
			   break;
		case '*' : printf("%d * %d = %d\n",v.a,v.b,v.a * v.b);
			   break;
		case '/' : printf("%d / %d = %f\n",v.a,v.b,(float)v.a / v.b);
			   break;
		default :printf("Invalid operator\n");
	}
	printf("\b  \n   Done  \n");
	return 0;
}
 

