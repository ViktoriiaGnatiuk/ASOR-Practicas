#include <stdio.h>
#include <iostream>
#include <errno.h>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<ctime>
/*
cmd especifica una de las siguientes operaciones:
    ■ F_LOCK: Bloquea la región especificada del fichero, esperando hasta que
        un cerrojo incompatible previo se libere
    ■ F_TLOCK: Como F_LOCK, pero la llamada no espera, sino que devuelve -1
        (con errno=EAGAIN) si la región está bloqueada
    ■ F_ULOCK: Desbloquea la región indicada del fichero
    ■ F_TEST: Devuelve 0 si la región está desbloqueada o bloqueada por el
        proceso que llama, o -1 (con errno=EAGAIN) si la bloquea otro proceso
*/
int main(int argc, char* argv[]) {
    int descriptor = open(argv[1], O_WRONLY);
    if(descriptor == -1){
        perror("open");
        return -1;
    }

    int cerrojo = lockf(descriptor, F_TEST, 0);
    if(cerrojo == 0){
        std::cout << "El cerrojo está desbloqueado" << std::endl;
        int cerrojoCerrado = lockf(descriptor, F_LOCK, 0);
        time_t t; // t passed as argument in function time()
       struct tm * tt; // decalring variable for localtime()
       time (&t); //passing argument to time()
       tt = localtime(&t);
        if(cerrojoCerrado == -1){
            perror("cerrojoCerrado");
            return -1;
        }
        std::cout << "El cerrojo se ha bloqueado a las " <<  asctime(tt) << std::endl;
        unsigned int tiempo = sleep(30);
        int cerrojoAbierto = lockf(descriptor, F_ULOCK, 0);
        if(cerrojoAbierto == -1){
            perror("cerrojoAbierto");
            return -1;
        }
        std::cout << "El cerrojo se ha vuelto a desbloquear" << std::endl;
    }
    else{
        std::cout << "El cerrojo está bloqueado" << std::endl;
    }
    return 0;
}
