#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX = 1000000000;

int cost[1001][1001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, x;
    cin >> n >> m >> x;

    for (int i = 0; i < 1001; i++)
    {
        for (int j = 0; j < 1001; j++)
        {
            if (i == j)
                continue;
            else
                cost[i][j] = MAX;
        }
    }


    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        cost[a][b] = c;
    }


    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cost[i][j] = min(cost[i][k] + cost[k][j], cost[i][j]);


    int max = 0;
    
    for (int i = 1; i <= n; i++)
    {
        if (cost[i][x] + cost[x][i] > max)
            max = cost[i][x] + cost[x][i];
    }

    cout << max;

    return 0;
}
