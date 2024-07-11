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

//For cat command
// void printcat(char** f){
// 	FILE* fr;
// 	const char* k=(const char*) f;
// 	char c;
// 	fr=fopen(k,"r");
// 	// if(!fr){
// 	// 	printf("Error");
// 	// }
// 	while((c=fgetc(fr))!=EOF){
// 		printf("%c",c);
// 		// printf("hgchghgdjyfsxsgfxtsjgxnghfxjyd");
// 	}
// 	fclose(fr);
// 	return;
// }

int main(int argc,char *argv[]){
	FILE* pt;
	pt=fopen(argv[1],"r");
	char k;
	if(!pt || argc !=2){
		printf("An error occurred");
	}
	while((k=fgetc(pt))!=EOF){
		printf("%c",k);
	}
	fclose(pt);
	// printcat(argv);
}