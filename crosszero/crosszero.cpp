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
			cout << board[i][j].spot << "\x1b[33m | \033[0m";
		}
		cout << endl;
		cout << "\x1b[33m----------\033[0m" << endl;
	}


	for (int i = 0; i < 9; i++)
	{
		char xo = (i % 2 == 0 ? 'X' : 'O');
		cout << "\x1b[33mNow is your turn : \033[0m" << xo << endl;
		int row, col;
		do {
			cout << "\x1b[33mEnter num of row (0-2):\033[0m";
			cin >> row;
			cout << "\x1b[33mEnter num of col (0-2):\033[0m";
			cin >> col;
		} while (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col].spot != ' ');

		board[row][col].spot = xo;

	}
	return 0;
}

