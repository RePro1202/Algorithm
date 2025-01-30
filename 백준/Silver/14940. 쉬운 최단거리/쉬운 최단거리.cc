#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int board[1001][1001];
int check[1001][1001];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

#define Y first
#define X second

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	pair<int, int> target;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			cin >> board[y][x];

			if (board[y][x] == 2)
			{
				target.X = x;
				target.Y = y;
			}

			if (board[y][x] == 0)
			{
				check[y][x] = -100;
			}
			else
			{
				check[y][x] = 2100000000;
			}
		}
	}

	queue<pair<int, int>> qu;

	qu.push(target);
	check[target.Y][target.X] = 0;

	while (!qu.empty())
	{
		pair<int, int> cur = qu.front();
		qu.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n)
				continue;
			if (board[ny][nx] == 0)
				continue;
			if (check[ny][nx] != 2100000000 || check[ny][nx] == -100)
				continue;
			
			qu.push({ ny, nx });
			check[ny][nx] = check[cur.Y][cur.X] + 1;
		}
	}

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			if (check[y][x] == -100)
			{
				cout << 0 << ' ';
			}
			else if (check[y][x] == 2100000000)
			{
				cout << -1 << ' ';
			}
			else
			{
				cout << check[y][x] << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}