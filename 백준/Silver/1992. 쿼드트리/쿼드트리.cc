#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char board[65][65];

string func(int y, int x, int n)
{
    if (n <= 1)
    {
        string s = "";
        s += board[y][x];
        return s;
    }

    string temp;

    temp += func(y, x, n / 2);
    temp += func(y, x + n / 2, n / 2);
    temp += func(y + n / 2, x, n / 2);
    temp += func(y + n / 2, x + n / 2, n / 2);

    int sum = 0;
    for (auto t : temp)
        sum += t - '0';

    if (sum == 4 && temp.size() <= 4)
    {
        return "1";
    }
    if (sum == 0 && temp.size() <= 4)
    {
        return "0";
    }
    else
    {
        string s = "(";
        s += temp;
        s += ")";

        return s;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int y = 0; y < n; y++)
    {
        string str;
        cin >> str;

        for (int x = 0; x < n; x++)
        {
            board[y][x] = str[x];
        }
    }

    cout << func(0, 0, n) << '\n';

    return 0;
}