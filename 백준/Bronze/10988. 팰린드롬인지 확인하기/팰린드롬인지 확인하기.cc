#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string str;
    cin >> str;

    int st = 0;
    int en = str.size() - 1;

    if (str.size() == 1)
    {
        cout << 1;
        return 0;
    }
        
    while (st <= en)
    {
        if (str[st] != str[en])
        {
            cout << 0;
            return 0;
        }

        st++;
        en--;
    }

    cout << 1;

    return 0;
}
