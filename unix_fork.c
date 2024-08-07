#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid;

  int n = 10;
  pid = fork();

  if (pid < 0) {  // error
    fprintf(stderr, "Failed to create the child process\n");
  } else if (pid == 0) {  // child process
    fprintf(stdout, "Child process...\n");
    return 0;
  } else {  // parent process
    wait(NULL);
    fprintf(stdout, "Parent process...\n");
  }
  return 0;
}
