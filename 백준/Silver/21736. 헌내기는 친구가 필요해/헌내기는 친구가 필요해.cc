#include <iostream>
#include <string>
#include <queue>
#include <utility>

using namespace std;

#define Y first
#define X second

char board[601][601];
bool check[601][601];

int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	queue<pair<int, int>> qu;

	for (int y = 0; y < n; y++)
	{
		string str;
		cin >> str;

		for (int x = 0; x < m; x++)
		{
			board[y][x] = str[x];

			if (board[y][x] == 'I')
			{
				qu.push({ y, x });
				check[y][x] = true;
			}
		}
	}

	int count = 0;

	while (!qu.empty())
	{
		pair<int, int> cur = qu.front();
		qu.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int ny = cur.Y + dy[dir];
			int nx = cur.X + dx[dir];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;
			if (board[ny][nx] == 'X')
				continue;
			if (check[ny][nx] == true)
				continue;

			check[ny][nx] = true;

			if (board[ny][nx] == 'P')
				count++;

			qu.push({ ny, nx });
		}
	}


	if (count == 0)
		cout << "TT";
	else
		cout << count;

	return 0;
}