#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <iostream>
#include <errno.h>
#include <string.h>
int main() {
	int respuesta=setuid(0);
	if(respuesta == -1){
		perror("setuid");
		return -1;	
	}
	return 1;
}
