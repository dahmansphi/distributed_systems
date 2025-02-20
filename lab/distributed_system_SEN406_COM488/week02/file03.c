#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>


void main(void)
{
    pid_t pid;
    char buf[100];
    int i=10, j=20;

    if ((pid = fork()) == 0)
    {
        i = 1000; j = 2000;
        sprintf(buf,"   From child val of i=%d; val of j = %d\n", i, j);
        write(1, buf, strlen(buf));
    }
    else
    {
        sleep(3);
        sprintf(buf,"From parent val of i=%d; val of j = %d\n", i, j);
        write(1, buf, strlen(buf));

    }
}
