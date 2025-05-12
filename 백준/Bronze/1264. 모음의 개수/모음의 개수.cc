#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    while (true)
    {
        string str;
        getline(cin, str);

        if (str[0] == '#')
        {
            break;
        }

        int count = 0;
        for (auto c : str)
        {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
                || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            {
                count++;
            }
        }

        cout << count << '\n';
    }

    return 0;
}