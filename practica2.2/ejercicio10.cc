#include <stdio.h>
#include <iostream>
#include <errno.h>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/sysmacros.h>
#include  <time.h>
/*
dev_t     st_dev;         / ID of device containing file 
ino_t     st_ino;         / Inode number 
mode_t    st_mode;        / File type and mode 
nlink_t   st_nlink;       / Number of hard links 
uid_t     st_uid;         / User ID of owner 
gid_t     st_gid;         / Group ID of owner 
dev_t     st_rdev;        / Device ID (if special file) 
off_t     st_size;        / Total size, in bytes 
blksize_t st_blksize;     / Block size for filesystem I/O 
blkcnt_t  st_blocks;      / Number of 512B blocks allocated 
struct timespec st_atim;  /* Time of last access 
struct timespec st_mtim;  /* Time of last modification 
struct timespec st_ctim;  /* Time of last status change 
*/
int main(int argc, char* argv[]) {
    struct stat statbuf;
    std::cout << argv[1] << std::endl;
	if(stat(argv[1], &statbuf) == -1){
		perror("stat");
		return -1;	
	}
    /*
        El número major y minor asociado al dispositivo.
        El número de i-nodo del fichero.
        El tipo de fichero (directorio, enlace simbólico o fichero ordinario).
        La hora en la que se accedió el fichero por última vez.
    */  
	
	std::cout << "El número major y minor asociado al dispositivo " << major(statbuf.st_dev) << " - " << minor(statbuf.st_dev) << std::endl;
    std::cout << "El número de i-nodo del fichero " << statbuf.st_ino << std::endl;
    std::cout << "El tipo de fichero " << statbuf.st_mode << std::endl;
    std::cout << "La hora en la que se accedió el fichero por última vez " << ctime(&statbuf.st_atim.tv_sec) << std::endl;
}
