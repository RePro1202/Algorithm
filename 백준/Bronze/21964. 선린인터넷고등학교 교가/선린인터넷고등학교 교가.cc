#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string str;

    cin >> n >> str;

    for (int i = 5; i > 0; i--)
    {
        cout << str[n - i];
    }

    return 0;
}