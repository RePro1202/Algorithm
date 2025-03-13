#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    if (n == 0)
    {
        cout << 1;
        return 0;
    }

    long long reuslt = 1;
    for (int i = 1; i <= n; i++)
    {
        reuslt *= i;
    }

    cout << reuslt;

    return 0;
}
