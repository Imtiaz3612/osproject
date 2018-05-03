#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

#define LEFT (PhilNum + 4) % 5
#define RIGHT (PhilNum + 1) % 5


enum s{
 EATING , HUNGRY , THINKING 
};
struct Philosopher{
    char * name;
    int id;

};

struct Philosopher P[5]={{"Professor A",0},{"Professor B",1},{"Professor C",2},{"Professor D",3},{"Professor E",4}};
int ProcessCurrantState[5];


 
sem_t MUTEX;
sem_t Chop[5];
 
void CheckAvailability(int PhilNum)
{
    if ( ProcessCurrantState[LEFT] != EATING && ProcessCurrantState[RIGHT] != EATING)
    {
        // ProcessCurrantState that eating
        ProcessCurrantState[PhilNum] = EATING;
 
        sleep(2);
    printf("--------------------------------------------------------\n"); 
        printf("| Philosopher %s ,id : %d | Picking up Chopsticks %d and %d  .| \n",P[PhilNum].name,
           PhilNum + 1, LEFT + 1, PhilNum + 1);
    printf("--------------------------------------------------------\n");
    printf("--------------------------------------------------------\n");
           printf("Philosopher %s , id : %d | is Eating .\n",P[PhilNum].name, PhilNum + 1);
    printf("--------------------------------------------------------\n");
        sem_post(&Chop[PhilNum]);
    }
}
 
// take up chopsticks
void PickUpChopSticks(int PhilNum)
{
 
    sem_wait(&MUTEX);
 
    // ProcessCurrantState that hungry
    ProcessCurrantState[PhilNum] = HUNGRY;

    printf("--------------------------------------------------------\n"); 
    printf(" | Philosopher %s , id : %d | is Hungry . |\n",P[PhilNum].name, PhilNum + 1);
    printf("--------------------------------------------------------\n"); 
    // eat if neighbours are not eating
    CheckAvailability(PhilNum);
 
    sem_post(&MUTEX);
 
    // if unable to eat wait to be signalled
    sem_wait(&Chop[PhilNum]);
 
    sleep(1);
}
 
// put down chopsticks
void PutChopsticksDown(int PhilNum)
{
 
    sem_wait(&MUTEX);
 
    // ProcessCurrantState that thinking
    ProcessCurrantState[PhilNum] = THINKING;
    printf("---------------------------------------------------------\n");
    printf("| Philosopher %s , id : %d | puting down Chopsticks %d and %d .|\n",P[PhilNum].name,
           PhilNum + 1, LEFT + 1, PhilNum + 1);
    printf("--------------------------------------------------------\n");
           printf("| Philosopher %s , id : %d | is thinking . | \n",P[PhilNum].name, PhilNum + 1);
    printf("--------------------------------------------------------\n");

   CheckAvailability(LEFT);
   CheckAvailability(RIGHT);
 
    sem_post(&MUTEX);
}
 
void* philospher(void* num)
{

     
    while (1) {
    
    int  i = (int *)num;
 
 
        sleep(1);
 
        PickUpChopSticks(i) ;
 
        sleep(0);
 
        PutChopsticksDown(i);
    }
}
 
int main()
{
 
    int i;
    pthread_t Thread[5];
 
    // initialize the semaphores
    sem_init(&MUTEX, 0, 1);
 
    for (i = 0; i < 5; i++)
     {
        sem_init(&Chop[i], 0, 0);
    }
    
    
    // create philosopher processes
    
    for (i = 0; i < 5; i++) {
        pthread_create(&Thread[i], NULL,philospher, (void*)P[i].id);
    printf("--------------------------------------------------------\n"); 
       printf("| Philosopher %s , id : %d | is thinking\n . |",P[i].name, i + 1);
    printf("--------------------------------------------------------\n");
    }
 
    for (i = 0; i < 5; i++)
 
        pthread_join(Thread[i], NULL);
}
