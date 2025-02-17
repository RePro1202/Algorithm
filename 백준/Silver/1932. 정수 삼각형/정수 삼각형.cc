#include <iostream>
#include <algorithm>

using namespace std;

int tr [501][501];

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            int temp;
            cin >> temp;

            if (i == 1 && j == 1)
            {
                tr[i][j] = temp;
                continue;
            }
            
            tr[i][j] = temp + max(tr[i - 1][j], tr[i - 1][j - 1]);
        }
    }

    int max = 0;
    for (int j = 1; j <= n; j++)
    {
        if (tr[n][j] > max)
        {
            max = tr[n][j];
        }
    }

    cout << max;

    return 0;
}