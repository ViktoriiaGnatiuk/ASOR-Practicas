#include <stdio.h>
#include <iostream>
#include <errno.h>
#include <string>
#include <unistd.h>
#include <sched.h>
int main(int argc, char* argv[]) {
    pid_t mi_pid, pid;
    pid = fork();
    //Crear una nueva sesión y un nuevo grupo de procesos
    pid_t sesion = setsid();
    std::cout << "Id de la sesión: " << sesion << std::endl;

    //Cambiar el directorio del proceso
    if ((chdir("/tmp")) < 0) {
        perror("chdir");
        return -1;
    }
    
    //id del proces
    pid_t id_propio = getpid();
    std::cout << "Id del proceso: " << id_propio << std::endl;
    //id del proceso padre
    pid_t id_padre = getppid();
    std::cout << "Id del padre: " << id_padre <<std::endl;
    //id del grupo
    pid_t  id_grupo = getpgid(id_propio);
    std::cout << "Id del grupo: " << id_grupo << std::endl;
    //id de sesión
    pid_t id_sesion = getsid(id_propio);
    std::cout << "Id sesión: " << id_sesion << std::endl;
    //ruta del directorio
    char* cwd;
    char buff[200];

    cwd = getcwd( buff, 200 );
    if( cwd == NULL ) {
        perror("cwd");
		    return -1;	
    }
    std::cout << "El directorio es " << cwd << std::endl;
    switch (pid) {
        case -1:{
            perror("fork");
            exit(1);
            }
        case 0:
        {
            pid_t mi_pid = getpid();
            std::cout << "Proceso hijo " << std::endl; 
        }
        break;
        default:
        {
            mi_pid = getpid();
            std::cout << "Proceso padre" << std::endl;
        }
        break;
    }
    return 0;
}
