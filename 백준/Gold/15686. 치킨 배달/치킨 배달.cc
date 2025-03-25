#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;

int board[51][51];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

const int MAX = 1000000000;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // 입력
    for (int y = 1; y <= n; y++)
    {
        for (int x = 1; x <= n; x++)
        {
            cin >> board[y][x];

            if (board[y][x] == 1)
                house.push_back({ y, x });
            else if (board[y][x] == 2)
                chicken.push_back({ y, x });
        }
    }

    // 조합
    vector<int> mask(chicken.size(), 0);
    fill(mask.begin(), mask.begin() + m, 1);

    int minSum = MAX;

    do
    {
        vector<int> tempHouse(house.size(), MAX);

        for (int i = 0; i < mask.size(); i++)
        {
            if (mask[i])
            {
                for (int j = 0; j < house.size(); j++)
                {
                    int dist = abs(house[j].first - chicken[i].first) + abs(house[j].second - chicken[i].second);
                    
                    if (dist < tempHouse[j])
                        tempHouse[j] = dist;
                }
            }
        }

        int sum = accumulate(tempHouse.begin(), tempHouse.end(), 0);

        if (sum < minSum)
            minSum = sum;

    } while (prev_permutation(mask.begin(), mask.end()));

    cout << minSum;

    return 0;
}