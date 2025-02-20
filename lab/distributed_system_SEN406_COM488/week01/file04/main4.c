
#include <stdlib.h>
#include <stdio.h>

void main(void)
{
    int i, LIMIT;
    char input[100];

    gets(input);
    LIMIT = atoi(input);
    for(i=0; i <= LIMIT; i++)
    {
        gets(input);
        printf("    FROM B: %s\n",input);
    }

}
