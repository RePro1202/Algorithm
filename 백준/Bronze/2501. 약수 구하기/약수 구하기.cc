#include <iostream>
#include <vector>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> v;

    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            v.push_back(i);

        if (v.size() == k)
        {
            cout << v.back();
            return 0;
        }
    }

    cout << 0;

    return 0;
}