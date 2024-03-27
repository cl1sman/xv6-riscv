#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[]){
	if (argc < 2){
		printf("Erro, minimo 2 argumentos\n");
		exit(1);
	}

	int time = atoi(argv[1]); // convert string to int. [sleep, n]
	// time great zero
	if (time > 0){
		sleep(time);
		exit(0);
	} else {
		printf("argument is wrong\n");
		exit(1);
	}
	return 0;
}
