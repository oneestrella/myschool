#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

void main()
{
	int status;
	status = system("ls -l | wc");
	printf("exit code %d \n",WEXITSTATUS(status));



}
