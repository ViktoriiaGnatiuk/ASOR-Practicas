#include <stdio.h>
#include <iostream>
#include <sstream>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
/*
SIG_BLOCK
    The resulting set will be the union of the current set and the signal set pointed to by set.
SIG_SETMASK
    The resulting set will be the signal set pointed to by set.
SIG_UNBLOCK
    The resulting set will be the intersection of the current set and the complement of the signal set pointed to by set.
*/
int main(int argc, char* argv[]) {
    
    sigset_t set_senales;
    sigemptyset(&set_senales);
    if(strcmp (argv[1], "1") == 0){
        //Añade una señal al conjunto
        if( sigaddset(&set_senales, SIGINT) == -1){
            perror("Se ha producido un error al añadir la señal SIGINT");
            return -1;
        }
    }else{
        //Añade una señal al conjunto
        if( sigaddset(&set_senales, SIGTSTP) == -1){
            perror("Se ha producido un error al añadir la señal SIGTSTP");
            return -1;
        }
    }
    

    if(sigprocmask(SIG_BLOCK, &set_senales, NULL) == -1){
        perror("Se ha producido un error al bloquear las señales");
        return -1;
    }

    if( setenv("SLEEP_SECS", "300", 0) == -1){
        perror("Se ha producido un error al estableces la variable de entorno");
        return -1;
    }
    char *variable = getenv("SLEEP_SECS");
    if(variable == NULL) {
        perror("No se ha encontrado la variable SLEEP_SECS");
        return  -1;
    }

    //No puedo hacer sleep porque no se como pasar de char* a unsigned int
    sleep(20);
    if(sigismember(&set_senales, SIGINT) == 1){
        std::cout << "Se ha bloqueado la señal SIGINT";
    }else if(sigismember(&set_senales, SIGTSTP) == 1){
        std::cout << "Se ha bloqueado la señal SIGTSTP";
    }else{
        std::cout << "No se ha bloqueado ninguna señal";
    }
    std::cout << std::endl;
    return 0;
}
