# MonsterHuntCoordinateGame

## Development process - Breaking down the problem
Like most (if not all) problems, a solution can be provided. This is done by breaking down the problem into smaller chunks, thus finding a solution for each chunk. 
Using this problem solving technique helped me greatly with this project.

## Game Idea - Writing it down
I had in mind to create a basic coordinate game where you move on a 2D map and you have to kill all the monsters on the map to complete the game. To help materialize this I used the good old fashioned pen and paper method:
// Insert pic here

As you can see from the above picture it is a simple 2D map (represented by characters #, P, M) where the player, as well as the monster, can move in four directions; Up, Down, Left and Right. To add a bit more interactivity giving the monster the ability to move in random directions makes it different through each playthrough.

The win condition: Kill all monsters.
The lose condition: Too many monsters spawned.

Although it is a simple game, there are quite a few things to consider. Here is what I put down on paper:
// Insert pic here

Writing down what the game's possible methods, data and objects are can help give your game idea a foundation to build upon. Another very important technqiue is to use a flow diagram technique to define the game's flow. In this case, as soon as you play the game, it loops between displaying all game characters and performning the character movements.

## Actual Implementation - What I needed
To represent the characters, using an enum type seemed most appropriate as I wanted to use only the characters '#', 'P' and 'M'. In code:
enum GameBoard { FIELD, PLAYER, MONSTER };
string symbol { "#", "P", "M"}

The next part I needed to define was drawing the map and to do that I used an array of my GameBoard:
GameBoard map COLUMNS, ROWS;

So far, I defined the characters and map. Next task was to initialize them and draw them using for loops. 
After drawing the characters was done, I had to consider setting each PLAYER and MONSTER their own unique coordinates. I did this using a struct data type:
struct Position
{ int x, y };

Of course for the player, I created an object and a pointer of struct type Position:
Position playerPosition;
Position * playerPtrPos;
playerPtrPos = &playerPosition

That's okay for the player. However, for the MONSTER, as there will be more than 1 monster and during run any amount of them and we have to consider once a MONSTER has been killed it needs to be deleted. Thus I opted for using a vector of type Position:
vector<Position> monsters

The reason for choosing a vector is that it can shrink or resize during runtime. A standard array however cannot unless you wish to use pointers which if not done properly can lead to memory leaks if left unchecked. In my case it was simpler to just use vectors.

As you can see from the code, I used switch cases for the movement methods of both the PLAYER and the MONSTER.
switch(movePlayer)  // For the player, insert letters w, s, a, d.
{
case 'w' //UP
case 's' //DOWN
case 'a' //LEFT
case 'd' //RIGHT
}

switch(moveMonster)  // For the monster, a random number between 0-3 is chosen.
{
case '0' //UP
case '1' //DOWN
case '2' //LEFT
case '3' //RIGHT
}
  
For the win and lose conditions, I simply used if statements and the monsters alive counter variable. 

## What improvements could be made
Of course there are a lot of improvements that could be made and there were some things I didn't get round to implementing, such as the following:
- A menu system (e.g. enum MainMenu { PLAY, SET_DIFFICULTY, QUIT }
- Usings classes / pointers for game objects (e.g. class Player, Monster, Map, Game)
- Implementing coloured text  (e.g. green text for winning the game, red text for losing the game)
- Adding ASCII art (e.g. for losing a game, a ASCII art of a monster would display).

I will get round to improving this project over time, I have learned a lot from this project and will continue to learn more!
