#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int m, n, k;

#define X second
#define Y first

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int board[101][101];
int check[101][101];

queue<pair<int, int>> qu;

int areaNum = 0;
int areaCount = 0;
vector<int> result;

void func(int lx, int ly, int rx, int ry)
{
    for (int y = ly; y < ry; y++)
    {
        for (int x = lx; x < rx; x++)
        {
            board[y][x] = 1;
        }
    }
}

bool findNX()
{
    if (!qu.empty())
        return true;

    if (areaCount != 0)
        result.push_back(areaCount);

    areaCount = 1;


    for (int y = 0; y < m; y++)
    {
        for (int x = 0; x < n; x++)
        {
            if (board[y][x] == 0 && check[y][x] == 0)
            {
                if (qu.empty())
                {
                    qu.push({ y, x });
                    areaNum++;
                    check[y][x] = areaNum;
                    return true;
                }
            }
        }
    }

    return false;
}

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> m >> n >> k;

    for (int i = 0; i < k; i++)
    {
        int ld_x, ld_y, rt_x, rt_y;
        cin >> ld_x >> ld_y >> rt_x >> rt_y;

        func(ld_x, ld_y, rt_x, rt_y);
    }

    while (findNX())
    {
        while (!qu.empty())
        {
            pair<int, int> cur = qu.front();
            qu.pop();

            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;
                if (board[ny][nx] != 0)
                    continue;
                if (check[ny][nx] != 0)
                    continue;

                areaCount++;
                check[ny][nx] = areaNum;
                qu.push({ ny, nx });
            }
        }
    }

    cout << areaNum << '\n';
    sort(result.begin(), result.end());
    for (auto a : result)
        cout << a << ' ';

    return 0;
}