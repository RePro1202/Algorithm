#include <iostream>
#include <utility>
#include <queue>

using namespace std;

vector<pair<int, int>> node[1001]; // [노드][비용, 연결노드]
bool check[1001];

int main(void)
{
	int n;
	cin >> n;

	for (int j = 1; j <= n; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			int cost;
			cin >> cost;

			if (i > j)
			{
				node[i].push_back({ cost, j });
				node[j].push_back({ cost, i });
			}
		}
	}

	priority_queue<
		pair<int, int>, 
		vector<pair<int, int>>, 
		greater<pair<int, int>>
	> pq;

	for (auto a : node[1])
	{
		pq.push({ a.first, a.second });
	}
	check[1] = 1;

	int count = 0;
	long long minCost = 0;

	while (count < n - 1)
	{
		int cost = pq.top().first;
		int nxt = pq.top().second;
		pq.pop();

		if (check[nxt])
			continue;

		check[nxt] = 1;

		for (auto a : node[nxt])
		{
			pq.push({ a.first, a.second });
		}

		count++;
		minCost += cost;
	}

	cout << minCost;

	return 0;
}