#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int n, m;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int board[9][9];

int m_count = 0;
int m_maxCount = 0;

class CCTV
{
private:
	int x, y, type;
	bool dir[4] = {};
	vector<pair<int, int>> curSee;

public:
	void excute()
	{
		if (type == 5)
			return;

		unCheck();
		turn();
		check();
	}

public:
	CCTV(int _y, int _x, int _type)
	{
		y = _y;
		x = _x;
		type = _type;

		initDir();
	}

	void check()
	{
		for (int i = 0; i < 4; i++)
		{
			if (dir[i] == 0)
				continue;

			int nx = x;
			int ny = y;

			while (true)
			{
				nx += dx[i];
				ny += dy[i];

				if (nx < 0 || nx >= m || ny < 0 || ny >= n)
					break;
				if (board[ny][nx] == 6)
					break;
				if (board[ny][nx] > 0 && board[ny][nx] < 6)
					continue;


				if (board[ny][nx] >= 7)
				{
					board[ny][nx]++;
				}
				else if(board[ny][nx] == 0)
				{
					board[ny][nx] = 7;
					m_count++;
				}

				curSee.push_back({ ny, nx });
			}
		}
	}

	void unCheck()
	{
		for (auto c : curSee)
		{
			if (board[c.first][c.second] > 7)
			{
				board[c.first][c.second]--;
			}
			else if (board[c.first][c.second] == 7)
			{
				board[c.first][c.second] = 0;
				m_count--;
			}
		}

		curSee.clear();
	}

	void turn()
	{
		if (type == 5)
			return;

		bool newDir[4] = {};

		for (int i = 0; i < 3; i++)
		{
			newDir[i + 1] = dir[i];
		}
		newDir[0] = dir[3];

		for (int i = 0; i < 4; i++)
		{
			dir[i] = newDir[i];
		}
	}

private:
	void initDir()
	{
		switch (type)
		{
		case 1:
			dir[0] = true;
			break;
		case 2:
			dir[0] = true;
			dir[2] = true;
			break;
		case 3:
			dir[0] = true;
			dir[1] = true;
			break;
		case 4:
			dir[0] = true;
			dir[1] = true;
			dir[2] = true;
			break;
		case 5:
			dir[0] = true;
			dir[1] = true;
			dir[2] = true;
			dir[3] = true;
			break;
		default:
			break;
		}
	}

};

vector<CCTV> cctv;

void func(int n)
{
	if (n < 0)
	{
		if (m_count > m_maxCount)
			m_maxCount = m_count;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		cctv[n].excute();
		if (m_count > m_maxCount)
			m_maxCount = m_count;

		func(n - 1);
		if (m_count > m_maxCount)
			m_maxCount = m_count;
	}
}


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int zeroCount = 0;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			cin >> board[y][x];

			if (board[y][x] == 0)
				zeroCount++;

			if (board[y][x] > 0 && board[y][x] < 6)
			{
				cctv.push_back(CCTV(y, x, board[y][x]));
			}
		}
	}

	for (int i = 0; i < cctv.size(); i++)
	{
		cctv[i].check();

		if (m_count > m_maxCount)
			m_maxCount = m_count;
	}

	func(cctv.size() - 1);
	
	cout << zeroCount - m_maxCount;

	return 0;
}