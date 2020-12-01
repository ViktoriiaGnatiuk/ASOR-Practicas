#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <errno.h>
#include <string.h>
#include <time.h>

int main() {
	time_t t = time(NULL);
	if(t == NULL){
		perror("time");
		return -1;
	}

	struct tm *time = localtime(&t);
	if(time == NULL){
		perror("localtime");
		return -1;
	}
	int anio = time -> tm_year;/* años desde 1900 */
	int anio_real = 1900 + anio;
	std::cout << anio_real << std::endl; 
	return 1;
}
