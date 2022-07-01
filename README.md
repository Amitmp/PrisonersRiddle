# PrisonersRiddle
This program implements the 100 Prisoners Riddle problem and solution described in The Veritasium Youtube channel https://www.youtube.com/watch?v=iSNsgj1OCLA

The 100 prisoners problem is a mathematical problem in probability theory and combinatorics. 
In this problem, 100 numbered prisoners must find their own numbers in one of 100 drawers in order to survive. 
The rules state that each prisoner may open only 50 drawers and cannot communicate with other prisoners. 
At first glance, the situation appears hopeless, but a clever strategy offers the prisoners a realistic chance of survival. 
Danish computer scientist Peter Bro Miltersen first proposed the problem in 2003. 

Problem : 
    The director of a prison offers 100 death row prisoners, who are numbered from 1 to 100, a last chance. 
    A room contains a cupboard with 100 drawers. The director randomly puts one prisoner's number in each closed drawer. 
    The prisoners enter the room, one after another. Each prisoner may open and look into 50 drawers in any order. 
    The drawers are closed again afterwards. If, during this search, every prisoner finds his number in one of the drawers, all prisoners are pardoned. 
    If just one prisoner does not find his number, all prisoners die. Before the first prisoner enters the room, the prisoners may discuss strategy — 
    but may not communicate once the first prisoner enters to look in the drawers. What is the prisoners' best strategy?

If every prisoner selects 50 drawers at random, the probability that a single prisoner finds his number is 50%. 
Therefore, the probability that all prisoners find their numbers is the product of the single probabilities, which is (1/2)100 ≈ 0.0000000000000000000000000000008, a vanishingly small number. 


Solution : 
Surprisingly, there is a strategy that provides a survival probability of more than 30%. The key to success is that the prisoners do not have to decide beforehand which drawers to open. 
Each prisoner can use the information gained from the contents of every drawer he already opened to help decide which one to open next. 
Another important observation is that this way the success of one prisoner is not independent of the success of the other prisoners, because they all depend on the way the numbers are distributed.

To describe the strategy, not only the prisoners, but also the drawers are numbered from 1 to 100, for example row by row starting with the top left drawer. The strategy is now as follows:

    Each prisoner first opens the drawer with his own number.
    If this drawer contains his number he is done and was successful.
    Otherwise, the drawer contains the number of another prisoner and he next opens the drawer with this number.
    The prisoner repeats steps 2 and 3 until he finds his own number or has opened 50 drawers.

By starting with his own number, the prisoner guarantees he is on a sequence of boxes containing his number. The only question is whether this sequence is longer than 50 boxes. 

Example :
The reason this is a promising strategy is illustrated with the following example using 8 prisoners and drawers, whereby each prisoner may open 4 drawers. 
The prison director has distributed the prisoners' numbers into the drawers in the following fashion:

    number of drawer 	1   2   3   4   5   6   7   8  
    number of prisoner 	7 	4 	6 	8 	1 	3 	5 	2 

The prisoners now act as follows:
    Prisoner 1 first opens drawer 1 and finds number 7. Then he opens drawer 7 and finds number 5. Then he opens drawer 5, where he finds his own number and is successful.
    Prisoner 2 opens drawers 2, 4, and 8 in this order. In the last drawer he finds his own number 2.
    Prisoner 3 opens drawers 3 and 6, where he finds his own number.
    Prisoner 4 opens drawers 4, 8, and 2, where he finds his own number. Note that this is the same cycle encountered by prisoner 2, but he isn't aware of it.
    Prisoners 5 to 8 will also each find their numbers in a similar fashion.

Source : https://en.wikipedia.org/wiki/100_prisoners_problem
