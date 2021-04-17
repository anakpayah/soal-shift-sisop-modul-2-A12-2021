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
  int status;
  pid_t pid, sid;        // Variabel untuk menyimpan PID

  pid = fork();     // Menyimpan PID dari Child Process

  pid_t child_id;

  /* Keluar saat fork gagal
  * (nilai variabel pid < 0) */
  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  /* Keluar saat fork berhasil
  * (nilai variabel pid adalah PID dari child process) */
  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  umask(0);

  sid = setsid();
  if (sid < 0) {
    exit(EXIT_FAILURE);
  }

  /*if ((chdir("/")) < 0) {
    exit(EXIT_FAILURE);
  }*/	

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  
  while (1) {
    char *argv[][4] = {
      {"/bin/mkdir", "Musyik", NULL},
      {"/bin/mkdir", "Fylm", NULL},
      {"/bin/mkdir", "Pyoto", NULL},
    };
    for (int idx = 0; idx < 3; idx ++)
    {
      if (0 == fork()) continue;
      execve(argv[idx][0], &argv[idx][0], NULL);
    }
    sleep(30);
  }
}
