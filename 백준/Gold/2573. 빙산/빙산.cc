#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int board[301][301];
int check[301][301];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	queue<pair<int,int>> qu;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			cin >> board[y][x];

			if (board[y][x] != 0)
			{
				qu.push({ y, x });
			}
		}
	}


	int year = 1;
	while (true)
	{
		queue<pair<int, int>> ch;

		int land = qu.size();
		vector<pair<int, int>> v;

		for (int i = 0; i < land; i++)
		{
			int curY = qu.front().first;
			int curX = qu.front().second;
			qu.pop();

			for (int dir = 0; dir < 4; dir++)
			{
				int ny = curY + dy[dir];
				int nx = curX + dx[dir];

				if (ny < 0 || nx < 0 || ny >= n || nx >= m)
					continue;
				if (board[ny][nx] != 0)
					continue;

				board[curY][curX]--;
			}

			if (board[curY][curX] <= 0)
			{
				board[curY][curX] = -1;
				v.push_back({ curY, curX });
			}

			if (board[curY][curX] > 0)
			{
				if(ch.empty())
					ch.push({ curY, curX });

				qu.push({ curY, curX });
			}
		}


		for (auto a : v)
		{
			board[a.first][a.second] = 0;
		}


		// 분할 여부 체크
		int count = 0;

		while (!ch.empty())
		{
			int curY = ch.front().first;
			int curX = ch.front().second;
			ch.pop();

			for (int dir = 0; dir < 4; dir++)
			{
				int ny = curY + dy[dir];
				int nx = curX + dx[dir];

				if (ny < 0 || nx < 0 || ny >= n || nx >= m)
					continue;
				if (board[ny][nx] == 0)
					continue;
				if (check[ny][nx] != 0)
					continue;

				v.push_back({ ny, nx });
				ch.push({ ny, nx });
				check[ny][nx]++;
				count++;
			}
		}


		// 결과 체크
		if (count == 0 && qu.empty())
		{
			cout << 0;
			return 0;
		}
		else if (count == qu.size())
		{
			year++;

			for (auto a : v)
				check[a.first][a.second] = 0;

			continue;
		}
		else
		{
			cout << year;
			return 0;
		}
	}
	
	return 0;
}