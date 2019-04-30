#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
	int i;

	if(argc<2){
		fprintf(stderr,"%s : no arguments\n", argv[0]);
		exit(1);	
	}

	char* s = strdup(argv[1]);

	char* dirname[10000];

	int sc = 0;

	while(1){
		char* p = strrchr(s,'/');
		if(p == NULL){
			dirname[sc] = strdup(s);
			break;
		}
		else if(*(p+1) == '\0'){
			fprintf(stderr,"Cannot make directory");
			exit(1);
		}
		else{
			dirname[sc++] = strdup(p+1);
			*p = '\0';
		}
	}

	for(int i = 0;i<=sc;i++){
		printf("%s\n",dirname[i]);
	}

	return 0;
}
