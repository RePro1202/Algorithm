#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        int temp;
        cin >> temp;

        sum += temp;
    }

    cout << sum / 60 << '\n' << sum % 60;

    return 0;
}