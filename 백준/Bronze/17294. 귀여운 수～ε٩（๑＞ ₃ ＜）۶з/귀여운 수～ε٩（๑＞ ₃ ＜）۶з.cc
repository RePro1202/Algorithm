#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    if (str.size() < 2)
    {
        cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
        return 0;
    }

    int curNum, preNum, gap;

    preNum = str[0] - '0';
    curNum = str[1] - '0';
    gap = preNum - curNum;

    for (int i = 2; i < str.size(); i++)
    {
        preNum = curNum;
        curNum = str[i] - '0';

        if (preNum - curNum != gap)
        {
            cout << "흥칫뿡!! <(￣ ﹌ ￣)>";
            return 0;
        }
    }

    cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";

    return 0;
}
