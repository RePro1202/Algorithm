#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int board[501][501];
bool check[501][501];

vector<pair<int, int>> block[19];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	block[0] = { {0, 0}, {0, 1}, {0,2}, {0, 3} };
	block[1] = { {0, 0}, {1, 0}, {2,0}, {3, 0} };

	block[2] = { {0, 0}, {0, 1}, {1,0}, {1, 1} };

	block[3] = { {0, 0}, {1, 0}, {2,0}, {2, 1} };
	block[4] = { {1, 0}, {1, 1}, {1,2}, {0, 2} };
	block[5] = { {0, 0}, {0, 1}, {1,1}, {2, 1} };
	block[6] = { {0, 0}, {1, 0}, {0,1}, {0, 2} };

	block[7] = { {0, 0}, {1, 0}, {1,1}, {2, 1} };
	block[8] = { {1, 0}, {1, 1}, {0,1}, {0, 2} };
	block[9] = { {0, 1}, {1, 1}, {1,0}, {2, 0} };
	block[10] = { {0, 0}, {0, 1}, {1,1}, {1, 2} };

	block[11] = { {0, 0}, {0, 1}, {0,2}, {1, 1} };
	block[12] = { {0, 0}, {1, 0}, {2,0}, {1, 1} };
	block[13] = { {1, 0}, {1, 1}, {1,2}, {0, 1} };
	block[14] = { {1, 0}, {0, 1}, {1,1}, {2, 1} };

	block[15] = { {2, 0}, {0, 1}, {1,1}, {2, 1} };
	block[16] = { {0, 0}, {0, 1}, {0,2}, {1, 2} };
	block[17] = { {0, 0}, {1, 0}, {2,0}, {0, 1} };
	block[18] = { {0, 0}, {1, 0}, {1,1}, {1, 2} };


	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++)
			cin >> board[y][x];

	int result = 0;

	for (int i = 0; i < 19; i++)
	{
		vector<pair<int, int>> curBlock = block[i];

		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < m; x++)
			{
				vector<pair<int, int>> newBlock;

				for (int b = 0; b < 4; b++)
				{
					int nx = curBlock[b].second + x;
					int ny = curBlock[b].first + y;

					if (nx < 0 || ny < 0 || ny >= n || nx >= m)
						break;

					newBlock.push_back({ ny, nx });
				}

				if (newBlock.size() < 4)
					continue;

				int sum = 0;
				for (int b = 0; b < 4; b++)
				{
					sum += board[newBlock[b].first][newBlock[b].second];
				}

				if (sum > result)
					result = sum;

			}
		}
	}

	std::cout << result;

	return 0;
}