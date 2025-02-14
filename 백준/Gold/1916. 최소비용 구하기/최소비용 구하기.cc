#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

#define X first
#define Y second

const int MAX = 1000000000;

vector<pair<int, int>> edge[1001];
int minCost[1001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    int st, dest;

    // 입력
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        edge[a].push_back({ c, b });
    }
    cin >> st >> dest;

    fill(minCost, minCost + n + 1, MAX);

    // 다익스트라
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > qu;

    minCost[st] = 0;
    qu.push({ minCost[st], st });

    while (!qu.empty())
    {
        pair<int, int> cur = qu.top();
        qu.pop();

        if (cur.X != minCost[cur.Y])
            continue;

        for (auto nx : edge[cur.Y])
        {
            if (minCost[nx.Y] <= nx.X + minCost[cur.Y])
                continue;

            minCost[nx.Y] = nx.X + minCost[cur.Y];
            qu.push({ minCost[nx.Y], nx.Y });
        }
    }

    cout << minCost[dest];

    return 0;
}