#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> edge[1001];
bool check[1001];

int main(void)
{
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;

		edge[x].push_back(y);
		edge[y].push_back(x);
	}

	queue<int> qu;
	int count = 0;

	for (int i = 1; i <= n; i++)
	{
		if (check[i] != 0)
			continue;

		qu.push(i);

		while (!qu.empty())
		{
			int cur = qu.front(); qu.pop();

			if (check[cur])
				continue;

			check[cur] = true;

			for (auto v : edge[cur])
			{
				if(check[v] == 0)
					qu.push(v);
			}
		}

		count++;
	}

	cout << count;

	return 0;
}