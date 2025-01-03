#include <iostream>
#include <tuple>
#include <vector>
#include <queue>

using namespace std;

int v, e;
vector<pair<int, int>> vertex[10001]; // [기준정점][비용, 연결정점]

bool check[10001]; // 정점 방문여부

int main(void)
{
	cin >> v >> e;

	for (int i = 0; i < e; i++)
	{
		int a, b, cost;

		cin >> a >> b >> cost;

		vertex[a].push_back({ cost, b });
		vertex[b].push_back({ cost, a });
	}

	// 비용, 기준정점, 연결정점
	priority_queue <
		tuple<int, int, int>,
		vector<tuple<int, int, int>>,
		greater<tuple<int, int, int>>
	> pq;

	
	check[1] = 1;

	for (int i = 0; i < vertex[1].size(); i++)
	{
		pq.push({ vertex[1][i].first, 1,vertex[1][i].second });
	}


	int count = 0;
	int totalWeight = 0;

	while (count < v - 1)
	{
		int weight, A, B;
		tie(weight, A, B) = pq.top();
		pq.pop();

		if (check[B]) continue;

		check[B] = 1;
		totalWeight += weight;

		// 방문한 정점의 간선 중 미방문 정점으로 이어진 간선만 추가
		for (auto t : vertex[B])
		{
			if (!check[t.second])
			{
				pq.push({ t.first, B, t.second });
			}
		}

		count++;

	}

	cout << totalWeight;

	return 0;
}