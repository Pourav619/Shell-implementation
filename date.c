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

void printdate(){    
    time_t tim;
    time(&tim);
 
    printf("Current date\n");
    printf("%s",ctime(&tim));
	return;
}

int main(int argc,char **argv){
    // long number = strtol(argv[1],0,0);
    // printf("%s",argv[0]);
    printdate();
    return 0;
}