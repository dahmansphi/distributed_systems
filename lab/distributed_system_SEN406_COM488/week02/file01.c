#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>



void main(void)
{
    pid_t myID, parentID;
    int i;
    char buf[100];

    fork();
    myID = getpid();
    parentID = getppid();

    for (i=0; i <= 200; i++)
    {
        sprintf(buf, "from myID: %ld, parentID: %ld, i=%3d\n",myID, parentID, i);
        write(1,buf, strlen(buf));
    }


}
