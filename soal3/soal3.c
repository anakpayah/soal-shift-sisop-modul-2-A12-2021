#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <wait.h>
#include <time.h>

void makeDirectory();
void downloadPics(char dirName[]);
void makeText(char dirName[]);
void caesarChiper(char text[]);
void zipping(char dirName[]);
void killer(int pid, int mode);

int main(int argc, char **argv) {
	int pid = (int)getpid();
	
	if (strcmp (argv[1], "-z")== 0) killer(pid, 0);
	
	else if (strcmp (argv[1], "-x")== 0) killer(pid, 1);
	
	else 
		return 0;	
	
	while (1) makeDirectory();

	return 0;
}

void makeDirectory() {
	int status;
	char timeForm[20];
	time_t sekarang = time(NULL);
	struct tm *waktu = localtime(&sekarang); 
		
	strftime (timeForm, sizeof(timeForm), "%Y-%m-%d_%H:%M:%S", waktu);
    	
	pid_t child_id;
	child_id = fork();
		
	if (child_id < 0)
		exit (EXIT_FAILURE);
	if (child_id == 0) {
		char *argv[] = {"mkdir", timeForm, NULL};
		execv ("/bin/mkdir", argv);
	}
		
	child_id = fork();

	if (child_id < 0)
		exit(EXIT_FAILURE);
	if (child_id == 0) {
		while(wait(&status) > 0);
		downloadPics(timeForm);
	}
		sleep(40);    	
	return;
}

void downloadPics(char dirName[]) {
	int i, maxPics = 10;
	for (i=0 ; i<maxPics ; i++) {
	
		pid_t child_id;
		child_id = fork();
				
		char downLink[1000], link[] = "https://picsum.photos/";		
		char fileName[20];
		time_t sekarang = time(NULL);
		int now = (int)sekarang;
		int size = (now%1000)+50;
		struct tm *waktu = localtime(&sekarang); 
		
		strftime (fileName, sizeof(fileName), "%Y-%m-%d_%H:%M:%S", waktu);		
		sprintf(downLink, "%s%d", link, size);
		
		char filePath[50];
		sprintf (filePath, "%s%c%s%s", dirName, '/', fileName, ".jpeg");
		
		if (child_id < 0)
        	exit (EXIT_FAILURE);
    	if (child_id == 0) {
        	char *argv[] = {"wget", "-q", "--no-check-certificate", downLink, "-O", filePath, NULL};
        	execv ("/bin/wget", argv);
    	}
    	sleep(5);		
	}
	makeText(dirName);
	zipping(dirName);
	return;
}

void makeText(char dirName[]) {
	char text[20], statusPath[50];
	sprintf (statusPath, "%s%c%s", dirName, '/', "status.txt");
	caesarChiper(text);
	FILE *statusText = fopen(statusPath, "w");
	fprintf(statusText, "%s", text);
	fclose(statusText);
	return;
}

void zipping(char dirName[]) {
	char zipName[50];
	sprintf (zipName, "%s%s", dirName, ".zip");


	char *argv[] = {"zip", "-rmqq", zipName, dirName, NULL};
	execv("/bin/zip", argv);
	
	return;
}

void caesarChiper(char text[]) {
	char string[]="Download Success";
	int i;
	for (i=0 ; string[i] != '\0'; i++) {
		if(string[i] == ' ') text[i] = ' ';
		else if(string[i] >= 'a' && string[i] <= 'z'){
			string[i] += 5;			
			if(string[i] > 'z'){
				string[i] = string[i] - 'z' + 'a' - 1;
			}			
			text[i] = string[i];
		}
		else if(string[i] >= 'A' && string[i] <= 'Z'){
			string[i] += 5;			
			if(string[i] > 'Z'){
				string[i] = string[i] - 'Z' + 'A' - 1;
			}			
			text[i] = string[i];
		}	
	}
	text[i++]='\0';
	return;
}

void killer(int pid, int mode) {
	FILE *killer = fopen("killer.sh", "w");
	char exe[1001];
	if (mode == 0) {
		sprintf (exe, "%s", "#!/bin/bash\npkill -9 soal3\nrm killer.sh");
		fprintf(killer, "%s", exe);
		fclose(killer);
		return;
	}
	else if (mode == 1) {
		sprintf (exe, "%s%d%s", "#!/bin/bash\nkill ", pid, "\nrm killer.sh");
		fprintf(killer, "%s", exe);
		fclose(killer);
		return;
	}
	printf ("gagal");
	return;
}
