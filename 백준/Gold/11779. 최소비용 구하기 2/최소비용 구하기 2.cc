#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAX = 210000000;

#define COST first
#define Y second

vector<pair<int, int>> edge[1001]; // [a].c b
int minCost[1001];
int path[1001];

int main(void)
{
	int n, m, st, dest;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		edge[a].push_back({ c, b });
	}
	cin >> st >> dest;

	fill(minCost, minCost + n + 1, MAX);
	minCost[st] = 0;

	priority_queue<
		pair<int, int>, 
		vector<pair<int, int>>, 
		greater<pair<int, int>>
	> qu;

	qu.push({ minCost[st], st });

	// 다익스트라
	while (!qu.empty())
	{
		pair<int, int> cur = qu.top();
		qu.pop();

		if (cur.COST != minCost[cur.Y])
			continue;

		for (auto nx : edge[cur.Y])
		{
			if (minCost[nx.Y] <= nx.COST + minCost[cur.Y])
				continue;

			minCost[nx.Y] = nx.COST + minCost[cur.Y];
			qu.push({ minCost[nx.Y], nx.Y });
			path[nx.Y] = cur.Y;
		}
	}

	// 경로복원
	vector<int> route;
	int s = dest;
	while (true)
	{
		route.push_back(s);

		if (s == st)
			break;

		s = path[s];
	}

	// 출력
	cout << minCost[dest] << '\n';
	cout << route.size() << '\n';

	reverse(route.begin(), route.end());

	for (auto a : route)
		cout << a << ' ';

	return 0;
}