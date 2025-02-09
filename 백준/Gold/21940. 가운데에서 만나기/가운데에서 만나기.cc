#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <set>

using namespace std;

int edge[201][201];
vector<int> fr;

int result[201];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (auto e : edge)
		fill(e, e + 201, 210000000);

	for (int i = 1; i <= n; i++)
	{
		edge[i][i] = 0;
	}


	for (int i = 0; i < m; i++)
	{
		int a, b, t;
		cin >> a >> b >> t;

		edge[a][b] = t;
	}

	int k;
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		int a;
		cin >> a;

		fr.push_back(a);
	}


	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				edge[i][j] = min(edge[i][j], edge[i][k] + edge[k][j]);
			}
		}
	}

	
	for (auto a : fr)
	{
		for (int j = 1; j <= n; j++)
		{
			if (result[j] >= 210000000)
				continue;


			result[j] = max(result[j], edge[a][j] + edge[j][a]);
		}
	}


	int min = 210000001;
	set<int> city;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (result[j] <= min && result[j] != 0)
			{
				if (result[j] == min)
				{
					city.insert(j);
				}
				else
				{
					city.clear();
					city.insert(j);
					min = result[j];
				}
				
			}
				
		}
	}

	for (auto a : city)
	{
		cout << a << ' ';
	}

	return 0;
}