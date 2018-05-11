//Name-Ricky Hempel
//Date-04/22/2018
//Purpose- List the files in a directory
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <time.h>
#include <sys/stat.h>
#include <grp.h>
#include <pwd.h>


void printMode(struct stat filePer){
  // I found this code on http://stackoverflow.com/questions/10323060/printing-file-permissions-like-ls-l-using-stat2-in-c

  printf( (S_ISDIR(filePer.st_mode)) ? "d" : "-");
  printf( (filePer.st_mode & S_IRUSR) ? "r" : "-");
  printf( (filePer.st_mode & S_IWUSR) ? "w" : "-");
  printf( (filePer.st_mode & S_IXUSR) ? "x" : "-");
  printf( (filePer.st_mode & S_IRGRP) ? "r" : "-");
  printf( (filePer.st_mode & S_IWGRP) ? "w" : "-");
  printf( (filePer.st_mode & S_IXGRP) ? "x" : "-");
  printf( (filePer.st_mode & S_IROTH) ? "r" : "-");
  printf( (filePer.st_mode & S_IWOTH) ? "w" : "-");
  printf( (filePer.st_mode & S_IXOTH) ? "x " : "- ");
}

int main(){
  DIR *dirp;
  struct dirent *direntp;
  dirp = opendir(".");
  
  struct stat filePer;
  while ((direntp = readdir(dirp)) != NULL){
    stat(direntp->d_name, &filePer);

    struct passwd *pwd;
    pwd = getpwuid(filePer.st_uid);

    struct group *pwd2;
    pwd2 = getgrgid(filePer.st_gid);

    time_t modDate;
    time(&modDate);
    char modDateArr[100];
    strftime(modDateArr, 100, "%b %d %y %l:%M", localtime(&(modDate)));

    printMode(filePer);
    printf("%3ld %s %s %9ld %s %s\n", filePer.st_nlink,  pwd->pw_name,
	   pwd2->gr_name, filePer.st_size, modDateArr, direntp->d_name);
  }
  (void)closedir(dirp);
  return 0;
} 

