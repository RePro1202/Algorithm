#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

vector<pair<int, int>> vec;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int t, r;
        cin >> t >> r;

        vec.push_back({ t, r });
    }

    sort(vec.begin(), vec.end());

    int time = 0;
    for (int i = 0; i < n; i++)
    {
        if (time < vec[i].first)
        {
            time = vec[i].first;
            time += vec[i].second;
            continue;
        }
        else
        {
            time += vec[i].second;
        }
    }

    cout << time;
    
    return 0;
}