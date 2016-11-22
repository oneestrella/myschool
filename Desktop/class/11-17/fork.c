#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>


int main(int agrc, char argv[])
{
	pid_t pid;
	int status;
	int i,j;
	int child_status;

	pid = fork();
	
	switch(pid)
	{
		case 0: //child
			printf("[%ld]this is child \n",(long)getpid());
			execl("/bin/ps","ps","-ef",NULL);
			printf("%s \n",argv[1]);

//			for(i=1; i<=1000; i++)
//			{
//				printf("%d -child process \n",i);
//				fflush(NULL);
//			}
			exit(0);
			break;
		case -1:
			perror("error!");
			exit(0);
		default:
			printf("[%ld]this is parent \n",(long)getpid());
//			for(j=1; j<=1000; j++)
//			{
//				printf("%d -parent proccess \n",j);
//				fflush(NULL);
//			}
//			for(;;){};
			wait(&status);		//wait till child proccess is end
			printf("[%ld]status code : %d \n",(long)getpid(),WEXITSTATUS(child_status));
			break;
	}


}
