//Ayush Pratap Singh
//Basic One Player Tic Tac Toe

#include <bits/stdc++.h>
using namespace std;
int pos;
char board[9] = {'*', '*', '*', '*', '*', '*', '*', '*', '*'}; // Single array represents the board '*' means empty box in board

int isFull() // Board is full
{
	for (int i = 0; i < 9; i++)
	{
		if (board[i] != 'X')
		{
			if (board[i] != 'O')
			{
				return 0;
			}
		}
	}
	return 1;
}

int user_won() //Checks whether user has won
{
	for (int i = 0; i < 9; i += 3)
	{
		if ((board[i] == board[i + 1]) && (board[i + 1] == board[i + 2]) && (board[i] == 'O'))
			return 1;
	}
	for (int i = 0; i < 3; i++)
	{
		if ((board[i] == board[i + 3]) && (board[i + 3] == board[i + 6]) && (board[i] == 'O'))
			return 1;
	}
	if ((board[0] == board[4]) && (board[4] == board[8]) && (board[0] == 'O'))
	{
		return 1;
	}
	if ((board[2] == board[4]) && (board[4] == board[6]) && (board[2] == 'O'))
	{
		return 1;
	}
	return 0;
}

int cpu_won() // Checks whether CPU has won
{
	for (int i = 0; i < 9; i += 3)
	{
		if ((board[i] == board[i + 1]) && (board[i + 1] == board[i + 2]) && (board[i] == 'X'))
			return 1;
	}
	for (int i = 0; i < 3; i++)
	{
		if ((board[i] == board[i + 3]) && (board[i + 3] == board[i + 6]) && (board[i] == 'X'))
			return 1;
	}
	if ((board[0] == board[4]) && (board[4] == board[8]) && (board[0] == 'X'))
	{
		return 1;
	}
	if ((board[2] == board[4]) && (board[4] == board[6]) && (board[2] == 'X'))
	{
		return 1;
	}
	return 0;
}

void draw_board() //display tic-tac-toe board
{
	cout << endl;
	cout << board[0] << "|" << board[1] << "|" << board[2] << endl;
	cout << "-----" << endl;
	cout << board[3] << "|" << board[4] << "|" << board[5] << endl;
	cout << "-----" << endl;
	cout << board[6] << "|" << board[7] << "|" << board[8] << endl;
}

int minimax(bool flag) // The minimax function
{

	int max_val = -1000, min_val = 1000;
	int i, j, value = 1;
	if (cpu_won() == 1)
	{
		return 10;
	}
	else if (user_won() == 1)
	{
		return -10;
	}
	else if (isFull() == 1)
	{
		return 0;
	}
	int score[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1}; //if score[i]=1 then it is empty

	for (i = 0; i < 9; i++)
	{
		if (board[i] == '*')
		{
			if (min_val > max_val) // reverse of pruning condition.....
			{
				if (flag == true)
				{
					board[i] = 'X';
					value = minimax(false);
				}
				else
				{
					board[i] = 'O';
					value = minimax(true);
				}
				board[i] = '*';
				score[i] = value;
			}
		}
	}

	if (flag == true)
	{
		max_val = -1000;
		for (j = 0; j < 9; j++)
		{
			if (score[j] > max_val && score[j] != 1)
			{
				max_val = score[j];
				pos = j;
			}
		}
		return max_val;
	}
	if (flag == false)
	{
		min_val = 1000;
		for (j = 0; j < 9; j++)
		{
			if (score[j] < min_val && score[j] != 1)
			{
				min_val = score[j];
				pos = j;
			}
		}
		return min_val;
	}
}

int main() //The main function
{
	int move, choice;
	cout << "--------TIC TAC TOE <<Ayush Pratap Singh_XO>>--------"
		 << "\n";
	cout << "USER--->(O)"
		 << "\n";
	cout << "CPU------>(X)"
		 << "\n";
	cout << "SELECT : 1-> Player first"
		 << "\n";
	cout << "SELECT : 2-> CPU first:"
		 << "\n";
	cin >> choice;
	if (choice == 1)
	{
		draw_board();
	up:
		cout << endl
			 << "Enter the value (1 to 9) for the move:";
		cin >> move;
		if (board[move - 1] == '*')
		{
			board[move - 1] = 'O';
			draw_board();
		}
		else
		{
			cout << endl
				 << "Invalid Move......Try different move";
			goto up;
		}
	}

	while (true)
	{

		cout << endl
			 << "CPU MOVE....";
		minimax(true);
		board[pos] = 'X';
		draw_board();
		if (cpu_won() == 1)
		{
			cout << endl
				 << "CPU WON.....";
			break;
		}
		if (isFull() == 1)
		{
			cout << endl
				 << "It's A DRAW....";
			break;
		}
	again:
		cout << endl
			 << "Enter the value (1 to 9) for the move:";
		cin >> move;
		if (board[move - 1] == '*')
		{
			board[move - 1] = 'O';
			draw_board();
		}
		else
		{
			cout << endl
				 << "Invalid Move......Try different move";
			goto again;
		}
		if (user_won() == 1)
		{
			cout << endl
				 << "You WON......";
			break;
		}
		if (isFull() == 1)
		{
			cout << endl
				 << "It's A DRAW....";
			break;
		}
	}
}