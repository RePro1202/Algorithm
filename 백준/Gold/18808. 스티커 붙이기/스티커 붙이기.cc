#include <iostream>
#include <vector>
#include <utility>

using namespace std;

#define X second
#define Y first

int n, m, k; // 노트북 세로, 가로, 스티커수
int board[41][41];

class Sticker
{
public:
    Sticker(int r, int c, vector<pair<int, int>>& v)
    {
        row = r;
        col = c;
        ch = v;
    }

private:
    int row;
    int col;
    vector<pair<int, int>> ch;
    int rot = 0;

public:
    void check()
    {
        while (rot < 4)
        {
            // 붙이기
            for (int sy = 0; sy <= n - row; sy++)
            {
                for (int sx = 0; sx <= m - col; sx++)
                {
                    if (checkPos(sy, sx))
                        return;
                }
            }

            rotate();
        }
    }

private:

    void rotate()
    {
        int temp = row;
        row = col;
        col = temp;

        // 위행 => 끝열, 아래행 => 처음열
        for (auto& p : ch)
        {
            int tempX = p.second;
            int tempY = p.first;

            p.X = col - tempY - 1;
            p.Y = tempX;
        }

        rot++;
    }

    bool checkPos(int sy, int sx)
    {
        for (auto p : ch)
        {
            if (board[p.Y + sy][p.X + sx] != 0)
                return false;
        }

        for (auto p : ch)
        {
            board[p.Y + sy][p.X + sx] = 1;
        }

        return true;
    }
};


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int t = 0; t < k; t++)
    {
        int r, c; // 행, 열
        cin >> r >> c;

        vector<pair<int, int>> stick;
        int pos[11][11];

        for (int y = 0; y < r; y++)
        {
            for (int x = 0; x < c; x++)
            {
                int temp;
                cin >> temp;

                pos[y][x] = temp;

                if (temp == 1)
                    stick.push_back({ y, x });
            }
        }

        Sticker stk(r, c, stick);

        stk.check();
    }

    int count = 0;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            if (board[y][x] == 1)
                count++;
        }
    }

    cout << count;

    return 0;
}
