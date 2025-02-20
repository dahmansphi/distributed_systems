
#include <stdlib.h>
#include <stdio.h>


void main(int argc, char **argv[])
{
    int i, LIMIT;
    char output[100];

    LIMIT = atoi(argv[1]);
    printf("%d\n", LIMIT);

    for(i=0; i <= LIMIT; i++)
    {
        sprintf(output, "Printing %d from A", i);
        printf("%s\n",output);
    }


}
