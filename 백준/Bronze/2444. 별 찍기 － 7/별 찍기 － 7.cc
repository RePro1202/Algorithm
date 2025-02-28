#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i <= (2 * n) - 1; i++)
    {
        int star;

        if (i > n - 1)
            star = ((2 * n) - 1) - (i % n * 2);
        else if (i == n - 1)
            continue;
        else
            star = (i * 2) + 1;

        int emp = ((2 * n) - 1) - star;


        for (int t = 0; t < emp / 2; t++)
            cout << " ";

        for (int t = 0; t < star; t++)
            cout << "*";

        cout << '\n';
    }

    return 0;
}
