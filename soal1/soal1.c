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

int main() {
  pid_t child_id;
  int status;

  child_id = fork();

  if (child_id < 0) {
    exit(EXIT_FAILURE); 
  }

  if (child_id == 0) {
    char *argv[] = {"mkdir", "Musyik", NULL};
    execv("/bin/mkdir", argv);
  } 

  else {
    while ((wait(&status)) > 0);
    child_id = fork();

    if (child_id < 0) {
      exit(EXIT_FAILURE); 
    }

    if (child_id == 0) {
      char *argv[] = {"mkdir", "Fylm", NULL};
      execv("/bin/mkdir", argv);
    } 

    else {
      while ((wait(&status)) > 0);
      child_id = fork();

      if (child_id < 0) {
        exit(EXIT_FAILURE); 
      }

      if (child_id == 0) {
        char *argv[] = {"mkdir", "Pyoto", NULL};
        execv("/bin/mkdir", argv);
      } 
    
      else{
	while ((wait(&status)) > 0);
        child_id = fork();

        if (child_id < 0) {
          exit(EXIT_FAILURE); 
        }

        if (child_id == 0) {
          char *argv[] = {"wget", "--no-check-certificate", "https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download", "-O", "Foto.ext", NULL};
	execv("/usr/bin/wget", argv);
        } 

	else{
	  while ((wait(&status)) > 0);
          child_id = fork();

          if (child_id < 0) {
            exit(EXIT_FAILURE); 
          }

          if (child_id == 0) {
            char *argv[] = {"wget", "--no-check-certificate", "https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download", "-O", "Musik.ext", NULL};
	    execv("/usr/bin/wget", argv);
          }
	  else{
	    while ((wait(&status)) > 0);
            child_id = fork();

            if (child_id < 0) {
              exit(EXIT_FAILURE); 
            }

            if (child_id == 0) {
              char *argv[] = {"wget", "--no-check-certificate", "https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download", "-O", "Film.ext", NULL};
	      execv("/usr/bin/wget", argv);
            }
	    else{
	    }
	  }
	}
      }
    }
  }
}
