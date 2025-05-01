#include <iostream>
#include <string>

using namespace std;

int alphabet[26];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
    
        alphabet[str[0] - 'a']++;
    }


    bool flag = false;
    for (int i = 0; i < 26; i++)
    {
        if (alphabet[i] >= 5)
        {
            cout << (char)('a' + i);
            flag = true;
        }
    }

    if (!flag)
    {
        cout << "PREDAJA";
    }

    return 0;
}