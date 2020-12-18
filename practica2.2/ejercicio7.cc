#include <stdio.h>
#include <iostream>
#include <errno.h>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
/*
S_IRWXU      00700 propietario tiene permiso de lectura, escritura y ejecución
    S_IRUSR      00400 propietario tiene permiso de lectura
    S_IWUSR      00200 propietario tiene permiso de escritura
    S_IXUSR      00100 propietario tiene permiso de ejecución
El grupo S_IRWXG      00070 tiene permiso de lectura, escritura y ejecución
    S_IRGRP      00040 El grupo tiene permiso de lectura
    S_IWGRP      00020 El grupo tiene permiso de escritura
    S_IXGRP      00010 El grupo tiene permiso de ejecución
S_IRWXO      00007 otros (no en el grupo) han leído, escriben y ejecutar permiso
    S_IROTH      00004 otros tienen permiso de lectura
    S_IWOTH      00002 otros tienen permiso de escritura
    S_IXOTH      00001 otros tienen permiso de ejecución
*/
int main(int argc, char* argv[]) {
    umask(S_IWGRP | S_IROTH | S_IWOTH | S_IXOTH);
	if(open("fichero2.txt", O_CREAT, 0645) == -1){
		perror("open");
		return -1;	
	}
	std::cout << "Se ha creado el archivo llamado \"fichero2.txt\"" << std::endl;
	return 0;
}
