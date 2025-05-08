#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int temp[100001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> result;
    result.push_back(0);

    for (int i = 1; i <= n; i++)
    {
        cin >> temp[i];

        if (i <= k)
        {
            result[0] += temp[i];
        }
        else
        {
            int sum = result.back() + temp[i] - temp[i - k];

            result.push_back(sum);
        }
    }

    cout << *max_element(result.begin(), result.end());

    return 0;
}