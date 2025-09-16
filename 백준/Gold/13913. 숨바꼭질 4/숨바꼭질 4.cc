#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>
#include <stack>

using namespace std;

#define time first
#define prePos second

const int MAX = 1000000000;

vector<pair<int, int>> v(100001);
queue<int> que;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    pair<int, int> temp = { MAX, 0 };
    fill(v.begin(), v.end(), temp);

    que.push(N);
    v[N].time = 0;
    v[N].prePos = -1;

    while (!que.empty())
    {
        int curPos = que.front();
        que.pop();

        for (int i = 0; i < 3; i++)
        {
            int np = 0;
            if (i == 0)
            {
                np = curPos + 1;
            }
            else if (i == 1)
            {
                np = curPos - 1;
            }
            else
            {
                np = curPos * 2;
            }


            if (np < 0 || np > 100000)
                continue;
            if (v[np].time <= v[curPos].time + 1)
                continue;

            v[np].prePos = curPos;
            v[np].time = v[curPos].time + 1;
            que.push(np);
        }
    }

    cout << v[K].time << '\n';

    stack<int> step;
    int pos = K;
    step.push(K);

    while (v[pos].prePos != -1)
    {
        step.push(v[pos].prePos);
        pos = v[pos].prePos;
    }

    while (!step.empty())
    {
        cout << step.top() << ' ';
        step.pop();
    }

    return 0;
}