/************
 Name-Ricky Hempel
 Date-Feb 26 2018
 Purpose-Shell program
***/

//libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>

//prototypes
char **parseit(char *);
void forker(char *);
void c_exit(int);

int time_opt = 1;//defaults to show time

int main(){
  char command[80]; //character array for user command

  printf("Enter 1 to display time, 0 to not dislpay time: \n");

  printf(":> ");

  signal(SIGINT, c_exit);

  //promts user, reads in user selection
  fgets(command, 80, stdin);

  //declaring an integer to represent the value from the string comparison
  int val=strcmp(command,"quit\n");
  int in=strcmp(command,"exit\n");
  /*The while loop loops until the value from the comparison equals zero.
   *When val equals zero, the user has entered "quit" or "exit".*/
  while(val != 0 && in != 0){
    printf("\nYou entered: %s", command);

    if(!strcmp(command,"0\n"))
      time_opt = 0; //if user does not want time shown
    else if(!strcmp(command,"1\n"))
      time_opt = 1;//if user does want time shown

    //printing the command entered by the user
    else
      forker(command);

    printf("\n>: ");

    //reading new command from the user
    fgets(command, 80, stdin);

    //setting val to the same string comparison
    val = strcmp(command,"quit\n");
    in = strcmp(command,"exit\n");

  }

  //prints when the user has chosen to exit the program
  printf("Exiting program.\n");

  return 0;
}

void forker(char *command){
  pid_t pid;
  clock_t start = clock();
  int status;
  int fd1;
  int out = 0;
  char **args = parseit(command);
  char output[80]; //char array to hold output from command
  char dir[1078]; //file directory

  if ((pid = fork()) < 0){ //forking child process
    printf("\nError: forking child process failed\n");
    exit(1);
  }

    else if (pid == 0){ //executing command
      for(int i = 0; args[i]!='\0';i++){
        if (strcmp(args[i],">") == 0){
          args[i]=NULL;
          strcpy(output,args[i+1]);
          out=2;
        }
        /*loops through parsed command to find >.
         * If found, copies the next element of args to output
         */
      }

      if (out){
        if((fd1 = creat(output, 0644)) < 0){
          perror("\nCouldn't open file.\n"); //error message if file can't be accessed
          exit(1);
        }

        dup2(fd1,STDOUT_FILENO);
        close(fd1);
        //creating output file for command
      }

      if (strcmp(args[0],"cd") == 0)
        chdir(args[1]); //changes directory to user input

      else if(strcmp(args[0],"pwd") == 0){
        getcwd(dir,sizeof(dir));
        printf("\n%s\n",dir); //prints current directory
      }

      else {
        char filename[900]; //full path
        char *path = getenv("PATH");
        char *patht = strtok(path,":"); //tokenizes path
        struct stat buffer;
        int locate;
        char *file = args[0];

        while(patht != NULL){
          sprintf(filename, "%s/%s", patht, file);
          locate = stat(filename, &buffer); //locates the file

          if(locate == 0 && (S_IFREG & buffer.st_mode)){
            printf("The file was found: %s\n", filename);
			  execve(filename, &args[0], NULL);
          }
          //if file is found, print file name, call execve

          patht = strtok(NULL, ":");
        }
      }
    }
 else{
   while (wait(&status) != pid);

   clock_t end = clock();
   double time_spent = (double)(end-start)/CLOCKS_PER_SEC; //time in seconds as dou

   if(time_opt == 1)//displays time only if user chooses
     printf("\nThat command took %f seconds to run.\n", time_spent);
 }
}


char **parseit(char *command){
  char **token = malloc(100); //allocating memory for command
  char *space = " "; //tokenizing by space
  int count = 0;

  //removing newline character
  command[strlen(command)-1] = '\0';

  //putting tokenized command into char** array
  token[count] = strtok(command,space);

  //while the end of the array has not been reached
  //tokenize flags
  while(token[count] != '\0')
    token[++count] = strtok(NULL,space);

  //set last position to NULL
  token[++count] = NULL;

  return token;

}

void c_exit(int csignal){
  printf("\nGoodbye!\n"); //signal handling control-c
  signal(csignal,SIG_IGN);
  exit(0);
}



