#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREAD 4
#define WORK_PER_THREAD 100



int main()
{
	pthread_t mythread;
	pthread_t myrange[NUM_THREAD];

	struct thread_args range[NUM_THREAD];

	int thread_result;
	int i=0;

//	thread_result = pthread_create(&mythread,NULL,myfunc,NULL);


//	if(thread_result)/
//	{
//		exit(1);
//	}
//
//	for(i=0; i<20; i++)
//	{
//		printf("%lld \n",counter);
//		sleep(1);
//	}
//	running =0;

	for(i=0; i<NUM_THREAD; i++)
	{
		range[i].myid = i;
		range[i].start = WORK_PER_THREAD + 1;
		range[i].end = (i+1)*WORK_PER_THREAD;

		pthread_create(&myrange[i], NULL, myfunc1, &range[i]);
	}

	for(i=0; i<NUM_THREAD; i++)
	{
		pthread_join(myrange[i],NULL);
		printf("%i is sum : %lld \n",i,sum[i]);
	}
//	pthread_exit(NULL);

	return 0;
}

