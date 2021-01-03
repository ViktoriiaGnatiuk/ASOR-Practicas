#include <stdio.h>
#include <iostream>
#include <sstream>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

volatile int stop = 0;

void hler(int senial){
  if (senial == SIGUSR1) stop = 1;
}

int main(int argc, char* argv[]) {
  sigset_t mask;
  sigemptyset(&mask);
	sigaddset(&mask, SIGUSR1);
  sigprocmask(SIG_UNBLOCK, &mask, NULL);

  struct sigaction act;
  sigaction(SIGUSR1, NULL, &act); 
  act.sa_handler = hler;
  sigaction(SIGUSR1, &act, NULL);

    int secs = atoi(argv[1]);
    int i = 0;
	while (i < secs && stop == 0) {
    i++;
    sleep(1);
  }

  if (stop == 0) {
    std::cout << "Se ha eliminado el fichero " << argv[0] << std::endl;
    unlink(argv[0]);
  }

  return 0;
}
