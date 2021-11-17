#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;

// Checklist of requirements
// 1: A looping Menu (DONE)
// 2: Able to either play game or quit game (DONE)
// 3: Able to set game difficulty (mostly done)
// 4: Generate Monsters and their coordinates (not done yet)
// 5: Have a monster count i.e. tally of alive monsters (not done yet)
// 6: Organise player and monster into organised classes (not done yet)
// 7: Able to kill a monster (DONE)
// 8: Able to spawn a new monster after so many player turns (not yet done)
// 9: Have a win and lose condition for game (not yet done)
// 10: Have a fixed size game grid 5x5 (not yet down)


/*
// ** Menu System ** ---------------------------------------------------------------------------
enum MainMenu { Play = 1, SetDifficulty, Quit };

static const int EASY = 1, MEDIUM = 2, HARD = 3;
void setDifficulty()
{
	int choice = 1;
	do
	{
		if (choice <EASY || choice>HARD)
		{
			cout << "Thats not the correct input, please try again!" << endl;
		}

		cout << "Choose your difficulty; Enter corresponding number\n"
			<< "1: Easy, 2: Medium, 3: Hard" << endl;
		cin >> choice;
	} 
	while (choice <EASY || choice>HARD);

	switch (choice)
	{
	case EASY: // Alter enemy health, quantity here. 
		cout << "Easy difficulty applied." << endl;
		break;
	case MEDIUM: // Alter enemy health, quantity here.
		cout << "Medium difficulty applied." << endl;
		break;
	case HARD: // Alter enemy health, quantity here.
		cout << "Medium difficulty applied." << endl;
		break;
	}
	cout << endl;
}

void playGame()
{
	bool playingGame = true;
	int playerLives = 2;
	while (playingGame)
	{
		// Display Monsters, Players, move directions etc...
		cout << "Player Lives = " << playerLives << endl;
		playerLives--;

		if (playerLives == 0)
		{
			cout << "Player Lives = " << playerLives << endl;
			cout << "Game Over!" << endl;
			playingGame = false;
		}
	}
	cout << endl;
}

MainMenu menuChoices;
MainMenu menu();
void startGame()
{
	bool finishedGame = false;
	while (!finishedGame)
	{
		menuChoices = menu();
		switch (menuChoices)
		{
		case Play: playGame(); break;
		case SetDifficulty: setDifficulty(); break;
		case Quit: finishedGame = true; break;
		}
	}
}

MainMenu menu()
{
	int choice = 3;
	do
	{
		if (choice<MainMenu::Play || choice>MainMenu::Quit)
		{
			cout << "Incorrect input, please try again!" << endl;
		}

		cout << "Main Menu: Please select your choice." << endl;
		cout << "1: Play, 2: Set Difficulty, 3: Quit" << endl;
		cin >> choice;
		cout << endl;
	} 
	while (choice<MainMenu::Play || choice>MainMenu::Quit);

	return (MainMenu)choice;
}

int main()
{
	startGame();

	return 0;
}
*/
// ** End of Menu system ** ------------------------------------------------------------------




/*
// ** Output map and occupy position ** -----------------------------------------------------
static const int MAP_SIZE = 3;
bool gameMap[MAP_SIZE][MAP_SIZE];

enum MapSpace { TAKEN, FREE };
void mapSpaceStatus(bool status)
{
	switch (status)
	{
	case TAKEN: cout << "taken"; break;
	case FREE: cout << "free"; break;
	}
}

struct Position
{
	int x, y;
} pos;

enum BooleanAnswer { FALSE, TRUE };
void testBoolWord(bool word)
{
	switch (word)
	{
	case FALSE: cout << "false"; break;
	case TRUE: cout << "true"; break;
	}
}

int main()
{
	Position aPosition;
	Position * ptrPosition;
	ptrPosition = &aPosition;

	BooleanAnswer answerBool;

	// Initialize map
	for (int i = 0; i < MAP_SIZE; i++)
	{
		for (int j = 0; j < MAP_SIZE; j++)
		{
			gameMap[i][j] = true;
		}
	}

	// Generate random xy coordinate values
	srand(time(NULL));
	for (int i = 0; i < 1; i++)
	{
		ptrPosition->x = rand() % MAP_SIZE;
		ptrPosition->y = rand() % MAP_SIZE;	
	}

	// Assign xy coordinate values to map
	gameMap[ptrPosition->x][ptrPosition->y] = false;

	// Display xy coordinates
	cout << "Current position = ["
		<< ptrPosition->x << ", " << ptrPosition->y << "]"
		<< endl;

	// Display map
	for (int i = 0; i < MAP_SIZE; i++)
	{
		for (int j = 0; j < MAP_SIZE; j++)
		{
			cout << gameMap[i][j] << ", ";
		}
		cout << endl;
	}

	cout << endl;

	// Display map with index description
	for (int i = 0; i < MAP_SIZE; i++)
	{
		for (int j = 0; j < MAP_SIZE; j++)
		{
			mapSpaceStatus(gameMap[i][j]);
			cout << ", ";
		}
		cout << endl;
	}

	cout << endl;

	bool testTrue = true;
	bool testFalse = false;
	cout << "bool testTrue = " << testTrue << " = ";
	testBoolWord(testTrue);
	cout << endl;
	cout << "bool testFalse = " << testFalse << " = ";
	testBoolWord(testFalse);
	cout << endl;
	
	cout << endl;

	system("pause");

	return 0;
}
*/
// ------------------------------------------------------------------------------------------





/*
// ** Move around in game map ** -----------------------------------------------------------
enum MoveDirection { UP, DOWN, LEFT, RIGHT };
const int ROWS = 3;
const int COLUMNS = 3;
static const int MAP_SIZE = 3;
bool gameMap[COLUMNS][ROWS];

struct Position
{
	int x, y;
}pos;

MoveDirection getDirection()
{
	char moveInput;
	bool inputIsWrong = true;
	cout << "Choose direction: w=UP, s=DOWN, a=LEFT, d=RIGHT" << endl;
	do
	{
		cin >> moveInput;
		switch (moveInput)
		{
		case 'w':
		case 'W':
			return MoveDirection::UP;

		case 's':
		case 'S':
			return MoveDirection::DOWN;

		case 'a':
		case 'A':
			return MoveDirection::LEFT;

		case 'd':
		case 'D':
			return MoveDirection::DOWN;
		}
	} 
	while (inputIsWrong);
}

// Important note: Make sure if logic is 100% correct.
void moveUp()
{
	if (pos.y < 3)
	{
		pos.y++;
	}
}

void moveDown()
{
	if (pos.y > 0)
	{
		pos.y--;
	}
}

void moveLeft()
{
	if (pos.x > 0)
	{
		pos.x--;
	}
}

void moveRight()
{
	if (pos.x < 3)
	{
		pos.x++;
	}
}

void move(MoveDirection dir)
{
	Position oldPosition;

	switch (dir)
	{
	case MoveDirection::UP: moveUp(); break;
	case MoveDirection::DOWN: moveDown(); break;
	case MoveDirection::LEFT: moveLeft(); break;
	case MoveDirection::RIGHT: moveRight(); break;
	}
}

int main()
{
	// Initialize map
	for (int i = 0; i < COLUMNS; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			gameMap[i][j] = true;
		}
	}

	Position aPosition;
	Position * ptrPosition;
	ptrPosition = &aPosition;

	// Generate random xy coordinate values
	srand(time(NULL));
	for (int i = 0; i < 1; i++)
	{
		ptrPosition->x = rand() % MAP_SIZE;
		ptrPosition->y = rand() % MAP_SIZE;
	}

	// Assign xy coordinate values to map
	gameMap[ptrPosition->y][ptrPosition->x] = false;

	cout << endl;
	int counter = 0;
	while (counter < 10)
	{
		// Display xy coordinates
		cout << "Current position = ["
			<< ptrPosition->y << ", " << ptrPosition->x << "]"
			<< endl;

		// Display map
		cout << "Map: " << endl;
		for (int i = 0; i < COLUMNS; i++)
		{
			for (int j = 0; j < ROWS; j++)
			{
				cout << gameMap[i][j] << ", ";
			}
			cout << endl;
		}

		cout << endl;

		cout << "Choose direction: w=UP, s=DOWN, a=LEFT, d=RIGHT" << endl;
		
		char inputDir;
		cin >> inputDir;

		switch(inputDir)
		{
		case 'w':
		case 'W':
		case UP: 
			if (ptrPosition->y > 0)
			{
				cout << "Moving Up..." << endl;
				gameMap[ptrPosition->y][ptrPosition->x] = true;
				ptrPosition->y--;
				gameMap[ptrPosition->y][ptrPosition->x] = false;
			}
			else
			{
				cout << "You cannot move up. End of map." << endl;
			}
			break;

		case 's':
		case 'S':
		case DOWN: 
			if (ptrPosition->y < 2)
			{
				cout << "Moving Down..." << endl;
				gameMap[ptrPosition->y][ptrPosition->x] = true;
				ptrPosition->y++;
				gameMap[ptrPosition->y][ptrPosition->x] = false;
			}
			else
			{
				cout << "You cannot move down. End of map." << endl;
			}
			break;

		case 'a':
		case 'A':
		case LEFT: 
			if (ptrPosition->x > 0)
			{
				cout << "Moving Left..." << endl;
				gameMap[ptrPosition->y][ptrPosition->x] = true;
				ptrPosition->x--;
				gameMap[ptrPosition->y][ptrPosition->x] = false;
			}
			else
			{
				cout << "You cannot move left. End of map." << endl;
			}
			break;

		case 'd':
		case 'D':
		case RIGHT:
			if (ptrPosition->x < 2)
			{
				cout << "Moving Right..." << endl;
				gameMap[ptrPosition->y][ptrPosition->x] = true;
				ptrPosition->x++;
				gameMap[ptrPosition->y][ptrPosition->x] = false;
			}
			else
			{
				cout << "You cannot move right. End of map." << endl;
			}
			break; 

		default: cout << "Incorrect input, try again." << endl;
		}

		counter++;
	}

	cout << "End of test" << endl;

	system("pause");

	return 0;
}
*/
// ------------------------------------------------------------------------------------------


/*
// ** Have Player move and clash with Monster ** -----------------------------------------------
enum GameBoard
{
	FIELD, PLAYER, MONSTER
};

enum MoveDirection { UP, DOWN, LEFT, RIGHT };

struct Position
{
	int x, y;
};

const int NUM_OF_CHAR = 3;
string symbol[NUM_OF_CHAR] = { "#", "P", "M" };

const int ROWS = 3;
const int COLUMNS = 3;
GameBoard map[COLUMNS][ROWS];

void printMapLine(GameBoard type)
{
	cout << symbol[type] << " ";
}

void initialiseMap(GameBoard type)
{
	for (int i = 0; i < COLUMNS; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			map[i][j] = type;
		}
	}
}

void assignLocation(Position *pos, GameBoard piece)
{
	int x = pos->x;
	int y = pos->y;
	map[x][y] = piece;
}

int main()
{
	// Initialise map
	initialiseMap(FIELD);

	// Place Player on map
	Position playerPosition;
	Position * playerPtrPos;
	playerPtrPos = &playerPosition;
	playerPtrPos->x = 0;
	playerPtrPos->y = 0;
	assignLocation(playerPtrPos, PLAYER);

	// Place Monster on map
	Position monsterPosition;
	Position * monsterPtrPos;
	monsterPtrPos = &monsterPosition;
	monsterPtrPos->x = 1;
	monsterPtrPos->y = 1;
	assignLocation(monsterPtrPos, MONSTER);

	// Main game loop
	char moveInput;
	bool gameOver = false;
	int monstersKilledCounter = 0;
	while (!gameOver)
	{
		// Player Location
		cout << "Player position = ["
			<< playerPtrPos->y << ", " << playerPtrPos->x << "]"
			<< endl;

		// Monsters killed
		cout << "Monsters killed = " << monstersKilledCounter << endl;
		
		// Print whole map
		cout << "Game map:" << endl;
		for (int i = 0; i < COLUMNS; i++)
		{
			for (int j = 0; j < ROWS; j++)
			{
				printMapLine(map[i][j]);
			}
			cout << endl;
		}
		cout << endl;

		cout << "Input direction: w=UP, s=DOWN, a=LEFT, d=RIGHT" << endl;
		cin >> moveInput;

		switch (moveInput)
		{
		case 'w':
		case 'W':
		case UP:
			if (playerPtrPos->y > 0)
			{
				cout << "Moving Up..." << endl;
				map[playerPtrPos->y][playerPtrPos->x] = FIELD;
				playerPtrPos->y--;
				map[playerPtrPos->y][playerPtrPos->x] = PLAYER;
			}
			else
			{
				cout << "You cannot move up. End of map." << endl;
			}
			break;

		case 's':
		case 'S':
		case DOWN:
			if (playerPtrPos->y < 2)
			{
				cout << "Moving Down..." << endl;
				map[playerPtrPos->y][playerPtrPos->x] = FIELD;
				playerPtrPos->y++;
				map[playerPtrPos->y][playerPtrPos->x] = PLAYER;
			}
			else
			{
				cout << "You cannot move down. End of map." << endl;
			}
			break;

		case 'a':
		case 'A':
		case LEFT:
			if (playerPtrPos->x > 0)
			{
				cout << "Moving Left..." << endl;
				map[playerPtrPos->y][playerPtrPos->x] = FIELD;
				playerPtrPos->x--;
				map[playerPtrPos->y][playerPtrPos->x] = PLAYER;
			}
			else
			{
				cout << "You cannot move left. End of map." << endl;
			}
			break;

		case 'd':
		case 'D':
		case RIGHT:
			if (playerPtrPos->x < 2)
			{
				cout << "Moving Right..." << endl;
				map[playerPtrPos->y][playerPtrPos->x] = FIELD;
				playerPtrPos->x++;
				map[playerPtrPos->y][playerPtrPos->x] = PLAYER;
			}
			else
			{
				cout << "You cannot move right. End of map." << endl;
			}
			break;

		default: cout << "Incorrect input, try again." << endl;
		}

		if (playerPtrPos->x == monsterPtrPos->x &&
			playerPtrPos->y == monsterPtrPos->y)
		{
			cout << "You killed a monster!" << endl;;
			monstersKilledCounter++;
		}

	}

	system("pause");

	return 0;
}
*/
// ------------------------------------------------------------------------------------------

// IMPORTANT NOTE : Beyond this point, learn to use classes and pointers! //

/*
// ** Generate monsters at random locations and delete upon collision ** --------------------
enum GameBoard
{
	FIELD, PLAYER, MONSTER
};

enum MoveDirection { UP, DOWN, LEFT, RIGHT };

struct Position
{
	int x, y;
};

const int MONSTER_AMOUNT = 3;

const int NUM_OF_CHAR = 3;
string symbol[NUM_OF_CHAR] = { "#", "P", "M" };

const int ROWS = 3;
const int COLUMNS = 3;
const int MAP_SIZE = 3;
GameBoard map[COLUMNS][ROWS];

void printMapLine(GameBoard type)
{
	cout << symbol[type] << " ";
}

void initialiseMap(GameBoard type)
{
	for (int i = 0; i < COLUMNS; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			map[i][j] = type;
		}
	}
}

void assignLocation(Position *pos, GameBoard piece)
{
	int x = pos->x;
	int y = pos->y;
	map[x][y] = piece;
}

int main()
{
	// Initialise map
	initialiseMap(FIELD);

	// Place Monster on map
	vector<Position> monsters;
	for (int i = 0; i < MONSTER_AMOUNT; i++)
	{
		Position p;
		p.x = rand() % MAP_SIZE;
		p.y = rand() % MAP_SIZE;
		monsters.push_back(p);
		map[p.x][p.y] = MONSTER;
	}

	// Place Player on map
	Position playerPosition;
	Position * playerPtrPos;
	playerPtrPos = &playerPosition;
	playerPtrPos->x = 0;
	playerPtrPos->y = 0;
	assignLocation(playerPtrPos, PLAYER);

	// Main game loop
	char moveInput;
	bool gameOver = false;
	bool monsterDetected = false;
	int monstersKilledCounter = 0;
	while (!gameOver)
	{
		// Player Location
		cout << "Player position = ["
			<< playerPtrPos->y << ", " << playerPtrPos->x << "]"
			<< endl;

		// Monsters killed
		cout << "Monsters killed = " << monstersKilledCounter << endl;

		// Print whole map
		cout << "Game map:" << endl;
		for (int i = 0; i < COLUMNS; i++)
		{
			for (int j = 0; j < ROWS; j++)
			{
				printMapLine(map[i][j]);
			}
			cout << endl;
		}
		cout << endl;

		cout << "Input direction: w=UP, s=DOWN, a=LEFT, d=RIGHT" << endl;
		cin >> moveInput;

		switch (moveInput)
		{
		case 'w':
		case 'W':
		case UP:
			if (playerPtrPos->y > 0)
			{
				cout << "Moving Up..." << endl;
				map[playerPtrPos->y][playerPtrPos->x] = FIELD;
				playerPtrPos->y--;
				if (map[playerPtrPos->y][playerPtrPos->x] == MONSTER)
				{
					monsterDetected = true;
				}
				map[playerPtrPos->y][playerPtrPos->x] = PLAYER;
			}
			else
			{
				cout << "You cannot move up. End of map." << endl;
			}
			break;

		case 's':
		case 'S':
		case DOWN:
			if (playerPtrPos->y < 2)
			{
				cout << "Moving Down..." << endl;
				map[playerPtrPos->y][playerPtrPos->x] = FIELD;
				playerPtrPos->y++;
				if (map[playerPtrPos->y][playerPtrPos->x] == MONSTER)
				{
					monsterDetected = true;
				}
				map[playerPtrPos->y][playerPtrPos->x] = PLAYER;
			}
			else
			{
				cout << "You cannot move down. End of map." << endl;
			}
			break;

		case 'a':
		case 'A':
		case LEFT:
			if (playerPtrPos->x > 0)
			{
				cout << "Moving Left..." << endl;
				map[playerPtrPos->y][playerPtrPos->x] = FIELD;
				playerPtrPos->x--;
				if (map[playerPtrPos->y][playerPtrPos->x] == MONSTER)
				{
					monsterDetected = true;
				}
				map[playerPtrPos->y][playerPtrPos->x] = PLAYER;
			}
			else
			{
				cout << "You cannot move left. End of map." << endl;
			}
			break;

		case 'd':
		case 'D':
		case RIGHT:
			if (playerPtrPos->x < 2)
			{
				cout << "Moving Right..." << endl;
				map[playerPtrPos->y][playerPtrPos->x] = FIELD;
				playerPtrPos->x++;
				if (map[playerPtrPos->y][playerPtrPos->x] == MONSTER)
				{
					monsterDetected = true;
				}
				map[playerPtrPos->y][playerPtrPos->x] = PLAYER;
			}
			else
			{
				cout << "You cannot move right. End of map." << endl;
			}
			break;

		default: cout << "Incorrect input, try again." << endl;
		}

		if (monsterDetected == true)
		{	
			// insert search monster array here
			for (int i = 0; i < monsters.size(); i++)
			{
				int mX = monsters[i].x;
				int mY = monsters[i].y;
				int pX = playerPtrPos->x;
				int pY = playerPtrPos->y;
				
				if (mX == pX && mY == pY)
				{
					monsters.erase(monsters.begin()+i);
				}
				// if this monster's xy matches
			}

			monsterDetected = false;
			cout << "You killed a monster!" << endl;
			monstersKilledCounter++;
		}
	}

	system("pause");

	return 0;
}
// -----------------------------------------------------------------------------------------
*/


/*
// ** Move Monsters per turn in random locations ------------------------------------------
enum GameBoard
{
	FIELD, PLAYER, MONSTER
};

enum MoveDirection { UP, DOWN, LEFT, RIGHT };

struct Position
{
	int x, y;
};

const int MONSTER_AMOUNT = 3;
const int MONSTER_MOVES = 4;

const int NUM_OF_CHAR = 3;
string symbol[NUM_OF_CHAR] = { "#", "P", "M" };

const int ROWS = 3;
const int COLUMNS = 3;
const int MAP_SIZE = 3;
GameBoard map[COLUMNS][ROWS];

void printMapLine(GameBoard type)
{
	cout << symbol[type] << " ";
}

void initialiseMap(GameBoard type)
{
	for (int i = 0; i < COLUMNS; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			map[i][j] = type;
		}
	}
}

void assignLocation(Position *pos, GameBoard piece)
{
	int x = pos->x;
	int y = pos->y;
	map[x][y] = piece;
}

int main()
{
	// Initialise map
	initialiseMap(FIELD);

	// Place Monster on map
	vector<Position> monsters;
	for (int i = 0; i < MONSTER_AMOUNT; i++)
	{
		Position p;
		p.x = rand() % MAP_SIZE;
		p.y = rand() % MAP_SIZE;
		monsters.push_back(p);
		map[p.y][p.x] = MONSTER;
	}

	// Place Player on map
	Position playerPosition;
	Position * playerPtrPos;
	playerPtrPos = &playerPosition;
	playerPtrPos->x = 0;
	playerPtrPos->y = 0;
	assignLocation(playerPtrPos, PLAYER);

	// Main game loop
	char moveInput;
	bool gameOver = false;
	bool monsterDetected = false;
	int monstersKilledCounter = 0;
	int monsterNumber;
	while (!gameOver)
	{
		// Player Location
		cout << "Player position = [ y = " << playerPtrPos->y 
			<< ", x = " << playerPtrPos->x << "]" << endl;

		// Monsters Locations
		cout << endl;
		monsterNumber = 1;
		for (int i = 0; i < monsters.size(); i++)
		{
			int mX = monsters[i].x;
			int mY = monsters[i].y;
			cout << "Monster " << monsterNumber
				<< " position = [ y = " << mY
				<< ", x = " << mX << "]" << endl;
			monsterNumber++;
		}

		// Monsters killed
		cout << "Monsters killed = " << monstersKilledCounter << endl;
		cout << endl;

		// Print whole map
		cout << "Game map:" << endl;
		for (int i = 0; i < COLUMNS; i++)
		{
			for (int j = 0; j < ROWS; j++)
			{
				printMapLine(map[i][j]);
			}
			cout << endl;
		}
		cout << endl;

		cout << "Input direction: w=UP, s=DOWN, a=LEFT, d=RIGHT" << endl;
		cin >> moveInput;

		switch (moveInput)
		{
		case 'w':
		case 'W':
		case UP:
			if (playerPtrPos->y > 0)
			{
				cout << "Moving Up..." << endl;
				map[playerPtrPos->y][playerPtrPos->x] = FIELD;
				playerPtrPos->y--;
				if (map[playerPtrPos->y][playerPtrPos->x] == MONSTER)
				{
					monsterDetected = true;
				}
				map[playerPtrPos->y][playerPtrPos->x] = PLAYER;
			}
			else
			{
				cout << "You cannot move up. End of map." << endl;
			}
			break;

		case 's':
		case 'S':
		case DOWN:
			if (playerPtrPos->y < 2)
			{
				cout << "Moving Down..." << endl;
				map[playerPtrPos->y][playerPtrPos->x] = FIELD;
				playerPtrPos->y++;
				if (map[playerPtrPos->y][playerPtrPos->x] == MONSTER)
				{
					monsterDetected = true;
				}
				map[playerPtrPos->y][playerPtrPos->x] = PLAYER;
			}
			else
			{
				cout << "You cannot move down. End of map." << endl;
			}
			break;

		case 'a':
		case 'A':
		case LEFT:
			if (playerPtrPos->x > 0)
			{
				cout << "Moving Left..." << endl;
				map[playerPtrPos->y][playerPtrPos->x] = FIELD;
				playerPtrPos->x--;
				if (map[playerPtrPos->y][playerPtrPos->x] == MONSTER)
				{
					monsterDetected = true;
				}
				map[playerPtrPos->y][playerPtrPos->x] = PLAYER;
			}
			else
			{
				cout << "You cannot move left. End of map." << endl;
			}
			break;

		case 'd':
		case 'D':
		case RIGHT:
			if (playerPtrPos->x < 2)
			{
				cout << "Moving Right..." << endl;
				map[playerPtrPos->y][playerPtrPos->x] = FIELD;
				playerPtrPos->x++;
				if (map[playerPtrPos->y][playerPtrPos->x] == MONSTER)
				{
					monsterDetected = true;
				}
				map[playerPtrPos->y][playerPtrPos->x] = PLAYER;
			}
			else
			{
				cout << "You cannot move right. End of map." << endl;
			}
			break;

		default: cout << "Incorrect input, try again." << endl;
		}
		cout << endl;

		if (monsterDetected == true)
		{
			// insert search monster array here
			for (int i = 0; i < monsters.size(); i++)
			{
				int mX = monsters[i].x;
				int mY = monsters[i].y;
				int pX = playerPtrPos->x;
				int pY = playerPtrPos->y;

				if (mX == pX && mY == pY)
				{
					monsters.erase(monsters.begin() + i);
				}
				// if this monster's xy matches
			}

			monsterDetected = false;
			cout << "You killed a monster!" << endl;
			monstersKilledCounter++;
			cout << endl;
		}

		
		// Move monsters in random directions
		for (int i = 0; i < monsters.size(); i++)
		{
			cout << "Moving monsters..." << endl;
			int mX = monsters[i].x;
			int mY = monsters[i].y;
			int moveMonster = rand() % MONSTER_MOVES;

			switch (moveMonster)
			{
			case 0:
				// UP
				if (mY > 0)
				{
					map[mY][mX] = FIELD;
					mY--;

					if (map[mY][mX] == FIELD)
					{
						monsters[i].y--;
						mY = monsters[i].y;
						map[mY][mX] = MONSTER;
					}
					else
					{
						mY++;
						map[mY][mX] = MONSTER;
					}
				}
				break;

			case 1:
				// DOWN
				if (mY < 2)
				{
					map[mY][mX] = FIELD;
					mY++;

					if (map[mY][mX] == FIELD)
					{
						monsters[i].y++;
						mY = monsters[i].y;
						map[mY][mX] = MONSTER;
					}
					else
					{
						mY--;
						map[mY][mX] = MONSTER;
					}
				}
				break;

			case 2:
				// LEFT
				if (mX > 0)
				{
					map[mY][mX] = FIELD;
					mX--;

					if (map[mY][mX] == FIELD)
					{
						monsters[i].x--;
						mX = monsters[i].x;
						map[mY][mX] = MONSTER;
					}
					else
					{
						mX++;
						map[mY][mX] = MONSTER;
					}
				}
				break;

			case 3:
				// RIGHT
				if (mX < 2)
				{
					map[mY][mX] = FIELD;
					mX++;

					if (map[mY][mX] == FIELD)
					{
						monsters[i].x++;
						mX = monsters[i].x;
						map[mY][mX] = MONSTER;
					}
					else
					{
						mX--;
						map[mY][mX] = MONSTER;
					}
				}
				break;
			}
		}
		
	}

	system("pause");

	return 0;
}
// ---------------------------------------------------------------------------------------
*/



// --------------------- ** Spawn new monsters during runtime ** -------------------------------
enum GameBoard
{
	FIELD, PLAYER, MONSTER
};

enum MoveDirection { UP, DOWN, LEFT, RIGHT };

struct Position
{
	int x, y;
};

const int MONSTER_AMOUNT = 3;
const int MONSTER_MOVES = 4;

const int NUM_OF_CHAR = 3;
string symbol[NUM_OF_CHAR] = { "#", "P", "M" };

const int ROWS = 5;
const int COLUMNS = 5;
const int MAP_SIZE = 5;
int mapContraint = 4;
GameBoard map[COLUMNS][ROWS];

void printMapLine(GameBoard type)
{
	cout << symbol[type] << " ";
}

void initialiseMap(GameBoard type)
{
	for (int i = 0; i < COLUMNS; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			map[i][j] = type;
		}
	}
}

void assignLocation(Position *pos, GameBoard piece)
{
	int x = pos->x;
	int y = pos->y;
	map[x][y] = piece;
}

int main()
{
	// Initialise map
	initialiseMap(FIELD);

	// Place Monster on map
	int monstersAliveCounter = 0;
	vector<Position> monsters;
	for (int i = 0; i < MONSTER_AMOUNT; i++)
	{
		Position p;
		p.x = rand() % MAP_SIZE;
		p.y = rand() % MAP_SIZE;
		monsters.push_back(p);
		map[p.y][p.x] = MONSTER;
		monstersAliveCounter++;
	}

	// Place Player on map
	Position playerPosition;
	Position * playerPtrPos;
	playerPtrPos = &playerPosition;
	playerPtrPos->x = 0;
	playerPtrPos->y = 0;
	assignLocation(playerPtrPos, PLAYER);

	// Main game loop
	char moveInput;
	bool gameOver = false;
	bool monsterDetected = false;
	int monstersKilledCounter = 0;
	int monsterNumber;
	int turnCounter = 3;

	cout << 
	R"(
             _          __  ___   ___   __                        ___
    |\  /|  / \  |\  | (_    |   |     |__)     |  | |   |  |\  |  |
    | \/ | |   | | \ |   \   |   |--   |\       |--| |   |  | \ |  |
    |    |  \_/  |  \| __/   |   |___  | \      |  |  \_/   |  \|  |

	)" << endl;

	cout << "How to play the game:" << endl;
	cout << "Use the wsad keys as input to move the player Up, Down, Left and Right." << endl;
	cout << "Goal: Kill all the remaining monsters by moving into their position." << endl;
	cout << "Avoid: Having too many monsters spawned results in a game over." << endl << endl;

	while (monstersAliveCounter < 6 && monstersAliveCounter != 0)
	{
		// Player Location
		cout << "Player position = [ y = " << playerPtrPos->y
			<< ", x = " << playerPtrPos->x << "]" << endl;

		// Monsters Locations
		monsterNumber = 1;
		for (int i = 0; i < monsters.size(); i++)
		{
			int mX = monsters[i].x;
			int mY = monsters[i].y;
			cout << "Monster " << monsterNumber
				<< " position = [ y = " << mY
				<< ", x = " << mX << "]" << endl;
			monsterNumber++;
		}
		cout << endl;

		// Spawn new monsters
		if (turnCounter == 0)
		{
			Position p;
			p.x = rand() % MAP_SIZE;
			p.y = rand() % MAP_SIZE;

			// If by chance the monster rand coords == player coords...
			if (p.x == playerPtrPos->x && p.y == playerPtrPos->y)
			{
				// ... Try assigning new random coordinates.
				p.x = rand() % MAP_SIZE;
				p.y = rand() % MAP_SIZE;
			}
			monsters.push_back(p);
			map[p.y][p.x] = MONSTER;
			monstersAliveCounter++;
			cout << "A new monster has spawned!" << endl;

			turnCounter = 3;
		}
		else
		{
			cout << "Turns before a new monster spawns = "
				<< turnCounter << endl;
			turnCounter--;
		}
		cout << endl;

		// Monsters killed / alive
		cout << "Monsters alive = " << monstersAliveCounter << endl;
		cout << "Monsters killed = " << monstersKilledCounter << endl;

		cout << endl;

		// Print whole map
		cout << "Game map:" << endl;
		for (int i = 0; i < COLUMNS; i++)
		{
			for (int j = 0; j < ROWS; j++)
			{
				printMapLine(map[i][j]);
			}
			cout << endl;
		}
		cout << endl;

		cout << "Input direction: w=UP, s=DOWN, a=LEFT, d=RIGHT" << endl;
		cin >> moveInput;

		switch (moveInput)
		{
		case 'w':
		case 'W':
		case UP:
			if (playerPtrPos->y > 0)
			{
				cout << "Moving Up..." << endl;
				map[playerPtrPos->y][playerPtrPos->x] = FIELD;
				playerPtrPos->y--;
				if (map[playerPtrPos->y][playerPtrPos->x] == MONSTER)
				{
					monsterDetected = true;
				}
				map[playerPtrPos->y][playerPtrPos->x] = PLAYER;
			}
			else
			{
				cout << "You cannot move up. End of map." << endl;
			}
			break;

		case 's':
		case 'S':
		case DOWN:
			if (playerPtrPos->y < mapContraint)
			{
				cout << "Moving Down..." << endl;
				map[playerPtrPos->y][playerPtrPos->x] = FIELD;
				playerPtrPos->y++;
				if (map[playerPtrPos->y][playerPtrPos->x] == MONSTER)
				{
					monsterDetected = true;
				}
				map[playerPtrPos->y][playerPtrPos->x] = PLAYER;
			}
			else
			{
				cout << "You cannot move down. End of map." << endl;
			}
			break;

		case 'a':
		case 'A':
		case LEFT:
			if (playerPtrPos->x > 0)
			{
				cout << "Moving Left..." << endl;
				map[playerPtrPos->y][playerPtrPos->x] = FIELD;
				playerPtrPos->x--;
				if (map[playerPtrPos->y][playerPtrPos->x] == MONSTER)
				{
					monsterDetected = true;
				}
				map[playerPtrPos->y][playerPtrPos->x] = PLAYER;
			}
			else
			{
				cout << "You cannot move left. End of map." << endl;
			}
			break;

		case 'd':
		case 'D':
		case RIGHT:
			if (playerPtrPos->x < mapContraint)
			{
				cout << "Moving Right..." << endl;
				map[playerPtrPos->y][playerPtrPos->x] = FIELD;
				playerPtrPos->x++;
				if (map[playerPtrPos->y][playerPtrPos->x] == MONSTER)
				{
					monsterDetected = true;
				}
				map[playerPtrPos->y][playerPtrPos->x] = PLAYER;
			}
			else
			{
				cout << "You cannot move right. End of map." << endl;
			}
			break;

		default: cout << "Incorrect input, try again." << endl;
		}

		if (monsterDetected == true)
		{
			// insert search monster array here
			for (int i = 0; i < monsters.size(); i++)
			{
				int mX = monsters[i].x;
				int mY = monsters[i].y;
				int pX = playerPtrPos->x;
				int pY = playerPtrPos->y;

				if (mX == pX && mY == pY)
				{
					monsters.erase(monsters.begin() + i);
				}
				// if this monster's xy matches
			}

			monsterDetected = false;
			cout << "You killed a monster!" << endl;
			monstersKilledCounter++;
			monstersAliveCounter--;
			cout << endl;
		}


		// Move monsters in random directions
		if (monsters.size() != 0)
		{
			cout << "Moving monsters..." << endl;
		}
		for (int i = 0; i < monsters.size(); i++)
		{
			int mX = monsters[i].x;
			int mY = monsters[i].y;
			int moveMonster = rand() % MONSTER_MOVES;

			switch (moveMonster)
			{
			case 0:
				// UP
				if (mY > 0)
				{
					map[mY][mX] = FIELD;
					mY--;

					if (map[mY][mX] == FIELD)
					{
						monsters[i].y--;
						mY = monsters[i].y;
						map[mY][mX] = MONSTER;
					}
					else
					{
						mY++;
						map[mY][mX] = MONSTER;
					}
				}
				break;

			case 1:
				// DOWN
				if (mY < mapContraint)
				{
					map[mY][mX] = FIELD;
					mY++;

					if (map[mY][mX] == FIELD)
					{
						monsters[i].y++;
						mY = monsters[i].y;
						map[mY][mX] = MONSTER;
					}
					else
					{
						mY--;
						map[mY][mX] = MONSTER;
					}
				}
				break;

			case 2:
				// LEFT
				if (mX > 0)
				{
					map[mY][mX] = FIELD;
					mX--;

					if (map[mY][mX] == FIELD)
					{
						monsters[i].x--;
						mX = monsters[i].x;
						map[mY][mX] = MONSTER;
					}
					else
					{
						mX++;
						map[mY][mX] = MONSTER;
					}
				}
				break;

			case 3:
				// RIGHT
				if (mX < mapContraint)
				{
					map[mY][mX] = FIELD;
					mX++;

					if (map[mY][mX] == FIELD)
					{
						monsters[i].x++;
						mX = monsters[i].x;
						map[mY][mX] = MONSTER;
					}
					else
					{
						mX--;
						map[mY][mX] = MONSTER;
					}
				}
				break;
			}
		}
		cout << endl;
	}

	if (monstersAliveCounter == 0)
	{
		cout << "-- Game Won --" << endl;
		cout << "Congrats! You killed all the monsters!" << endl;
		for (int i = 0; i < COLUMNS; i++)
		{
			for (int j = 0; j < ROWS; j++)
			{
				printMapLine(map[i][j]);
			}
			cout << endl;
		}
	}
	else
	{
		cout << "-- Game Lost --" << endl;
		cout << "Too many monsters have spawned! Game over!" << endl;
		for (int i = 0; i < COLUMNS; i++)
		{
			for (int j = 0; j < ROWS; j++)
			{
				printMapLine(map[i][j]);
			}
			cout << endl;
		}
	}

	cout << endl;

	std::this_thread::sleep_for(std::chrono::milliseconds(5000));

	return 0;
}



// **** Implement the game! Including difficulty parameters, menu, game loop, win / lose condition.