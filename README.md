# Credits

Credits for Wikipedia editors.

# Problem statement

![Dining Philosophers](https://upload.wikimedia.org/wikipedia/commons/thumb/7/7b/An_illustration_of_the_dining_philosophers_problem.png/440px-An_illustration_of_the_dining_philosophers_problem.png)
> Illustration of the dining philosophers problem.
Five silent philosophers sit at a round table with bowls of spaghetti. Forks are placed between each pair of adjacent philosophers.

> Each philosopher must alternately think and eat. However, a philosopher can only eat spaghetti when they have both left and right forks. Each fork can be held by only one philosopher and so a philosopher can use the fork only if it is not being used by another philosopher. After an individual philosopher finishes eating, they need to put down both forks so that the forks become available to others. A philosopher can take the fork on their right or the one on their left as they become available, but cannot start eating before getting both forks.

> Eating is not limited by the remaining amounts of spaghetti or stomach space; an infinite supply and an infinite demand are assumed.

> The problem is how to design a discipline of behavior (a concurrent algorithm) such that no philosopher will starve; i.e., each can forever continue to alternate between eating and thinking, assuming that no philosopher can know when others may want to eat or think.

[source](https://en.wikipedia.org/wiki/Dining_philosophers_problem)



<details>
  <summary>Tips:</summary>
  <ul>
    <li>Consider usage of Actor pattern</li>
    <li>library that easier actor pattern usage: [kontrator](https://github.com/RuedigerMoeller/kontraktor)</li>
  </ul>
</details>
