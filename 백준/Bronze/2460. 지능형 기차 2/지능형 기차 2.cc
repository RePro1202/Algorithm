#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int max = 0;
    int cur = 0;
    for (int i = 0; i < 10; i++)
    {
        int in, out;
        cin >> out >> in;

        cur -= out;
        if (cur > max)
        {
            max = cur;
        }

        cur += in;
        if (cur > max)
        {
            max = cur;
        }
    }

    cout << max;

    return 0;
}