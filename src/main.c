/*
  Licensed under the Apache License, Version 2.0 (the "License"); you may not
  use this file except in compliance with the License. You may obtain a copy of
  the License at
  
  http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
  License for the specific language governing permissions and limitations under
  the License.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

/* Release version */
char PROG[] = "Couch Shell (cosh)";
char VERSION[] = "v0.0.1a";

/* Command number and char reader for prompt line */
int  PNUM = 1;
char PC = '\0';

/* Functions for command prompt */
void show_prompt() {
  printf("%d> ", PNUM++);
}

void show_intro() {
  printf("\n%s %s [^D to quit]\n\n", PROG, VERSION);
  show_prompt();
}

/* Signal handler for Ctl-C */
typedef void (*sighandler_t)(int);

void handle_signal(int signum) {
  printf("\n");
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
