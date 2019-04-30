#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
	int i;

	if(argc<2){
		fprintf(stderr,"%s : no arguments\n", argv[0]);
		exit(1);	
	}

	mode_t old = umask(0000);

	for(i=1; i<argc; i++){
//		mkdir(argv[i],S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP|S_IWGRP|S_IXGRP|S_IROTH|S_IWOTH|S_IXOTH);
		mkdir(argv[i],0777);
	}

	umask(old);

	return 0;
}
