#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;

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
