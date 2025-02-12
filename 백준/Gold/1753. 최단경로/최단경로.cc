#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

const int INF = 210000000;

using namespace std;

vector<pair<int, int>> edge[20001]; // 
int leastCost[20001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int v, e, k;
	cin >> v >> e >> k;

	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		edge[u].push_back({ w, v });
	}

	fill(leastCost, leastCost + v + 1, INF);

	priority_queue<
		pair<int, int>, 
		vector<pair<int, int>>, 
		greater<pair<int, int>>
	> qu;

	leastCost[k] = 0;
	qu.push({ 0, k });

	while (!qu.empty())
	{
		pair<int, int> cur = qu.top();
		qu.pop();

		if (leastCost[cur.second] != cur.first)
			continue;

		for (auto nx : edge[cur.second])
		{
			if (leastCost[nx.second] <= leastCost[cur.second] + nx.first)
				continue;

			leastCost[nx.second] = leastCost[cur.second] + nx.first;
			qu.push({ leastCost[nx.second], nx.second });
		}
	}

	for (int i = 1; i <= v; i++)
	{
		if (leastCost[i] == INF)
			cout << "INF" << '\n';
		else
			cout << leastCost[i] << '\n';
	}

	return 0;
}