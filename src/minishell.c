#include<stdio.h>
#include<stdlib.h>

#define BUFFER 1024
int main(int argc, char * argv[]){

//Phase 1
	int bufsize = BUFFER;
	int position = 0;
	char *buffer = malloc(sizeof(char) *bufsize);
	char *line;

	if(!buffer){
		fprintf(stderr, "Allocation Error\n");
		exit(EXIT_FAILURE);
	}
	int c;
	while(1){
		c = getchar();
		if( c == EOF || c=='\n'){
			buffer[position] = '\0';
			line =  buffer;
		}else{
			buffer[position] =c;
		}
	position++;
		if(position >=bufsize){
			bufsize += BUFFER;
			buffer = realloc(buffer, bufsize);
			if(!buffer){
				fprintf(stderr,"Allocation Error\n");
				exit(EXIT_FAILURE);
			}//inner If
		}//outer if
	}//while
//End of Phase1

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

