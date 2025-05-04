#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    getline(cin, str);

    for (auto s : str)
    {
        if (s < 'A' || s > 'z' || (s > 'Z' && s < 'a'))
        {
            cout << s;
            continue;
        }


        int n = s + 13;

        // 대문자
        if (s < 'a')
        {
            if (n > 'Z')
            {
                n += - 'Z' + 'A' - 1;
            }
        }
        else // 소문자
        {
            if (n > 'z')
            {
                n += - 'z' + 'a' - 1;
            }
        }

        cout << (char)n;
    }

    return 0;
}