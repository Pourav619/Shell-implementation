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
void printmkdir(char** parsed){
	int m;
    m= mkdir(parsed[1],0777);
	if(!m){
		printf("Created!!");
	}
	else{
		printf("Error");
	}
}
int main(int argc, char *argv[])
{
	// printf(argv[1]);
    printmkdir(argv);
    return 0;
}

