#include <iostream>

using namespace std;

// GCD(a, b) * LCM(a, b) = a * b

int GCD(int a, int b)
{
    return b == 0 ? a : GCD(b, a % b);
}

int LCM(int a, int b)
{
    return a / GCD(a, b) * b;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int a, b;
        cin >> a >> b;

        cout << LCM(a, b) << '\n';
    }

    return 0;
}