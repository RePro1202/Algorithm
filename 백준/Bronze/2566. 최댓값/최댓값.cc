#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int max = 0;
    int rx = 1, ry = 1;
    for (int y = 1; y <= 9; y++)
    {
        for (int x = 1; x <= 9; x++)
        {
            int temp;
            cin >> temp;

            if (temp > max)
            {
                max = temp;
                rx = x;
                ry = y;
            }
        }
    }

    cout << max << '\n' << ry << ' ' << rx;

    return 0;
}