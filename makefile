all:
	gcc mkdirfunction.c -o mkdir
	gcc ls.c -o ls
	gcc date.c -o date
	gcc rmfunction.c -o rm
	gcc cat.c -o cat
	gcc Shell.c -lreadline -lpthread
