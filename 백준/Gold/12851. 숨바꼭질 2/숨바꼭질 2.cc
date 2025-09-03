#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int visitTime[100001];
const int MAX_INT = 1000000000;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    if (n == k)
    {
        cout << 0 << '\n' << 1;
        return 0;
    }

    fill(visitTime, visitTime + sizeof(visitTime) / sizeof(int), MAX_INT);

    queue<int> que;
    que.push(n);
    visitTime[n] = 0;

    int minTime = MAX_INT;
    int count = 0;

    while (!que.empty())
    {
        int cur = que.front();
        que.pop();

        if (minTime < visitTime[cur])
        {
            continue;
        }

        int newPos[3] = { cur * 2, cur - 1 , cur + 1, };

        for (int i = 0; i < 3; i++)
        {
            if (newPos[i] < 0 || newPos[i] > 100000)
            {
                continue; // 범위 체크.
            }
            if (visitTime[newPos[i]] < visitTime[cur] + 1)
            {
                continue; // 더 빠른 경우가 이미 존재.
            }
            if (newPos[i] == k) 
            {
                if (visitTime[newPos[i]] == visitTime[cur] + 1) // 같은 속도의 경로가 이미 존재하는 경우.
                {
                    count++;
                    continue;
                }
                else
                {
                    minTime = visitTime[cur] + 1;
                    visitTime[newPos[i]] = visitTime[cur] + 1;
                    count = 1;
                    continue;
                }
            }

            visitTime[newPos[i]] = visitTime[cur] + 1;
            que.push(newPos[i]);
        }
    }

    cout << minTime << '\n' << count;

    return 0;
}