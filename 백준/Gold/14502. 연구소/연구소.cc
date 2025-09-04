#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int board[9][9];

vector<pair<int, int>> startPos;
vector<pair<int, int>> emptyArea;
vector<pair<int, int>> wall;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    int n, m;
    cin >> n >> m;
    
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            cin >> board[y][x];

            if (board[y][x] == 2)
            {
                startPos.push_back({ y, x });
            }
            else if (board[y][x] == 1)
            {
                wall.push_back({ y, x });
            }
            else
            {
                emptyArea.push_back({ y, x });
            }
        }
    }

    vector<int> mask(emptyArea.size(), 0);
    std::fill(mask.begin(), mask.begin() + 3, 1);

    for (int i = 0; i < emptyArea.size(); i++)
    {
        if (mask[i])
        {
            board[emptyArea[i].first][emptyArea[i].second] = 1;
            wall.push_back({ emptyArea[i].first , emptyArea[i].second });
        }
    }

    int max = 0;

    while (true)
    {
        // 초기화
        for (auto p : emptyArea)
        {
            board[p.first][p.second] = 0;
        }


        // 벽 세우기
        bool flag = false;
        for (int i = 0; i < 3; i++)
        {
            wall.pop_back();
        }

        for (int i = 0; i < emptyArea.size(); i++)
        {
            if (mask[i])
            {
                board[emptyArea[i].first][emptyArea[i].second] = 1;
                wall.push_back({ emptyArea[i].first , emptyArea[i].second });
            }
        }
        if (!prev_permutation(mask.begin(), mask.end()))
        {
            flag = true;
        }
        // ---

        queue<pair<int, int>> que;

        for (auto s : startPos)
        {
            que.push({ s.first, s.second });
            board[s.first][s.second] = 2;
        }

        for (auto p : wall)
        {
            board[p.first][p.second] = 1;
        }

        // BFS
        while (!que.empty())
        {
            pair<int, int> curPos = que.front();
            que.pop();

            for (int dir = 0; dir < 4; dir++)
            {
                int ny = curPos.first + dy[dir];
                int nx = curPos.second + dx[dir];

                if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                    continue;
                if (board[ny][nx] == 1 || board[ny][nx] == 2)
                    continue;

                board[ny][nx] = 2;
                que.push({ ny, nx });
            }
        }

        // 결과
        int result = 0;

        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < m; x++)
            {
                if (board[y][x] == 0)
                    result++;
            }
        }

        if (result > max)
            max = result;

        if (flag)
            break;
    }

    cout << max;

    return 0;
}