<H><b><center>                                    DINING PHILOSOPHERS PROBLEM</center></b></H>
<br>
<b>1.Project Description</b>
<br>
>In computer science, the dining philosophers problem is an example problem often used in concurrent algorithm design to illustrate synchronization issues and techniques for resolving them.
The dining-philosophers problem is considered a classic synchronization problem neither because of its practical importance nor because computer scientists dislike philosophers but because it is an example of a large class of concurrency-control problems.
It was originally formulated in 1965 by Edsger Dijkstra as a student exam exercise, presented in terms of computers competing for access to tape drive peripherals. Soon after, Tony Hoare gave the problem its present formulation



<b>2.Problem Statement</b>
 <br>
>Five silent philosophers sit at a round table around a bowl of spaghetti. chopsticks are placed between each pair of adjacent philosophers.
Each philosopher must alternately think and eat. However, a philosopher can only eat spaghetti when they have both left and right chopsticks . Each chopstick can be held by only one philosopher and so a philosopher can use the chopstick only if it is not being used by another philosopher. After an individual philosopher finishes eating , they need to put down both forks so that the forks become available to others. A philosopher can take the fork on their right or the one on their left as they become available, but cannot start eating before getting both chopsticks .
Eating is not limited by the remaining amounts of spaghetti or stomach space; an infinite supply and an infinite demand are assumed.
The problem is how to design a discipline of behaviour (a concurrent algorithm) such that no philosopher will starve; i.e., each can forever continue to alternate between eating and thinking, assuming that no philosopher can know when others may want to eat or think .



<b>3.Procedure and Method/implementation (You applied)</b>
<br>
> We used Semaphore and threads to demonstrate and solve the problem 
One simple solution is to represent each chopstick with a semaphore. A
philosopher tries to grab a chopstick by executing a wait() operation on that
semaphore. She releases her chopsticks by executing the signal() operation
on the appropriate semaphores.

ALGORITHM FOR OUR CODE 
-Define the number of philosophers
-Declare one thread per philosopher
-Declare one mutex(represent chopsticks) per philosopher
-When a philosopher is hungry
-See if chopsticks on both sides are free
  -acquire chopsticks
 -eat
-restore the chopsticks
-If chopsticks aren’t free
-wait till they’re available
- repeat endlessly



<b>4.Project Result</b>
<br>
-Getting rid of deadlock by properly synchronizing .
-Meeting need to allocate several resources among several processes in a deadlock-free and
starvation-free manner.




<b>5.References</b>
Abraham silberschatz operating system concepts 
Wikipedia
