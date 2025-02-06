#include <iostream>

using namespace std;

int board[101][101];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (board[i][j] == 1)
					continue;

				if (board[i][k] && board[k][j])
					board[i][j] = 1;
			}
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}