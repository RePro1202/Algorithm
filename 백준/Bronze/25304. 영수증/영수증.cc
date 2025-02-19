#include <iostream>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, n;
    cin >> x >> n;

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        sum += a * b;
    }

    if (sum == x)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}