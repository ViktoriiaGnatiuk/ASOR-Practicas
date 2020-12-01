#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <errno.h>
#include <string.h>
#include <sys/time.h>

int get_time(timeval &tv){
	int tiempo = gettimeofday(&tv, NULL);
	if(tiempo == -1){
		perror("gettimeofday");
		return -1;	
	}
	return 0;
}
int main() {
	struct timeval tv1;
	if(get_time(tv1) == -1){
		perror("tv1");
		return -1;
	}
	
	for(int i=0; i < 1000000; i++);

	struct timeval tv2;
	if(get_time(tv2) == -1){
		perror("tv2");
		return -1;
	}
	
	long sec_dif = 0;
	long usec_dif = 0;
	sec_dif = tv2.tv_sec - tv1.tv_sec ;
	usec_dif = tv2.tv_usec - tv1.tv_usec ;
	long total_usec = usec_dif + sec_dif*1000000;
	std::cout << "El bucle ha tardado " << total_usec << " microsegundos." << std::endl;
	return 1;
}
