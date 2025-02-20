#include <stdio.h>
#include  <sys/types.h>
#include  <sys/ipc.h>
#include  <sys/shm.h>
#include "file05.c"

 int main1(void)
 {
     key_t          ShmKEY;
     int            ShmID;
     struct Memory  *ShmPTR;

     ShmKEY=ftok("./", 'x');

     ShmID = shmget(ShmKEY, sizeof(struct Memory), 0666);

     ShmPTR = (struct Memory *) shmat(ShmID, NULL, 0);
     while (ShmPTR->status != FILLED)
        ;
     printf("%d %d %d %d\n", ShmPTR->data[0],ShmPTR->data[1], ShmPTR->data[2], ShmPTR->data[3]);

     ShmPTR->data[0] = getpid();

     ShmPTR->status = TAKEN;

     shmdt((void *) ShmPTR);

     exit(0);


 }
