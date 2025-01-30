#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

char board[1001][1001];
int check[1001][1001];
int escape[1001][1001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int test = 0; test < t; test++)
	{
		int w, h;
		cin >> w >> h;

		queue<pair<int, int>> fQu;
		pair<int, int> startPos;

		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				cin >> board[y][x];

				check[y][x] = 210000000;
				escape[y][x] = -1;

				if (board[y][x] == '*')
				{
					fQu.push({ y, x });
					check[y][x] = 1;
				}

				if (board[y][x] == '@')
				{
					startPos = { y, x };
				}
			}
		}

		while (!fQu.empty())
		{
			pair<int, int> cur = fQu.front();
			fQu.pop();

			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.second + dx[dir];
				int ny = cur.first + dy[dir];

				if (nx < 0 || nx >= w || ny < 0 || ny >= h)
					continue;
				if (board[ny][nx] == '#' || board[ny][nx] == '*')
					continue;
				if (check[ny][nx] != 210000000)
					continue;
				if (check[ny][nx] <= check[cur.first][cur.second])
					continue;

				fQu.push({ ny, nx });
				check[ny][nx] = check[cur.first][cur.second] + 1;
			}
		}

		queue<pair<int, int>> sQu;
		sQu.push(startPos);
		escape[startPos.first][startPos.second] = 1;

		while (!sQu.empty())
		{
			pair<int, int> cur = sQu.front();
			sQu.pop();

			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.second + dx[dir];
				int ny = cur.first + dy[dir];

				if (nx < 0 || nx >= w || ny < 0 || ny >= h)
					continue;
				if (board[ny][nx] == '#' || board[ny][nx] == '*')
					continue;
				if (escape[ny][nx] != -1)
					continue;
				if (check[ny][nx] <= escape[cur.first][cur.second] + 1)
					continue;
				

				sQu.push({ ny, nx });
				escape[ny][nx] = escape[cur.first][cur.second] + 1;
			}
		}

		int minTime = 210000000;

		for (int x = 0; x < w; x++)
		{
			if (escape[0][x] != -1 && board[0][x] != '#' && board[0][x] != '*')
			{
				if (escape[0][x] < minTime)
					minTime = escape[0][x];
			}

			if (escape[h - 1][x] != -1 && board[h - 1][x] != '#' && board[h - 1][x] != '*')
			{
				if (escape[h - 1][x] < minTime)
					minTime = escape[h - 1][x];
			}
		}

		for (int y = 0; y < h; y++)
		{
			if (escape[y][0] != -1 && board[y][0] != '#' && board[y][0] != '*')
			{
				if (escape[y][0] < minTime)
					minTime = escape[y][0];
			}

			if (escape[y][w - 1] != -1 && board[y][w - 1] != '#' && board[y][w - 1] != '*')
			{
				if (escape[y][w - 1] < minTime)
					minTime = escape[y][w - 1];
			}
		}

		if (minTime == 210000000)
		{
			cout << "IMPOSSIBLE";
		}
		else
		{
			cout << minTime;
		}

		cout << '\n';
	}

	return 0;
}