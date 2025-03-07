#include <iostream>

using namespace std;

int arr[101];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= 100; i++)
        arr[i] = i;

    for (int t = 0; t < m; t++)
    {
        int i, j;
        cin >> i >> j;

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    for (int i = 1; i <= n; i++)
        cout << arr[i] << ' ';

    return 0;
}
