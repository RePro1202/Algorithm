#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> net[101];
bool check[101];

int main(void)
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int e1, e2;
		cin >> e1 >> e2;

		net[e1].push_back(e2);
		net[e2].push_back(e1);
	}

	queue<int> qu;
	check[1] = true;
	
	for (auto a : net[1])
	{
		qu.push(a);
	}

	int count = 0;

	while (!qu.empty())
	{
		int nx = qu.front();
		qu.pop();

		if (check[nx])
			continue;

		for (auto a : net[nx])
		{
			qu.push(a);
		}

		check[nx] = true;
		count++;
	}

	cout << count;

	return 0;
}