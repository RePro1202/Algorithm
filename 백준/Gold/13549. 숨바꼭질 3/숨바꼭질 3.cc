#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 1000000000;

int board[150001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    fill(board, board + 150001, MAX);

    queue<int> qu;
    qu.push(n);
    board[n] = 0;

    while (!qu.empty())
    {
        int x = qu.front();
        qu.pop();

        if (x * 2 < k + 100)
        {
            if (board[x * 2] > board[x])
            {
                board[x * 2] = board[x];
                qu.push(x * 2);
            }
        }

        if (x + 1 < k + 100)
        {
            if (board[x + 1] > board[x] + 1)
            {
                board[x + 1] = board[x] + 1;
                qu.push(x + 1);
            }
        }
            
        if (x - 1 >= 0)
        {
            if (board[x - 1] > board[x] + 1)
            {
                board[x - 1] = board[x] + 1;
                qu.push(x - 1);
            }
        }
       
    }

    cout << board[k];

    return 0;
}
