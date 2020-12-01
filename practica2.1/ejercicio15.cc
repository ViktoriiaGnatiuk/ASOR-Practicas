#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <errno.h>
#include <string.h>
#include <time.h>

int main() {
	time_t t = time(NULL);
	if(&t == nullptr){
		perror("time");
		return -1;
	}

	struct tm *time = localtime(&t);
	if(&time == nullptr){
		perror("localtime");
		return -1;
	}
	int anio = time -> tm_year;/* años desde 1900 */
	int anio_real = 1900 + anio;

	char outstr[200];
	const char format [] = "%A, %d of %B of %Y, %H:%M";
	if( strftime(outstr, sizeof(outstr), format, time) == 0){
		perror("strftime");
		return -1;
	}
	std::cout << outstr << std::endl;
	return 1;
}
