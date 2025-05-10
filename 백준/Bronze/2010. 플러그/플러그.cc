#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int sum;
    cin >> sum;
    for (int i = 1; i < n; i++)
    {
        int temp;
        cin >> temp;

        sum += temp - 1;
    }

    cout << sum;

    return 0;
}