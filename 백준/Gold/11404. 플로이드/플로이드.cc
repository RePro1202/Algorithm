#include <iostream>

using namespace std;

int bus[101][101];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		fill(bus[i], bus[i] + n + 1, 100000000);
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		bus[a][b] = min(bus[a][b], c);
	}

	for (int i = 1; i <= n; i++)
	{
		bus[i][i] = 0;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int i = 1; i <= n; i++)
			{
				bus[i][j] = min(bus[i][j], bus[i][k] + bus[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (bus[i][j] == 100000000)
				cout << 0;
			else
				cout << bus[i][j];

			cout << ' ';
		}
		cout << '\n';
	}

	return 0;
}