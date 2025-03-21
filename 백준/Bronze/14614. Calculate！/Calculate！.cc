#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    string sc;

    cin >> a >> b >> sc;

    c = sc.back() - '0';

    if (c % 2 != 0)
    {
        a = a ^ b;
    }
    else
    {
        a = a ^ b;
        a = a ^ b;
    }

    cout << a;

    return 0;
}
