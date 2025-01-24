#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> node[1001];
bool check[1001];

int main(void)
{
	int n, m, v;

	cin >> n >> m >> v;

	for (int i = 0; i < m; i++)
	{
		int e1, e2;

		cin >> e1 >> e2;

		node[e1].push_back(e2);
		node[e2].push_back(e1);
	}

	//DFS
	for (int i = 1; i <= n; i++)
	{
		sort(node[i].begin(), node[i].end(), greater<int>());
	}

	stack<int> st;

	for (auto a : node[v])
	{
		st.push(a);
	}

	check[v] = true;
	cout << v << ' ';

	while (!st.empty())
	{
		int t = st.top();
		st.pop();

		if (check[t] == true)
			continue;

		check[t] = true;
		cout << t << ' ';

		for (auto a : node[t])
		{
			st.push(a);
		}
	}


	cout << '\n';

	for (int i = 0; i < 1001; i++)
	{
		check[i] = false;
	}

	//BFS
	for (int i = 1; i <= n; i++)
	{
		sort(node[i].begin(), node[i].end());
	}

	queue<int> qu;

	for (auto a : node[v])
	{
		qu.push(a);
	}

	check[v] = true;
	cout << v << ' ';

	while (!qu.empty())
	{
		int t = qu.front();
		qu.pop();

		if (check[t] == true)
			continue;

		check[t] = true;
		cout << t << ' ';

		for (auto a : node[t])
		{
			qu.push(a);
		}
	}


	return 0;
}