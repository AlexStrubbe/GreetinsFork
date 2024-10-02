#include <stdio.h>
#include <time.h>
#include <unistd.h>

/**
 * @brief Main function to demonstrate process creation and execution.
 *
 * This program demonstrates the creation of multiple processes using `fork()`.
 * Each child process may further create its own child (grandchild) processes.
 * Some child and grandchild processes will execute an external program (`greetings1`).
 *
 * The program's output includes messages indicating the process IDs of the child
 * and grandchild processes. The grandchild processes will execute an external
 * program called `greetings1`.
 *
 * @return int Exit status of the program. Returns 0 on successful completion.
 */
int main()
{
  // Create the first child process
  __pid_t p = fork();

  // Code executed by the first child process
  if (p == 0)
  {
    printf("I'm a child, my id is: '%d'\n", getpid());

    // Create a grandchild process
    __pid_t e = fork();
    if (e != 0)
    {
      e = fork(); // Create another grandchild process if the previous fork was successful
    }
    // Code executed by the grandchild processes
    if (e == 0)
    {
      printf("I'm a grandchild, my id is: '%d'\n", getpid());
      // Execute the external program `greetings1`
      execl("./greetings1", "greetings1", (char *)NULL);
    }

    _exit(0); // Terminate the child process
  }

  // Code executed by the parent process
  if (p != 0)
    p = fork(); // Create another child process

  // Code executed by the second child process
  if (p == 0)
  {
    printf("I'm a child, my id is: '%d'\n", getpid());

    // Create a grandchild process
    __pid_t e = fork();
    if (e != 0)
    {
      e = fork(); // Create another grandchild process if the previous fork was successful
    }
    // Code executed by the grandchild processes
    if (e == 0)
    {
      printf("I'm a grandchild, my id is: '%d'\n", getpid());
      // Execute the external program `greetings1`
      execl("./greetings1", "greetings1", (char *)NULL);
    }

    _exit(0); // Terminate the child process
  }

  // Code executed by the parent process
  if (p != 0)
    p = fork(); // Create another child process

  // Code executed by the third child process
  if (p == 0)
  {
    printf("I'm a child, my id is: '%d'\n", getpid());

    // Create a grandchild process
    __pid_t e = fork();
    if (e != 0)
    {
      e = fork(); // Create another grandchild process if the previous fork was successful
    }
    // Code executed by the grandchild processes
    if (e == 0)
    {
      printf("I'm a grandchild, my id is: '%d'\n", getpid());
      // Execute the external program `greetings1`
      execl("./greetings1", "greetings1", (char *)NULL);
    }

    _exit(0); // Terminate the child process
  }

  return 0;
}

