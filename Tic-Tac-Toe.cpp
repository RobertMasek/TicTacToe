#define BOARD_WIDTH 3
#define BOARD_HEIGHT 3
#include <iostream>

using namespace std;

enum turn {X, O, empty};

turn currentTurn {X};

turn board[3][3];

void setBoard();
void displayBoard();
bool end();
bool fullBoard();
bool notValid(int x, int y);
void set(int x, int y);
void processTurn();

void setBoard()
{
	for(int i {0}; i < BOARD_WIDTH; i++)
	{
		for(int j {0}; j < BOARD_HEIGHT; j++)
		{
			board[i][j] = empty;
		}
	}	
}

void displayBoard()
{
	for(int i {0}; i < BOARD_HEIGHT; i++)
	{
		for(int j {0}; j < BOARD_WIDTH; j++)
		{
			switch(board[i][j])
			{
				case X:
					cout << "X";
					break;
				case O:
					cout << "O";
					break;
				case empty:
					cout << "_";
					break;
			}
		}
		cout << "\n";
	}
	cout << flush;
}

bool end()
{
	for(int i {0}; i < BOARD_WIDTH; i++)
	{
		if((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != empty)||(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != empty))
		{
			cout << "Player " << board[i][i] + 1 << " Wins!";
			return true;
		}
	}
	if((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != empty) || (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != empty))
	{
		cout << "Player " << board[1][1] + 1 << " Wins!";
		return true;
	}
	if(fullBoard())
	{
		cout << "It's A Tie!";
		return true;
	}
	return false;
}

bool fullBoard()
{
	for(int i {0}; i < BOARD_HEIGHT; i++)
	{
		for(int j {0}; j < BOARD_WIDTH; j++)
		{
			if(board[i][j] == empty)
			{
				return false;
			}
		}
	}
	return true;
}

bool notValid(int x, int y)
{
	if(x >= BOARD_WIDTH || y >= BOARD_HEIGHT || x < 0 || y < 0)
	{
		return true;
	}
	else if(board[y][x] != empty)
	{
		return true;
	}
	return false;
}

void set(int x, int y)
{
	board[y][x] = currentTurn;
}

void processTurn()
{
	int x {-1}, y {-1};
	while(notValid(x,y))
	{
		cin >> x >> y;
		system("CLS");
		displayBoard();
	}
	set(x, y);
	if(currentTurn == X)
	{
		currentTurn = O;
	}
	else
	{
		currentTurn = X;
	}
}

int main()
{
	setBoard();
	while(!end())
	{
		displayBoard();
		processTurn();
		system("CLS");
	}
	return 1;
}
