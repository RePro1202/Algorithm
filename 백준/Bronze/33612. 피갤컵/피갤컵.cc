#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int y = 2024;
    int m = 8;
    n -= 1;

    m += n * 7;
    y += m / 13;
    m %= 12;
    
    if (m == 0)
        m = 12;

    cout << y << ' ' << m;

    return 0;
}
