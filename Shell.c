#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<readline/readline.h>
#include<readline/history.h>
#include<dirent.h>
#include<errno.h>
#include<pthread.h>
#include<time.h>
#include<sys/stat.h>

void printdir()
{
	char h[1024];
	getcwd(h, sizeof(h));
	printf("\nDir: %s", h);
}

void external(char** parsed)
{
	// printf("ls");
	pid_t pid = fork();
	int g=0;

	if (pid == -1) {
		printf("\nError making child..");
		return;
	} else if (pid == 0 || pid>0) {
		if(strcmp(parsed[0],"date")==0){
			char *args1[]={"./date",NULL};
			execvp(args1[0], args1);
			if (execvp("./date", parsed) == 0) {
				printf("\nCould not execute command..");
				return;
		}}
		else if(strcmp(parsed[0],"ls")==0){
			if(parsed[1]!=NULL){
			char *args1[]={"./ls",parsed[1],NULL};
			execvp(args1[0], args1);}
			else{
				char *args1[]={"./ls",NULL};
				execvp(args1[0], args1);}
			
			if (execvp("./ls.c", parsed) == 0) {
				printf("\nCould not execute command..");
			}
			return;
		}
		
		else if(strcmp(parsed[0],"cat")==0){
			char *args1[]={"./cat",parsed[1],parsed[2],NULL};
			execvp(args1[0], args1);
			if (execvp("./cat.c", parsed) == 0) {
				printf("\nCould not execute command..");
				return;
		}
		}
		else if(strcmp(parsed[0],"rm")==0){
			char *args1[]={"./rm",parsed[1],NULL};

			if(strcmp(parsed[1],"-i")==0){
				printf("rm: remove regular empty file? Press y for yes, n for n.");
				char* r;
				scanf("%c",r);
				if(strcmp(r,"y")==0){
					char *args1[]={"./rm",parsed[2],NULL};
					execvp(args1[0], args1);
				}
				else{
					return;
				}
			}
			else{
			execvp(args1[0], args1);
			}

			if (execvp(args1[0], parsed) == 0) {

				printf("\nCould not execute command..");
		}
		return;
		}
		else if(strcmp(parsed[0],"mkdir")==0){
			char *args1[]={"./mkdir",parsed[1],NULL};
			execvp(args1[0], args1);
			if (execvp("mkdirfunction.c", parsed) ==0) {
				printf("\nCould not execute command..");
		}
		return;
		}
		exit(0);
	} else {
		wait(NULL);
		return;
	}
}
void* thre(void * ptr)
{
	// printf("%s", (char *)ptr);

	if(strcmp((char *)ptr,"date")==0){
		system("./date");}
	else if(strcmp((char *)ptr,"ls")==0){
		system("./ls");
	}
	else if(strcmp((char *)ptr,"mkdir")==0){
		char o[32] = { 0 };
		int t = 0;
		ptr=ptr+6;
		sprintf(o, "./mkdir %s",(char *)ptr);
		t = system(o);
		if (t == 0)
			printf("Directory created successfully\n");
		else
			printf("Error, not able to create directory\n");
	}
	else if(strcmp((char *)ptr,"cat")==0){
		printf("cat executing");
		char o[32] = { 0 };
		int t = 0;
		ptr=ptr+4;
		sprintf(o, "./cat %s", (char *)ptr);

		t = system(o);

		if (t == 0)
			printf("Directory viewed successfully\n");
		else
			printf("Error!\n");
	}
	else if(strcmp((char *)ptr,"rm")==0){
		printf("rm executing");
		char o[32] = { 0 };
		int t = 0;
		ptr=ptr+4;
		sprintf(o, "./rm %s", (char *)ptr);
		t = system(o);
		if (t == 0)
			printf(" removed successfully\n");
		else
			printf("Error, not removed\n");
	}
}
  
void thr(char* * parse)
{
    pthread_t ptid;
  
	printf("Using thread \n");
	void *ptr = *parse;
    pthread_create(&ptid, NULL,&thre ,ptr);
  
    pthread_join(ptid, NULL);
  
    pthread_exit(NULL);
}

int mine(char** parsed)
{
	int cmd = 4, check = 0;
	char* internal[cmd];
	int k=0;
	while(parsed[k]!=NULL)
		k++;
	internal[0] = "exit";
	internal[1] = "cd";
	internal[2] = "echo";
	internal[3] = "pwd";
	for (int i = 0; i < cmd; i++) {
		if (strcmp(parsed[0], internal[i]) == 0) {
			check = i + 1;
			break;
		}
	}

	switch (check) {
	case 1:
		if(parsed[1]!=NULL){
		if(strcmp(parsed[1],"--help")==0)
			printf("Exits the shell");}
		else{
		printf("\nBye\n");
		exit(0);}
	case 2:
		if(strcmp(parsed[1],"~")==0)
			chdir("/home");
		else
			chdir(parsed[1]);
		return 1;
	case 3:
		// char arr_size = sizeof(parsed)/sizeof(parsed[0]);
		if(strcmp(parsed[1],"-e")==0){
			int j=2;
			while(parsed[j]!=NULL)
				printf("%s",parsed[2]);}
		else if(strcmp(parsed[1],"*")==0){
			pid_t sid = fork();
			char *args1[]={"./ls",parsed[1],NULL};
			execvp(args1[0], args1);
		}
		else{
		for(int i=1;i<k;i++)
			printf("%s ", parsed[i]);}
		return 1;
	case 4:
		printdir();
		return 1;
	default:
		break;
	}
	return 0;
}

void space(char* str, char** parsed)
{
	int i;
	for (i = 0; i < 100; i++) {
		parsed[i]=strsep(&str, " ");
		if (parsed[i]== NULL)
			break;
		if (strlen(parsed[i])== 0)
			i--;
	}
}

int first(char* str, char** parsed)
{
	space(str, parsed);

	if (mine(parsed))
		return 0;
	else
		return 1;
}

int main(void)
{
	char inputString[100], *List[100];
	int bin = 0;
	int i=0;
	char *p;
	printf("\nMy shell\n");
	int k=0;
	char inp[100];
	char *strinp[100];

	while (1) {
		printdir();
		printf("\n");
		// printf("s%s",inp);
		fgets(inp, 100, stdin);
		int size= strlen(inp);
		inp[size-1]='\0';
		if(strcmp(inp,"")==0){
			printf("Error, enter something!");
			continue;}
		bin=first(inp,List);
		char **s=List;
		int k=0;
		while(s[k]!=NULL)
			k++;
		if( strcmp(s[k-1],"&t")==0)
			thr(List);
		else{
		 if (bin==1)
			external(List);
		}
	}
	return 0;
}
