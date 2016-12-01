#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void a()
{
	sleep(1);
	printf("a function \n");
	printf("pid is %d \n",(long)getpid());

}

void b()
{
	printf("b funtion \n");
	a();
}

void c()
{
	printf("c function \n");
	b();

}



void main()
{
	int i;

	while(1)
	{
		//printf("pid is %d \n",(long)getpid());
		c();
		sleep(1);
	}
}
