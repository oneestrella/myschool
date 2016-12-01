#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

void *myfunc(void *arg)
{

	printf("hello world \n");
	pthread_exit(NULL);
}

int main()
{
	pthread_t mythread;
	//char *data="this is main thread";
	int return_thread;

	return_thread = pthread_create(&mythread,NULL,myfunc,NULL);
	//printf("im the main thread \n");

	if(return_thread)
	{
		exit(1);
	}

//	printf("im the main thread \n");
	pthread_join(mythread,NULL);
	printf("im the main thread \n");

	pthread_exit(NULL);
}
