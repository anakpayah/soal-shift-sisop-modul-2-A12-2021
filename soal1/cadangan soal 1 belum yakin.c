#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <pwd.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <grp.h>
#include <fcntl.h>
#include <wait.h>
#include <time.h>



int main() 
{
  
  time_t w, t;  
  pid_t pid, sid ;     
  char birthday[100] , etc[100]; 
  struct tm *tm, *wm;
  
    pid_t child_id = fork();
    pid = fork();  

 
 if (pid > 0) 
   { exit(EXIT_SUCCESS) ;}
 if (pid < 0) 
   { exit(EXIT_FAILURE) ;}
 


 umask(0);

 sid = setsid() ;

 if (sid < 0) 
     { exit(EXIT_FAILURE) ;}
 

 close(STDIN_FILENO) ;
 close(STDERR_FILENO) ;
 close(STDOUT_FILENO) ;

 char *Link[3] = {
        "https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download",
        "https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download",
        "https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download"
  };

 while(1) { 

   pid_t cid1, cid2, cid3, cid4, cid5, cid6, cid7, cid8, cid9, cid10, cid11, cid12, cid13, cid14;
   
//set 6 jam sebelum ultah//
    w = time(NULL);
        wm = localtime(&w);
        strftime(birthday, 60, "%d-%m-%Y_%H:%M:%S", wm);
        if(strcmp(birthday,"09-04-2021 16:22:00") == 0)
        {
//dir musyik//
             cid1 = fork();
             if (cid1 < 0)exit(0);
             if (cid1 == 0) {
                char *argv[] = {"mkdir" , "-p" , "musyik", NULL};
                 execv("/bin/mkdir", argv);}
            while(wait(NULL) != cid1);
 //get musik//
            cid2 = fork();
            if (cid2 < 0)exit(0);
            if (cid2 == 0) {
                char *args[] = {"wget" , "--no-check-certificate" , "-q", Link[1],"-O", "Musik_for_Stevany.zip", NULL};
                execv("/usr/bin/wget", args) ;}
            while(wait(NULL) != cid2) ;   
 //unzip musik
            cid3 = fork();
            if (cid3 == 0) 
            if (cid3 < 0)exit(0);{
                char *argv[] = {"unzip", "-q" , "Musik_for_Stevany.zip" , NULL};
                execv("/usr/bin/unzip", argv);}
            while(wait(NULL) != cid3); 
//move to musyik
            cid4 = fork();
            if (cid4 < 0)exit(0);
            if (cid4 == 0) {
            char *argv[] = {"find","MUSIK","-type","f","-name","*", "-exec","mv","-t","Musyik/","{}","+",NULL};
               execv("/bin/find", argv);}
            while(wait(NULL) != cid4);                                 
//dir pyoto//
            cid5 = fork();
            if (cid5 < 0)exit(0);
            if (cid5 == 0) {
                char *argv[] = {"mkdir" , "-p" , "pyoto", NULL};
                 execv("/bin/mkdir", argv);}
            while(wait(NULL) != cid5);
 //get foto//
            cid6 = fork();
            if (cid6 < 0)exit(0);
            if (cid6 == 0) {
                char *args[] = {"wget" , "--no-check-certificate" , "-q", Link[0], "-O", "Foto_for_Stevany.zip", NULL};
                execv("/usr/bin/wget", args);}
            while(wait(NULL) != cid6);
  //unzip foto
            cid7 = fork();
            if (cid7 == 0) 
            if (cid7 < 0)exit(0);{
                char *argv[] = {"unzip" , "-q" , "Foto_for_Stevany.zip" , NULL};
                execv("/usr/bin/unzip", argv);}
            while(wait(NULL) != cid7);         
//move to pyoto
            cid8 = fork();
            if (cid8 < 0)exit(0);
            if (cid8 == 0) {
            char *argv[] = {"find","FOTO","-type","f","-name","*", "-exec","mv","-t","Pyoto/","{}","+",NULL};
                execv("/bin/find", argv);}
            while(wait(NULL) != cid8);
//dir fylm//
            if (cid9 < 0)exit(0);
            if (cid9 == 0) {
                char *argv[] = {"mkdir" , "-p" , "fylm", NULL};
                 execv("/bin/mkdir", argv);}
            while(wait(NULL) != cid9);            
//get film//
            cid10 = fork();
            if (cid10 < 0)exit(0);
            if (cid10 == 0) {
                char *args[] = {"wget" , "--no-check-certificate" , "-q", Link[2], "-O", "Film_for_Stevany.zip", NULL};
                 execv("/usr/bin/wget", args);}
            while(wait(NULL) != cid10);  

//unzip film
            cid11 = fork();
            if (cid11 == 0)
            if (cid11 < 0)exit(0); {
                char *argv[] = {"unzip", "-q", "Film_for_Stevany.zip", NULL};
                execv("/usr/bin/unzip", argv);}
            while(wait(NULL) != cid11);
       

//move to fylm
            cid12 = fork();
            if (cid12 == 0) {
            char *argv[] = {"find","FILM","-type","f","-name","*", "-exec","mv","-t","Fylm/","{}","+",NULL};
               execv("/bin/find", argv);}
            while(wait(NULL) != cid12);

        }     
    }
    while (1) {
//ultah rename
        w = time(NULL);
        wm = localtime(&w);
        strftime(birthday, 60, "%d-%m-%Y_%H:%M:%S", wm);
        if(strcmp(birthday,"09-04-2021 22:22:00") == 0)
        
        {
            child_id = fork();
            if (child_id == 0) {
                char *argv[] = {"zip", "-r", "Lopyu_Stevany.zip", "Fylm", "Musyik", "pyoto", NULL};
                execv("/usr/bin/zip", argv);}
            while(wait(NULL) != child_id);
            child_id = fork();
            if (child_id == 0) 
            {  char *argv[] = {"rm", "-r",  "FILM", "MUSIK", "FOTO", "Fylm",  "Musyik",  "Pyoto", NULL};
                execv("/bin/rm", argv);}
            while(wait(NULL) != child_id);
            break;

        }
    }
  }


