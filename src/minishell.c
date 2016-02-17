#include<stdio.h>
#include<stdlib.h>

int main(int argc, char * argv[]){


	printf("minishell>");
	pid_t pid;
	int status;

	pid= fork();
	if(pid==0){
		if(execvp(argv[0], argv) == -1){
			printf("Error");
		}
	exit(1);
	} else if(pid < 0){
		printf("Error");
	}else{
		do{
		waitpid(pid, &status, WUNTRACED);
		}while(!WIFEXITED(status) && !WIFSIGNALED(status));
	}

return 0;
}

