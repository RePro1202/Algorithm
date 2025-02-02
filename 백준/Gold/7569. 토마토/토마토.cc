#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[6] = { 1, 0, 0, -1, 0, 0 };
int dy[6] = { 0, 1, 0, 0, -1, 0 };
int dz[6] = { 0, 0, 1, 0, 0, -1 };

int box[101][101][101];
int check[101][101][101];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, n, h;
	cin >> m >> n >> h;


	queue<tuple<int,int,int>> qu;

	int yung = 0;

	for (int z = 0; z < h; z++)
	{
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < m; x++)
			{
				cin >> box[z][y][x];

				if (box[z][y][x] == 1)
				{
					qu.push({ z, y, x });
				}
				else if (box[z][y][x] == 0)
				{
					yung++;
				}
			}
		}
	}

	if (qu.empty())
	{
		cout << -1;
		return 0;
	}
	else if (!qu.empty() && yung == 0)
	{
		cout << 0;
		return 0;
	}

	while (!qu.empty())
	{
		int curX, curY, curZ;
		tie(curZ, curY, curX) = qu.front();
		qu.pop();

		for (int dir = 0; dir < 6; dir++)
		{
			int nx = curX + dx[dir];
			int ny = curY + dy[dir];
			int nz = curZ + dz[dir];

			if (nx < 0 || ny < 0 || nz < 0 || nx >= m || ny >= n || nz >= h)
				continue;
			if (check[nz][ny][nx] != 0)
				continue;
			if (box[nz][ny][nx] != 0)
				continue;

			qu.push({ nz, ny, nx });
			check[nz][ny][nx] = check[curZ][curY][curX] + 1;
			box[nz][ny][nx] = 1;
		}
	}


	int result = 0;

	for (int z = 0; z < h; z++)
	{
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < m; x++)
			{
				if (check[z][y][x] != 0 && result < check[z][y][x])
					result = check[z][y][x];
				
				if (box[z][y][x] == 0)
				{
					cout << -1;
					return 0;
				}
			}
		}
	}

	cout << result;

	return 0;
}