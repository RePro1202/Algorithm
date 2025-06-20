#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        // 공백
        for (int j = 0; j < n - i; j++)
            cout << ' ';

        // 별
        for (int j = 0; j < i * 2 - 1; j++)
            cout << '*';

        if(i < n)
            cout << '\n';
    }

    return 0;
}