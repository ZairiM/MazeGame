**MazeGame**

*By Zairi Marion Pineda*

MazeGame is a console application made using C++, CodeBlocks and GNU GCC
Compiler.

**Game Development:**

This game was developed using CodeBlocks, in the image you can see the game
structure.

![](https://cdn.discordapp.com/attachments/799826831368126464/799826930441650197/unknown.png)

The game starts in main class, there is a Player and a GameMap.

GameMap draws the screens and of course the map, after that the Player call a
fuction to receive the movement, then the GameMap draws a map again. This
sequence is repeated until the game is declared over; the game is over when:

1.  The player loses and choose no continue playing.

2.  The player wins and choose no play again.

GameMap has a MapCell matrix to draw the map, also has an Enemy in each level.

Enemy and Player class control themselves movements. After that, the GameMap
draws the map with the new positions updated.

If you want to see all code and how it works you can see it in the GitHub
repository:

<https://github.com/ZairiM/MazeGame>

There you can clone the project and see what is inside.

**Let’s Play:**

There is a link where you can find the game:

<https://drive.google.com/file/d/1_11UmsesEkSX96dMggfjbtXJLbYZMpaJ/view?usp=sharing>

To play to need to download it, unzipped and run Labyrinth Game application You
can found it in
“\\MazeGameRelease\\bin\\Debug”![](https://cdn.discordapp.com/attachments/799826831368126464/799827260369797130/unknown.png)

Maybe when you run it you can find this screen:

![](https://cdn.discordapp.com/attachments/799826831368126464/799827685403787284/unknown.png)

It is ok, just click More info

![](https://cdn.discordapp.com/attachments/799826831368126464/799827814714048512/unknown.png)

And click in Run anyway. That’s all, now you can play this game.

**Game Presentation:**

**What MazeGame is about?**

In MazeGame you are a hero identified on the map with the letter ‘H’. You enter
in 3 different mazes; in each maze you need to get a chest identified on the
with the letter ‘O’ and to get it you need move using ‘w’, ‘a’, ‘s’, ‘d’
followed by the Enter key while you avoid the enemies identified with the letter
‘e’.

**Game Rules:**

-   You move using ‘w’, ’a’, ’s’, ’d’ and enter key.

-   You cannot go through the walls; you are not invisible.

-   You win when you complete 3 mazes.

-   To complete a maze, you need to get the chest ‘O’.

-   You lose if you and an enemy are in the same position.

-   Enemies move random. You cannot know what the enemy’s next position is.

**Game Intro:**

When you start the game, you see an intro screen. Welcoming you to the game.

![](https://cdn.discordapp.com/attachments/799826831368126464/799827983262285884/unknown.png)

**Game Instructions:**

Next the Intro Screen you see some instructions to start play. As you can see in
the next image.

![](https://cdn.discordapp.com/attachments/799826831368126464/799828094834704434/unknown.png)

**Game Map:**

This is one of the three maps. In each map these are the characters:

-   Starting hero position ‘x’

-   Current hero position ‘H’

-   Starting enemy position ‘E’

-   Current enemy position ‘e’

-   Chest ‘O’

-   Vertical wall ‘\|’

-   Horizontal wall ‘-‘

Also, there is an alert when you try pass the walls.

![](https://cdn.discordapp.com/attachments/799826831368126464/799828257218101259/unknown.png)

**Level Up:**

You level up when you find the chest and the game shows you this screen.

![](https://cdn.discordapp.com/attachments/799826831368126464/799828378600472586/unknown.png)

**Game Over:**

You lose when you touch and enemy. And you see this screen, also you can choose
if exit or play again.

![](https://cdn.discordapp.com/attachments/799826831368126464/799828558146961408/unknown.png)

**Victory:**

You win when you complete the 3 mazes. Then you see this screen. As well as when
you lose when you win you also have the option to choose if you want to play
again or not.

![](https://cdn.discordapp.com/attachments/799826831368126464/799828709980897288/unknown.png)

