#include <iostream>

using namespace std;

bool board[101][101];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        for (int lx = x; lx < x + 10; lx++)
        {
            for (int ly = y; ly < y + 10; ly++)
            {
                board[lx][ly] = true;
            }
        }
    }

    int count = 0;
    for (int x = 0; x <= 100; x++)
    {
        for (int y = 0; y <= 100; y++)
        {
            if (board[x][y] == true)
                count++;
        }
    }

    cout << count;

    return 0;
}