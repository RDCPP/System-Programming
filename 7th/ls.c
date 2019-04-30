#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>

static void do_ls(char *path);

int
main(int argc, char *argv[])
{
    int i;

    if (argc < 2) {
        fprintf(stderr, "%s: no arguments\n", argv[0]);
        exit(1);
    }
    for (i = 1; i < argc; i++) {
        do_ls(argv[i]);
    }
    exit(0);
}

static void
do_ls(char *path)
{
    DIR *d;
    struct dirent *ent;

    d = opendir(path);          /* (1) */
    if (!d) {
        perror(path);
        exit(1);
    }
	struct stat st;
    char *final = (char *)malloc(sizeof(char)*1000);
    memset(final,0,1000);
    while (ent = readdir(d)) {  /* (2) */
        strcpy(final,path);
        strcat(final,"/");
        strcat(final,ent->d_name);
		lstat(final,&st);
		printf("%s %d %s",ent->d_name,st.st_uid,ctime(&st.st_mtime));
    }
    closedir(d);                /* (1') */
}
