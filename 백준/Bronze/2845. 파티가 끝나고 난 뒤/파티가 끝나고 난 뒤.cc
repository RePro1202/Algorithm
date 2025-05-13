#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int L, P;
    cin >> L >> P;

    for (int i = 0; i < 5; i++)
    {
        int num;
        cin >> num;

        cout << num - (L * P) << ' ';
    }

    return 0;
}