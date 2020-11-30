#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <errno.h>
#include <sys/types.h>
int main(int argc, char* argv[]) {

	//Si el fichero de programa tiene los bits setuid o setgid activos, el
	//EUID o el EGID del proceso creado se cambian al usuario o grupo del fichero.

	uid_t uid = getuid(); //returns the real user ID of the calling process.
	std::cout << "uid=" << uid << " ";

        uid_t euid = geteuid(); //returns the effective user ID of the calling process.
	std::cout << "euid=" << euid << " ";

	//gid_t gid = getgid(); //returns the real group ID of the calling process.
	//std::cout << "gid=" << gid << " ";

       	//gid_t egid = getegid(); //returns the effective group ID of the calling process.
	//std::cout << egid << " ";
	
	std::cout << std::endl;

	return 0;
}
