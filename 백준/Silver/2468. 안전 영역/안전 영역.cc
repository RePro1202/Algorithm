#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
#include <vector>

using namespace std;

int board[105][105];
bool visit[105][105];
vector<pair<int, int>> v[105];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            cin >> board[y][x];
            v[board[y][x]].push_back({ y, x });
        }
    }

    int maxResult = 0;
    int result = 1;

    for (int num = 0; num < 100; num++)
    {
        int i = num + 1;

        if (v[i].empty())
            continue;

        for (int y = 0; y <= n; y++)
            for (int x = 0; x <= n; x++)
                visit[y][x] = false;

        queue<pair<int, int>> que;
        int vx = v[i][0].second;
        int vy = v[i][0].first;

        que.push(v[i][0]);
        visit[vy][vx] = true;

        int result = 1;

        while (!que.empty())
        {
            pair<int, int> cur = que.front();
            que.pop();

            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.second + dx[dir];
                int ny = cur.first + dy[dir];

                if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                    continue;
                if (visit[ny][nx])
                    continue;
                if (board[ny][nx] < i)
                    continue;

                que.push({ ny, nx });
                visit[ny][nx] = true;
            }

            if (que.empty())
            {
                for (int y = 0; y < n; y++)
                {
                    for (int x = 0; x < n; x++)
                    {
                        if (visit[y][x])
                            continue;
                        if (board[y][x] < i)
                            continue;

                        que.push({ y, x });
                        visit[y][x] = true;
                        result++;
                        break;
                    }

                    if (!que.empty())
                        break;
                }
            }
        }

        if (result > maxResult)
            maxResult = result;
    }

    std::cout << maxResult;

    return 0;
}