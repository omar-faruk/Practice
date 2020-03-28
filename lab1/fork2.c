#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int i;

void f1(){
	
	pid_t pid;
	int status;
	pid=fork();
	
	if(pid==0){
		puts("nested child 1:");
		printf("nested child 1 id %d\n",getpid());
		printf("parent 1 id %d\n\n",getppid());
	}
	else{
		
		wait(&status);
		puts("terminating nested 1");
		system("xdg-open ~/1.jpg");
		exit(1);
	}
}

void f2(){
	
	pid_t pid;
	int status;
	pid=fork();
	
	if(pid==0){
		puts("nested child 2:");
		printf("nested child 2 id %d\n",getpid());
		printf("parent 2 id %d\n\n",getppid());
	}
	else{
		wait(&status);
		puts("terminating nested 2");
		exit(1);
	}
}


int main()
{
	pid_t pid;
	int status;
	
	pid = fork();
	if (pid < 0){
		printf("Process creation error");
		exit(-1);
	}
	else if(pid==0){
		sleep(10);
		puts("child process: 1");
		printf("child process id %d\n",getpid());
		printf("parent process id %d\n\n",getppid());
		puts("child msg\n\n");
		//f1();
	}
	else{
		//wait(&status);
		puts("parent msg");
		puts("parent process:");
		printf("main process id %d\n",getpid());
		printf("shell process id %d\n\n",getppid());
		//puts("creating nested child 2\n\n");
		//f2();
		//system("xdg-open ~/2.jpg");
	}

	return 0;
}
