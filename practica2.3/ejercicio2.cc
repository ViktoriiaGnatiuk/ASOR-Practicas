#include <stdio.h>
#include <iostream>
#include <errno.h>
#include <string>
#include <sched.h>
int main(int argc, char* argv[]) {
    int resultado = sched_getscheduler(0);
	if(resultado == -1){
		perror("sched_getscheduler");
		return -1;	
	}
    std::cout <<"Política: " << resultado << std::endl;

    struct sched_param parametro;
    if(sched_getparam(0, &parametro) == -1){
		perror("sched_getscheduler");
		return -1;	
	}
    std::cout << "Parametro: " << parametro.sched_priority << std::endl;

    //No se como traducir el número de la politica que me da la primera función a cadena
    int max = sched_get_priority_max(SCHED_FIFO);
    int min = sched_get_priority_min(SCHED_FIFO);
    std::cout << "Max: " << max << std::endl;
    std::cout << "Min: " << min << std::endl; 
	return 0;
}
