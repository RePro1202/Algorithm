#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int board[51][51];
int open[51][51];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

queue<pair<int, int>> que;
int N, L, R;

int sums[2501];

const int CON = 0;

pair<int, int> BFS(int initSum)
{
    int sum = initSum;
    int count = 1;

    while (!que.empty())
    {
        pair<int, int> cur = que.front();
        que.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int ny = cur.first + dy[dir];
            int nx = cur.second + dx[dir];

            if (ny < 0 || nx < 0 || ny >= N || nx >= N)
                continue;
            if (abs(board[ny][nx] - board[cur.first][cur.second]) < L
                || abs(board[ny][nx] - board[cur.first][cur.second]) > R)
                continue;
            if (open[ny][nx] != CON)
                continue;

            open[ny][nx] = open[cur.first][cur.second];
            que.push({ ny, nx });
            sum += board[ny][nx];
            count++;
        }
    }

    pair<int, int> result = { sum / count, count };

    return result;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> L >> R;

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            cin >> board[y][x];
        }
    }


    int result = 0;
    int numbering = 1;
    
    while (true)
    {
        numbering = 1;
        int stopCount = 1;

        for (int i = 0; i < N; i++)
        {
            fill(open[i], open[i] + N + 1, CON);
        }

        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < N; x++)
            {
                if (que.empty())
                {
                    if (open[y][x] == 0)
                    {
                        que.push({ y, x });
                        open[y][x] = numbering;
                    }
                    else
                        continue;
                }

                pair<int, int> BFSresult = BFS(board[y][x]);
                sums[numbering] = BFSresult.first;
                numbering++;

                if (BFSresult.second == 1)
                {
                    stopCount++;
                }
            }
        }

        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < N; x++)
            {
                board[y][x] = sums[open[y][x]];
            }
        }

        if (stopCount >= N * N)
        {
            break;
        }
        else
        {
            result++;
        }
    }

    cout << result;


    return 0;
}