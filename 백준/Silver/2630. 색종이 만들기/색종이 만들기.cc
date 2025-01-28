#include <iostream>

using namespace std;

int board[129][129];

int white = 0;
int blue = 0;

int func(int n, int ltX, int ltY)
{
	int er[4];

	if (n == 1)
	{
		return board[ltX][ltY];
	}
	
	er[0] = func(n / 2, ltY, ltX); // left top
	er[1] = func(n / 2, ltY + n / 2, ltX); // left bottom
	er[2] = func(n / 2, ltY, ltX + n / 2); // right top
	er[3] = func(n / 2, ltY + n / 2, ltX + n / 2); // right bottom

	int sum = 0;
	for (auto a : er)
		sum += a;

	if (sum == 0)
	{
		return 0;
	}
	else if (sum == 4)
	{
		return 1;
	}
	else
	{
		for (auto a : er)
		{
			if (a == 0)
				white++;
			else if(a == 1)
				blue++;
		}

		return 5;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			cin >> board[y][x];
		}
	}

	if (n == 2)
	{
		int er[4];

		er[0] = board[0][0];
		er[1] = board[1][0];
		er[2] = board[0][1];
		er[3] = board[1][1];

		int sum = 0;
		for (auto a : er)
			sum += a;

		if (sum == 0)
		{
			white++;
		}
		else if (sum == 4)
		{
			blue++;
		}
		else
		{
			for (auto a : er)
			{
				if (a == 0)
					white++;
				else if (a == 1)
					blue++;
			}
		}
	}
	else
	{
		int temp = func(n, 0, 0);

		if (temp == 0)
			white++;
		if (temp == 1)
			blue++;
	}
	
	cout << white << '\n' << blue;

	return 0;
}