## Program #2 Blackjack Game part 1
### Description:

This assignment is making a UML Diagram of our understanding of Blackjack. Creating different classes with their own variables and methods. Different classes would inherit methods from other classes.

## Class Layout

#### Class Card
> This will be the main parent class, all of the other classes would be brought back to this class to inherit its variables and methods. 

> #### Member Variables:
> - int suit, rank, value
 
> #### Methods:
> - setRank
> - setValue
> - getRank
> - getValue
> - print

#### Class Deck
>- This class would be pointed to the Player and inherited by the class card
> #### Member Variables:
> - int size, remaining

> #### Methods:
> - deal
>- shuffle
>- reset

#### Class Hand
>- This class would be implemented by the deck and player. Also this will display the players hand

> #### Methods: 
>- sort
>- discard

#### Class Player
> This class would be in inherited by hand class. It would show the total the player won, and the money that the player already has in the bank. 

> #### Member Variables
>- double bank, total
>- string name
>- int hand

> #### Methods
>- bet
>- win
>- hit

#### Class Game
>Game would be displayed with two or more players playing the game
>Methods
>- deal
> -acceptsBets
> -print


![UML flowchart](https://github.com/MarquiseJBlue/2143-OOP-Blue/blob/master/Assignments/p02/UML%20class%20(1).png)
