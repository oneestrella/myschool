#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREAD 8
#define WORK_PER_THREAD 100

struct thread_sum
{
	int myid;
	long long start;
	long long end;
};

volatile long long summ = 1000000000;
long long sum[NUM_THREAD];

void *myfunc(void *data)
{
	struct thread_sum *sum_in;

	long long sum_result = 0;
	long long i;

	sum_in = (struct thread_sum *) data;

	for(i=sum_in->start; i <= sum_in->end; i++)
		sum_result = sum_result + i;

	sum[sum_in->myid] = sum_result;
	pthread_exit(NULL);
}

int main()
{
	pthread_t mysum[NUM_THREAD];

	struct thread_sum sum_main[NUM_THREAD];

	int thread_result;
	int i=0;
	long long sum_result_main=0;



	for(i=0; i<NUM_THREAD; i++)
	{
		sum_main[i].myid = i;
		sum_main[i].start = (summ/NUM_THREAD)*i+1;
		sum_main[i].end = (summ/NUM_THREAD)*(i+1);

		pthread_create(&mysum[i], NULL, myfunc, &sum_main[i]);
	}

	for(i=0; i<NUM_THREAD; i++)
	{
		pthread_join(mysum[i],NULL);
		sum_result_main = sum_result_main + sum[i];
		printf("%i is sum : %lld \n",i,sum[i]);
	}
	printf("%lld is sum of number \n",sum_result_main);

	return 0;
}

