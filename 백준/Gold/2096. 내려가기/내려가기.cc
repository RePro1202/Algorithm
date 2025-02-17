#include <iostream>
#include <cmath>
using namespace std;

int max_adj[3];
int min_adj[3];

int pre_max_adj[3];
int pre_min_adj[3];

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int index = 0;

    for (int i = 1; i <= n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        max_adj[0] = max(pre_max_adj[0], pre_max_adj[1]) + a;
        max_adj[1] = max(max(pre_max_adj[0], pre_max_adj[1]), pre_max_adj[2]) + b;
        max_adj[2] = max(pre_max_adj[2], pre_max_adj[1]) + c;

        min_adj[0] = min(pre_min_adj[0], pre_min_adj[1]) + a;
        min_adj[1] = min(min(pre_min_adj[0], pre_min_adj[1]), pre_min_adj[2]) + b;
        min_adj[2] = min(pre_min_adj[2], pre_min_adj[1]) + c;

        for (int j = 0; j < 3; j++)
        {
            pre_max_adj[j] = max_adj[j];
            pre_min_adj[j] = min_adj[j];
        }
    }

    cout << max(max(max_adj[0], max_adj[1]), max_adj[2]) << ' '
        << min(min(min_adj[0], min_adj[1]), min_adj[2]);

    return 0;
}