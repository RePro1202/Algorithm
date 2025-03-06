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

    for (int i = 1; i <= n; i++)
    {
        arr[i] = i;
    }

    for (int a = 0; a < m; a++)
    {
        int i, j;
        cin >> i >> j;

        reverse(arr + i, arr + j + 1);
    }

    for (int i = 1; i <= n; i++)
        cout << arr[i] << ' ';

    return 0;
}