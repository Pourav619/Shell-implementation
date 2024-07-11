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
void printrm(char** parsed){
	if(remove(parsed[1])==0){
		printf("Deleted successfully");
	}
	// else
	// 	printf("Error");
}
int main(int argc, char *argv[])
{
	// printf(argv[1]);
    printrm(argv);
    return 0;
}
