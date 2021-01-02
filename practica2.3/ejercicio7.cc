#include <stdio.h>
#include <iostream>
#include <errno.h>
#include <string>
#include <unistd.h>
#include <sched.h>
#include <stdlib.h>
int main(int argc, char* argv[]) {

      if(system(argv[1]) == -1){
        perror("system");
        return -1;
      }
        std::cout << "El comando terminó de ejecutarse" << std::endl;
    return 0;
}
