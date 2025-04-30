#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 9; i++)
    {
        int temp;

        cin >> temp;

        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    do
    {
        int sum = 0;

        for (int i = 0; i < 7; i++)
        {
            sum += v[i];

            if (sum > 100)
                continue;
        }

        if (sum == 100)
        {
            for (int i = 0; i < 7; i++)
            {
                cout << v[i] << '\n';
            }

            break;
        }

    } while (next_permutation(v.begin(), v.end()));


    return 0;
}