#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int indegree[32001];
vector<int> edge[32001];
vector<int> result;

int main(void) {
    
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        edge[a].push_back(b);
        indegree[b]++;
    }

    queue<int> qu;

    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
            qu.push(i);
    }

    while (!qu.empty())
    {
        int cur = qu.front();
        qu.pop();

        if (indegree[cur] == 0)
        {
            result.push_back(cur);

            for (auto a : edge[cur])
            {
                indegree[a]--;

                if (indegree[a] == 0)
                    qu.push(a);
            }
        }
    }
    
    for (auto a : result)
    {
        cout << a << ' ';
    }

    return 0;
}