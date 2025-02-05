#include <iostream>
#include <vector>

using namespace std;

int map[101];
int edge[101][101];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, r;
	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++)
	{
		cin >> map[i];
	}
	for (auto a : edge)
	{
		fill(a, a + 101, 210000000);
	}

	for (int i = 0; i < r; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		edge[a][b] = c;
		edge[b][a] = c;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i == j)
				{
					edge[i][j] = 0;
					continue;
				}

				edge[i][j] = min(edge[i][j], edge[i][k] + edge[k][j]);
			}
		}
	}

	int max = 0;

	for (int i = 1; i <= n; i++)
	{
		int sum = 0;

		for (int j = 1; j <= n; j++)
		{
			if (edge[i][j] <= m)
			{
				sum += map[j];
			}
		}

		if (sum > max)
			max = sum;
	}

	cout << max;

	return 0;
}