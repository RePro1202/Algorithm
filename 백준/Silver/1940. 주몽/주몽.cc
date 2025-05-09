#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int arr[100001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        if (m - temp <= 100000)
        {
            if (arr[abs(m - temp)] > 0 && m - temp > 0)
            {
                arr[abs(m - temp)]--;
                sum++;
            }
            else
            {
                arr[temp]++;
            }
        }
    }
    cout << sum;

    return 0;
}