#include <iostream>
using namespace std;

struct Board {
	char spot = ' ';
};

int main()
{
	Board board[3][3];
	cout << "\x1b[33m----------\033[0m" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "\x1b[33m" << board[i][j].spot << " | " << "\033[0m";
		}
		cout << endl;
		cout << "\x1b[33m----------\033[0m" << endl;
	}
	bool validator;

	for (int i = 0; i < 9; i++)
	{
		char xo = (i % 2 == 0 ? 'X' : 'O');
		cout << "\n\x1b[33mNow is your turn : \033[0m" << xo << endl;
		int row, col;
		
		do {
			validator = true;
			cout << "\n\x1b[33mEnter num of row (0-2):\033[0m";
			cin >> row;
			cout << "\n\x1b[33mEnter num of col (0-2):\033[0m";
			cin >> col;
			if (cin.fail())
			{
				cout << "\n\x1b[31mInvalid input! Please, enter just  (0-2) nums:\033[0m";
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				validator = false;
			}
			else if(row < 0 || row > 2 || col < 0 || col > 2)
			{
				cout << "\n\x1b[31mInvalid input! use just 0 or 1 or 2 nums!\033[0m\n" << endl;
				validator = false;
			}
			else if (board[row][col].spot != ' ')
			{
				cout << "\n\x1b[31mThis spot is already taken, please choose another one!\033[0m\n" << endl;
				validator = false;
			}
			else
			{
			board[row][col].spot = xo;
			}
		}while (!validator);

		bool winner = false;
		for (int j = 0; j < 3; j++)
		{
			if (board[j][0].spot == xo && board[j][1].spot == xo && board[j][2].spot == xo) 
			{
				winner = true;
				break;
			}
			if (board[0][j].spot == xo && board[1][j].spot == xo && board[2][j].spot == xo) 
			{
				winner = true;
				break;
			}
		}
		if (board[0][0].spot == xo && board[1][1].spot == xo && board[2][2].spot == xo)
		{
			winner = true;
		}
		if (board[0][2].spot == xo && board[1][1].spot == xo && board[2][0].spot == xo)
		{
			winner = true;
		}
		if (winner)
		{
			cout << xo << "\n\x1b[35m:  WON!!!\033[0m" << endl;
			break;
		}
		if (i == 8)
		{
			cout << xo << "\n\x1b[35mALL OF YOU ARE WINNERS !!!\033[0m" << endl;
			break;
		}
		cout << "\x1b[32m-----------\033[0m" << endl;
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				cout << "\x1b[32m" << board[j][k].spot << " | "<< "\033[0m";
			}
			cout << endl;
			cout << "\x1b[32m-----------\033[0m" << endl;
			
		}
	}
	return 0;

}

