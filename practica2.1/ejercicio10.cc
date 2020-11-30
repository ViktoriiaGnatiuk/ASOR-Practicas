#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <errno.h>
#include <sys/types.h>
#include <pwd.h>

int main(int argc, char* argv[]) {

	//Si el fichero de programa tiene los bits setuid o setgid activos, el
	//EUID o el EGID del proceso creado se cambian al usuario o grupo del fichero.

	uid_t uid = getuid(); //returns the real user ID of the calling process.
	std::cout << "uid=" << uid << " ";

        uid_t euid = geteuid(); //returns the effective user ID of the calling process.
	std::cout << "euid=" << euid << " ";

	struct passwd *usuario = getpwuid(uid);
	if(usuario == NULL){
		perror("getpwuid");
		return -1;
	}

	//Imprime el nombre d eusuario
	std::cout << usuario -> pw_name << " ";
	
	//Imprime el directorio home
	std::cout << usuario -> pw_dir << " ";
	
	//Imprime la descipción del usuario
	std::cout << usuario -> pw_gecos << " ";

	std::cout << std::endl;

	return 0;
}
