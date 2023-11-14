#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <unistd.h>

#include <sys/wait.h>


void error_and_exit(const char * error) {

  printf("ERROR : %s\n", error);

  exit(1);

}

int main(int argc, char * argv[]) {

  const char * url = argv[1];

  const int PORT = atoi(argv[2]);

  pid_t pid = fork();

  int status;

  if (pid == 0) {

    if (execlp("./fetch", "./fetch", argv[1]) < 0) {

      error_and_exit("Couldn't fetch webpage\n");

    }

  } else {

    wait( & status);

    printf("Head over to http://192/168.1.200:%d\n", PORT);

    if (execlp("./share", "./share", argv[2], "./temp.html") < 0) {

      error_and_exit("Error Serving\n");

    }

  }

  return 0;

}
