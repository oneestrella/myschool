#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>


struct two_double{

	double a;
	double b;
}data;


void ouch(int sig)
{
	printf("ouch!! \n");
	printf("signal is %d \n",sig);
}

void goodbye(int sig)
{
	printf("goodbye \n");
	printf("signal is %d \n",sig);
}

void alrm(int sig)
{
	//waitting = 0;
	//printf("alarm arrived!@ \n");
	printf("pid is %d \n",(long)getpid());
	printf("%f, 	%f 	\n",data.a, data.b);
	printf("signal is %d \n",sig);
	alarm(1);
}

int main()
{
	sigset_t block_set,prev_set;


	struct sigaction sa_int;
	struct sigaction sa_term;
	struct sigaction sa_alrm;

	static struct two_double zeros={0.0,0.0}, ones = {1.0,1.0};

	sigemptyset(&sa_int.sa_mask);
	sa_int.sa_flags = 0;
	sa_int.sa_handler = ouch;
	if(sigaction(SIGINT,&sa_int,NULL)==-1)
	{
		perror("sigaction");
		exit(0);
	}

	sigemptyset(&sa_term.sa_mask);
	sa_term.sa_flags = 0;
	sa_term.sa_handler = goodbye;
	if(sigaction(SIGTERM,&sa_term,NULL)==-1)
	{
		perror("sigaction");
		exit(0);
	}
	

	sigemptyset(&sa_alrm.sa_mask);
	sa_alrm.sa_flags = 0;
	sa_alrm.sa_handler = alrm;
	if(sigaction(SIGALRM,&sa_alrm,NULL)==-1)
	{
		perror("sigaction");
		exit(0);
	}
	
	
	data = zeros;
	alarm(1);

	sigemptyset(&block_set);
	sigaddset(&block_set,SIGALRM);
	//signal(SIGINT,ouch);	
	while(1)
	{
		sigprocmask(SIG_BLOCK,&block_set,&prev_set);
		data = zeros;
		sigprocmask(SIG_SETMASK,&prev_set,NULL);
		sigprocmask(SIG_BLOCK,&block_set,&prev_set);
		data = ones;
		sigprocmask(SIG_SETMASK,&prev_set,NULL);
		//printf("pid is %d \n",(long)getpid());
		//sleep(1);
	}
	
	return 0;
}
