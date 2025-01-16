#include <iostream>
#include <utility>
#include <queue>

using namespace std;

vector<int> v[1001];
bool check[1001];

int main(void)
{
	int t;
	int n, m;
	int a, b;

	cin >> t;
	
	for (int test = 0; test < t; test++)
	{
		cin >> n >> m;

		for (int airplane = 0; airplane < m; airplane++)
		{
			cin >> a >> b;

			v[a].push_back(b);
			v[b].push_back(a);
		}

		queue<pair<int, int>> qu;
		
		for (auto n : v[1])
		{
			qu.push({ 1, n });
		}

		check[1] = 1;

		int count = 0;

		while (!qu.empty())
		{
			int b = qu.front().second;
			qu.pop();

			if (check[b])
				continue;

			for (auto n : v[b])
			{
				qu.push({ b, n });
			}

			count++;
			check[b] = 1;
		}

		cout << count << '\n';

		for (int i = 1; i <= n; i++)
		{
			v[i].clear();
		}

		for (int i = 1; i <= n; i++)
		{
			check[i] = 0;
		}
	}

	return 0;
}