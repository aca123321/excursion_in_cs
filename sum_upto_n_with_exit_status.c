#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t child_pid = 0, original_pid = getpid();
  bool already_spawned_child = false;

  int n = 10, status = 1;
  fprintf(stdout, "ORIGINAL PID:%d\n", original_pid);

  for (int i = 1; i <= n; i++) {
    fprintf(stdout, "AT :%d with pid: %d\nalready spawned child?: %s\n", i, getpid(), already_spawned_child ? "Y" : "N");

    if (!already_spawned_child) {
      child_pid = fork();
      if (child_pid > 0) {  // just spawned a child
        already_spawned_child = true;
        wait(&status);
        int child_exit_status = WEXITSTATUS(status);
        fprintf(stdout, "RETURNING STATUS: %d from pid: %d\n", i + child_exit_status, getpid());
        if (getpid() != original_pid) {
          exit(i + child_exit_status);
        } else {
          fprintf(stdout, "RESULT: %d\n", i + child_exit_status);
        }
      }
    } else {
      break;
    }
  }

  return 0;
}
