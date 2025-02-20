#include <stdio.h>
#include  <sys/types.h>
#include  <sys/ipc.h>
#include  <sys/shm.h>


#define  NOT_READY  (-1)
#define  FILLED     (0)
#define  TAKEN      (1)


struct Memory
{
 int  status;
 int  data[4];
};


 int main(int argc, char *argv[])
 {

     key_t ShmKEY;
     int ShmID, i;
     struct Memory *ShmPTR;

     ShmKEY = ftok("./", 'x');
     ShmID = shmget(ShmKEY, sizeof(struct Memory),IPC_CREAT | 0666);

     ShmPTR = (struct Memory *) shmat(ShmID, NULL, 0);

     ShmPTR->status = NOT_READY;

     ShmPTR->data[0] = getpid();
     for (i = 1; i < 4; i++)
        ShmPTR->data[i] = atoi(argv[i]);

     ShmPTR->status = FILLED;
     while (ShmPTR->status != TAKEN)
        sleep(1);  /* sleep for 1 second */

     printf("My buddy is %ld\n", ShmPTR->data[0]);

     shmdt((void *) ShmPTR);
     shmctl(ShmID, IPC_RMID, NULL);
     exit(0);
 }
