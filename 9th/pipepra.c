#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int fdptoc[2];
    int fdctop[2];
    pid_t pid;
    char bufp[257];
	char bupc[257];
    int len, status;

    if (pipe(fdptoc) == -1 || pipe(fdctop) == -1) {
        perror("pipe");
        exit(1);
    }

    switch (pid = fork()) {
        case -1 :
            perror("fork");
            exit(1);
            break;
        case 0 : /* child */
            close(fdptoc[1]);
			close(fdctop[0]);
			bupc[0] = '\0';
			write(1, "Child Process: ", 16);
			write(fdctop[1], "Msg from child\n", 15);
            len = read(fdptoc[0], bufp, 256);
            write(1, bufp, len);
            close(fdptoc[0]);
			close(fdctop[1]);
            break;
        default :
            close(fdptoc[0]);
			close(fdctop[1]);
            bufp[0] = '\0';
            write(fdptoc[1], "Msg from parent\n", 16);
			len = read(fdctop[0], bupc, 256);
			write(1, "Parent Process: ", 17);
			write(1, bupc, len);
            close(fdptoc[1]);
			close(fdctop[0]);
            break;
            waitpid(pid, &status, 0);
    }


    return 0;
}
