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
	return 0;
}

