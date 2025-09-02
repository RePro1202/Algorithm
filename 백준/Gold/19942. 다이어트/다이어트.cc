#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int input[16][5];

// 0000 0101

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 입력 
    int n;
    cin >> n;

    int m[4];
    for(int i = 0 ; i < 4; i++)
    {
        cin >> m[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
            cin >> input[i][j];
    }
    // ---

    vector<int> resultNum;
    int minValue = 100000000;
    for (int i = 0; i < (1 << n); i++)
    {
        int sum[5] = {};

        vector<int> v;
        v.clear();

        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                for (int t = 0; t < 5; t++)
                {
                    sum[t] += input[j][t];
                }
                v.push_back(j);
            }
        }

        // 4가지중 기준에 충족 못하는 항목이 있으면 넘김.
        bool flag = true;
        for (int c = 0; c < 4; c++)
        {
            if (sum[c] < m[c])
            {
                flag = false;
                break;
            }
        }

        if (!flag)
        {
            continue;
        }
        // ----

        if (minValue > sum[4])
        {
            minValue = sum[4];
            resultNum.clear();
            resultNum = v;
        }
        else if (minValue == sum[4])
        {
            for (int t = 0; t < 4; t++)
            {
                if (v[t] == resultNum[t])
                {
                    continue;
                }
                else if (v[t] < resultNum[t])
                {
                    resultNum.clear();
                    resultNum = v;
                    break;
                }
            }
        }
    }

    // 결과 출력
    if (minValue == 100000000)
    {
        cout << -1;
        return 0;
    }

    cout << minValue << '\n';
    
    for (auto i : resultNum)
    {
        cout << i + 1 << ' ';
    }

    return 0;
}