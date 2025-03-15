#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n, p;
    cin >> n >> p;

    long long result = 1;

    for (long long i = 2; i <= n; i++)
    {
        if (i == p)
            continue;

        result *= i % p;
        result %= p;
    }

    cout << result;

    return 0;
}
