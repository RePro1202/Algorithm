#include <iostream>
#include <algorithm>

using namespace std;

int arr[101];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int a = 0; a < m; a++)
    {
        int i, j, k;
        cin >> i >> j >> k;

        fill(arr + i, arr + j + 1, k);
    }

    for (int i = 1; i <= n; i++)
        cout << arr[i] << ' ';

    return 0;
}