#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

/* Release version */
char PROG[] = "Couch Shell (cosh)";
char VERSION[] = "v0.0.1";

/* Command number and char reader for prompt line */
int  PNUM = 1;
char PC = '\0';

/* Functions for command prompt */
void show_prompt() {
  printf("%d> ", PNUM++);
}

void show_intro() {
  printf("\n%s %s\n\n", PROG, VERSION);
  show_prompt();
}

/* Signal handler for Ctl-C */
typedef void (*sighandler_t)(int);

void handle_signal(int signum) {
  show_prompt();
  fflush(stdout);
}


/* MAIN event loop */
int main(int argc, char *argv[], char *envp[])
{
  /* Setup signals and print initial prompt... */
  signal(SIGINT, SIG_IGN);
  signal(SIGINT, handle_signal);
  show_intro();

  /* Start permanent REPL... */
  while (PC != EOF) {
    PC = getchar();
    if (PC == '\n')
      show_prompt();
  }
  printf("\n");
  return 0;
}
