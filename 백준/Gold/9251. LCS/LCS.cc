#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int board[1001][1001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str1, str2;
    cin >> str1 >> str2;

    for (int i = 0; i < str1.size(); i++)
    {
        for (int j = 0; j < str2.size(); j++)
        {
            if (str1[i] == str2[j])
                board[i + 1][j + 1] = board[i][j] + 1;
            else
                board[i + 1][j + 1] = max(board[i][j + 1], board[i + 1][j]);
        }
    }

    cout << board[str1.size()][str2.size()];
    /*
        A   C   A   Y   K   P
    
    C   0   1   1   1   1   1

    A   1   1   2   2   2   2

    P   1   1   2   2   2   

    C

    A

    K

    */

    return 0;
}
