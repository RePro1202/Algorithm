#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int check[101];

map<int, int> w;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n + m; i++)
	{
		int a, b;
		cin >> a >> b;

		w[a] = b;
	}

	int num = 1;

	queue<int> qu;

	fill(check, check + 101, 2100000000);

	check[1] = 0;
	for (int i = 2; i <= 7; i++)
	{
		check[i] = 1;

		if (w.find(i) != w.end())
		{
			check[w[i]] = 1;
			check[i] = 1;
			qu.push(w[i]);
		}
		else
		{
			check[i] = 1;
			qu.push(i);
		}
	}

	while (!qu.empty())
	{
		int cur = qu.front();
		qu.pop();

		for (int i = 1; i <= 6; i++)
		{
			if (check[cur + i] != 2100000000)
				continue;

			if (w.find(cur + i) != w.end())
			{
				if (check[w[cur + i]] < check[cur] + 1)
					continue;

				check[w[cur + i]] = check[cur] + 1;
				check[cur + i] = check[cur] + 1;
				qu.push(w[cur + i]);
			}
			else if (check[cur + i] > check[cur] + 1)
			{
				check[cur + i] = check[cur] + 1;
				qu.push(cur + i);
			}
		}
	}

	cout << check[100];

	return 0;
}