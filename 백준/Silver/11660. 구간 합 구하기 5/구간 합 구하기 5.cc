#include <iostream>

using namespace std;

int board[1025][1025];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    for (int y = 1; y <= N; y++)
    {
        for (int x = 1; x <= N; x++)
        {
            int temp;
            cin >> temp;

            if (x - 1 > 0)
            {
                board[y][x] += temp + board[y][x - 1];
            }
            else
            {
                board[y][x] = temp;
            }
        }
    }

    for (int i = 0; i < M; i++)
    {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
    
        int sum = 0;

        for (int y = y1; y <= y2; y++)
        {
            if (x1 == 1)
                sum += board[y][x2];
            else
                sum += board[y][x2] - board[y][x1 - 1];
        
        }

        cout << sum << '\n';
    }


    return 0;
}
