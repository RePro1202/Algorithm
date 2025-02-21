#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> edge[101];
int check[101];

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    

    int min = 1000000000;
    vector<int> v;

    for (int i = 1; i <= n; i++)
    {
        fill(check, check + 101, 1000000000);

        queue<int> qu;

        qu.push(i);
        check[i] = 0;

        while (!qu.empty())
        {
            int cur = qu.front();
            qu.pop();

            for (auto a : edge[cur])
            {
                if (check[a] != 1000000000)
                    continue;

                qu.push(a);
                check[a] = check[cur] + 1;
            }
        }

        int sum = 0;
        for (int j = 1; j <= n; j++)
        {
            if (j == i)
                continue;

            sum += check[j];
        }

        if (sum == min)
        {
            v.push_back(i);
        }
        if (sum < min)
        {
            v.clear();
            v.push_back(i);

            min = sum;
        }
            
    }

    cout << v.front();

    return 0;
}