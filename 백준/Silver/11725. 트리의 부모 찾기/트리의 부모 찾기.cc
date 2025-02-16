#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> node[100001];
int pa[100001];

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    queue<int> qu;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        node[a].push_back(b);
        node[b].push_back(a);
    }


    qu.push(1);

    while(!qu.empty())
    {
        int n = qu.front();
        qu.pop();

        for (auto a : node[n])
        {
            if (pa[a] != 0)
                continue;

            pa[a] = n;
            qu.push(a);
        }
    }

    for (int i = 2; i <= n; i++)
    {
        cout << pa[i] << '\n';
    }

    return 0;
}