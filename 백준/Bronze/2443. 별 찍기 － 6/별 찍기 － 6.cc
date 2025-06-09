#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        // 앞 공백
        for (int j = 0; j < i; j++)
            cout << ' ';

        // 별
        for (int j = 0; j < 2 * n - (1 + 2 * i); j++)
            cout << '*';

        if(i < n-1)
            cout << '\n';
    }

    return 0;
}