#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int board[51][51];
int visit[51][51];
queue<pair<int, int>> lands;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

const int MAX_INT = 100000000;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int X, Y;
    cin >> Y >> X;

    for (int y = 0; y < Y; y++)
    {
        string str;
        cin >> str;

        for (int x = 0; x < X; x++)
        {
            if (str[x] == 'W')
            {
                board[y][x] = 0;
            }
            else
            {
                board[y][x] = 1;
                lands.push({ y, x });
            }
        }
    }


    int result = 0;
    while (!lands.empty())
    {
        queue<pair<int, int>> que;

        pair<int, int> curStart = lands.front();
        lands.pop();

        for (int y = 0; y < Y; y++)
        {
            fill(visit[y], visit[y] + X, MAX_INT);
        }

        que.push(curStart);
        visit[curStart.first][curStart.second] = 0;

        while (!que.empty())
        {
            pair<int, int> cur = que.front();
            que.pop();

            for (int dir = 0; dir < 4; dir++)
            {
                int ny = cur.first + dy[dir];
                int nx = cur.second + dx[dir];

                if (ny < 0 || nx < 0 || ny >= Y || nx >= X)
                    continue;
                if (board[ny][nx] == 0)
                    continue;
                if (visit[ny][nx] <= visit[cur.first][cur.second] + 1)
                    continue;

                visit[ny][nx] = visit[cur.first][cur.second] + 1;
                que.push({ ny, nx });
            }
        }

        int max = 0;
        for (int y = 0; y < Y; y++)
        {
            for (int x = 0; x < X; x++)
            {
                if (visit[y][x] > max && visit[y][x] != MAX_INT)
                    max = visit[y][x];
            }
        }

        if (max > result)
            result = max;
    }

    cout << result;

    return 0;
}