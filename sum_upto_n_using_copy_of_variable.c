#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t child_pid = 0;

  int n = 10, sum = 0;

  for (int i = 1; i <= n; i++) {
    fprintf(stdout, "proc %d: pid: %d\n", i, getpid());
    sum += i;
    child_pid = fork();
    if (child_pid > 0) {  // just spawned a child
      wait(NULL);
      exit(0);
    } else if (i == n) {  // in child process
      fprintf(stdout, "RESULT from pid: %d => %d\n", getpid(), sum);
    }
  }
  return 0;
}
