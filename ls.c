
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<readline/readline.h>
#include<readline/history.h>
// #include "ls.h"
// #include "date.h"
// #include "rmfunction.h"
// #include "mkdirfunction.h"
// #include "cat.h"
#include<dirent.h>
#include<errno.h>
#include<pthread.h>
#include<time.h>
#include<sys/stat.h>

//For ls command
void printls(char **argv){
	struct dirent *d;
	DIR *dh = opendir(".");
	while((d= readdir(dh)) !=NULL){
		if(argv[1]!=NULL){
			if(strcmp(argv[1],"-1")==0){
				if(strcmp(d->d_name,".")!=0 &&strcmp(d->d_name,"..")!=0){
					printf("%s", d->d_name);
					printf("\n");
				}
			}
			else if(strcmp(argv[1],"-a")==0){
				printf("%s", d->d_name);
					printf("  ");

			}}
			else{
				if(strcmp(d->d_name,".")!=0 &&strcmp(d->d_name,"..")!=0){
					printf("%s", d->d_name);
					printf("  ");
				}
			}
			// printf("yo");
	}
	printf("\n");
	return;
}

int main(int argc, char *argv[])
{
	// printf("%s",argv[1]);
    printls(argv);
    return 0;
}