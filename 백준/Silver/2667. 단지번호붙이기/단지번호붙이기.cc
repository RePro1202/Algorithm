#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

bool board[26][26];
int check[26][26];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

#define Y first
#define X second

queue<pair<int, int>> que;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int oneCount = 0;

	for (int y = 0; y < n; y++)
	{
		string str;
		cin >> str;

		for (int x = 0; x < n; x++)
		{
			if (str[x] == '0')
			{
				board[y][x] = 0;
			}
			else
			{
				board[y][x] = 1;
				oneCount++;
			}
		}
	}


	vector<int> group;

	while (oneCount > 0)
	{
		int count = 0;

		if (que.empty())
		{
			for (int ly = 0; ly < n; ly++)
			{
				for (int lx = 0; lx < n; lx++)
				{
					if (board[ly][lx] == 1 && check[ly][lx] == 0)
					{
						que.push({ ly, lx });
						check[ly][lx] = 1;
						count++;
						break;
					}
				}

				if (!que.empty())
					break;
			}
		}

		while (!que.empty())
		{
			pair<int, int> cur = que.front();
			que.pop();

			for (int dir = 0; dir < 4; dir++)
			{
				int ny = cur.Y + dy[dir];
				int nx = cur.X + dx[dir];

				if (ny < 0 || nx < 0 || ny >= n || nx >= n)
					continue;
				if (board[ny][nx] == 0)
					continue;
				if (check[ny][nx] != 0)
					continue;

				check[ny][nx] = 1;
				count++;
				que.push({ ny, nx });
			}
		}

		group.push_back(count);
		oneCount -= count;
	}
	

	sort(group.begin(), group.end());

	cout << group.size() << '\n';
	for (auto a : group)
	{
		cout << a << '\n';
	}

	return 0;
}