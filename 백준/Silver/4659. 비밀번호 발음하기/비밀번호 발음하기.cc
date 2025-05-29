#include <iostream>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        string str;
        cin >> str;

        if (str == "end")
        {
            break;
        }

        bool result = true;
        bool hasVowel = 0;
        bool prevIsVowel = false;
        int streamCount = 0;
        char lastChar = ' ';

        for (auto c : str)
        {
            bool curIsVowel = false;

            // 모음 자음 체크
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                curIsVowel = true;
            else
                curIsVowel = false;

            // 연속 글자인지 체크
            if (lastChar == c)
            {
                if (!(c == 'e' || c == 'o'))
                {
                    result = false;
                    break;
                }
            }

            // 연속된 횟수 체크
            if (curIsVowel && prevIsVowel)
                streamCount++;
            else if (!curIsVowel && !prevIsVowel)
                streamCount++;
            else
                streamCount = 1;

            // 3연속인지 체크
            if (streamCount >= 3)
            {
                result = false;
                break;
            }

            if (curIsVowel)
                hasVowel = true;

            prevIsVowel = curIsVowel;
            lastChar = c;
        }

        if (hasVowel == 0)
            result = false;

        cout << "<" << str << ">";
        if (result)
            cout << " is acceptable.\n";
        else
            cout << " is not acceptable.\n";
    }

    return 0;
}