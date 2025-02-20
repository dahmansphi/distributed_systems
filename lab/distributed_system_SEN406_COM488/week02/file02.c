#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>


void main(void)
{
    pid_t pid;
    char buf[100];
    pid = fork();

    if (pid == 0)
    {
        sprintf(buf,"   From child %ld: my parent is %ld\n", getpid(), getppid());
        write(1, buf, strlen(buf));

        sleep(5);
        sprintf(buf,"   From child after sleep 5seconds %ld: my parent is %ld\n", getpid(), getppid());
        write(1, buf, strlen(buf));
    }
    else
    {
        sleep(2);
        sprintf(buf,"From parent %ld: child is %ld, parent %ld\n", getpid(), pid,getppid());
        write(1, buf, strlen(buf));

        sprintf(buf,"From Parent done\n");
        write(1, buf, strlen(buf));


    }
}
