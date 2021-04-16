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
#include <dirent.h>
#include <ctype.h>

void makeDirectory();
void downloadPics(char dirName[]);
void makeText(char dirName[]);
void caesarChiper(char text[]);

int main() {
	makeDirectory();

	return 0;
}


void makeDirectory() {
	int i, jmlh = 2;
	for (i=1 ; i<jmlh ; i++) {
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
		sleep(10);    	
	}
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
		int picsID = (now%1000)+50;
		struct tm *waktu = localtime(&sekarang); 
		
    		strftime (fileName, sizeof(fileName), "%Y-%m-%d_%H:%M:%S", waktu);		
		sprintf(downLink, "%s%d", link, picsID);
		
		char filePath[50];
		sprintf (filePath, "%s%c%s%s", dirName, '/', fileName, ".jpg");
		
		if (child_id < 0)
        	exit (EXIT_FAILURE);
    	if (child_id == 0) {
        	char *argv[] = {"wget", "-q", "--no-check-certificate", downLink, "-O", filePath, NULL};
        	execv ("/bin/wget", argv);
    	}
    	sleep(10);		
	}
	makeText(dirName);
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
