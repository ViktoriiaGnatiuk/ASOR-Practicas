#include <stdio.h>
#include <iostream>
#include <sstream>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

volatile int contInt = 0;
volatile int contTstp = 0;

void hler(int senial){
  if (senial == SIGINT) contInt++;
  if (senial == SIGTSTP) contTstp++;
}
/*
SIG_BLOCK
    The resulting set will be the union of the current set and the signal set pointed to by set.
SIG_SETMASK
    The resulting set will be the signal set pointed to by set.
SIG_UNBLOCK
    The resulting set will be the intersection of the current set and the complement of the signal set pointed to by set.
*/
int main(int argc, char* argv[]) {
    
     struct sigaction act;

  //Sigint
  sigaction(SIGINT, NULL, &act); //Get handler
  act.sa_handler = hler;
  sigaction(SIGINT, &act, NULL); //Set sa_handler
  //Sigtstp
  sigaction(SIGTSTP, NULL, &act); //Get handler
  act.sa_handler = hler;
  sigaction(SIGTSTP, &act, NULL); //Set sa_handler


  sigset_t set;
	sigemptyset(&set);

	while ((contInt + contInt) < 10)
		sigsuspend(&set);
    std::cout << std::endl;
    std::cout << "Se han recibido " << contInt << " señales tipo SIGINT" << std::endl;
    std::cout << "Se han recibido " << contTstp << " señales tipo SIGTSTP" <<std::endl;
    return 0;
}
