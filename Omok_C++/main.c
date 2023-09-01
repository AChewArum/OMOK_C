#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<string.h>


#define BLACK 1
#define WHITE 2
#define NONE 0
#define BOARD_MAX  6
#define MAIN_X_ADJ 31
#define MAIN_Y_ADJ 10


void gotoxy(int x, int y);

void DrawBoard();
void DrawStone(int _x, int _y, int _stone);
int CheckFive(int _stone);


int board[BOARD_MAX][BOARD_MAX] =
{
	{1, 0, 1, 2, 0, 0},
	{0,1, 0,0, 0, 0},
	{0, 0, 1, 2, 0, 0},
	{0, 0, 1, 1, 0, 0},
	{0, 0, 1, 2,1, 0},
	{0, 0, 1, 2, 0, 0},
};

int main()
{
	DrawBoard();
	CheckFive(BLACK);
	CheckFive(WHITE);
	return 0;
}

void gotoxy(int x, int y)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){x * 2, y});
}

void DrawBoard()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	for (int _x = 0; _x < BOARD_MAX; _x++)
	{
		for (int _y = 0; _y < BOARD_MAX; _y++)
		{
			gotoxy(MAIN_X_ADJ + _x, MAIN_Y_ADJ + _y);

			if (_x == BOARD_MAX - 1)
			{
				printf("式托式");
			}

			else
			{
				printf("式托");
			}
		}
	}

	for (int _x = 0; _x < BOARD_MAX; _x++)
	{
		for (int _y = 0; _y < BOARD_MAX; _y++)
		{
			gotoxy(MAIN_X_ADJ + _x, MAIN_Y_ADJ + _y);

			if (_x == BOARD_MAX - 1)
			{
				printf("式托式");
			}

			else
			{
				DrawStone(_x, _y, board[_x][_y]);
			}
		}
	}
}


void DrawStone(int _x, int _y, int _stone)
{
	switch (_stone)
	{
	case BLACK:
		printf(" ∞");
		break;

	case WHITE:
		printf(" ≒");
		break;

	default:

		break;
	}
}

int CheckFive(int _stone)
{
	int dir[4] = {0};
	for (int _x = 0; _x < BOARD_MAX; _x++)
	{
		for (int _y = 0; _y < BOARD_MAX; _y++)
		{
			if (board[_x][_y] == _stone)
			{
				for (int i = 1; i < 5; i++)
				{
					if (_x + i < BOARD_MAX && board[_x + i][_y] == _stone)
					{
						dir[0]++;
					}
					if (_y + i < BOARD_MAX && board[_x][_y + i] == _stone)
					{
						dir[1]++;
					}
					if ((_x + i < BOARD_MAX && _y + i < BOARD_MAX) && board[_x + i][_y + i] == _stone)
					{
						dir[2]++;
					}
					if ((_x + i < BOARD_MAX && _y - i >= 0) && board[_x + i][_y - i] == _stone)
					{
						dir[3]++;
					}
				}


				/// 
				for (int _dir = 0; _dir < 4; _dir++)
				{
 					if (dir[_dir] >= 4)
					{
						printf("\nSucces\n");
						return _stone;
					}
					else
					{
						dir[_dir] = 0;
					}
				}
			}
			else
			{
			}

		} 
	}


}
