#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t child_pid;

  child_pid = fork();
  int status = 1;

  if (child_pid < 0) {  // error
    fprintf(stderr, "Failed to create the child process\n");
  } else if (child_pid == 0) {  // child process
    fprintf(stdout, "Child process with pid: %d and parent process pid: %d\n", getpid(), getppid());
    exit(2);
  } else {  // parent process
    wait(&status);
    fprintf(stdout, "Parent process with pid: %d waited on child with pid: %d and status: %d\n", getpid(), child_pid, WEXITSTATUS(status));
  }
  return 0;
}
