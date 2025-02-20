// C program to show thread functions
 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 #define  LIMIT  (20)   // run this number of iterations

int main(void)
 {
     int i, j, x, y;
     srand(time(NULL));  // plant a random number seed
     for (j = 1; j <= LIMIT; j++)
        {
         x = rand()/10; // get a random number and scale
         for (i = 1; i <= x; i++)
            y = rand();  // just waste CPU time, :o)
            printf("Hi, A here!  Random number = %d\n", x);
        }
     printf("A completes\n");
 }

