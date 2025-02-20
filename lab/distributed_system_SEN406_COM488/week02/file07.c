#include <pthread.h>

void* taskOne(void * arg)
{
    //while(1)
    for(int i=0; i <= 10; i++)
    {
        sleep(1);
        printf("This is machine one! %d\n",i);
    }
    return NULL;
}

void taskTwo()
{
    //while(1)
    for(int i=0; i <= 3; i++)
    {
        sleep(1);
        printf("This is machine Two %d!\n",i);
    }
}

void main(void)
{
    pthread_t newThread;

    pthread_create(&newThread, NULL, taskOne, NULL);


    //taskOne();
    taskTwo();

    //to make sure execution finish
    pthread_join(&newThread, NULL);
}
