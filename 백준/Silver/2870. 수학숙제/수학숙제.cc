#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

vector<string> result;

bool comp(const string& a,const string& b)
{
    if (a.size() == b.size())
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == b[i])
                continue;
            
            return (int)a[i] < (int)b[i] ? true : false;
        }
    }
    else
    {
        return a.size() < b.size() ? true : false;
    }

    return false;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string temp = "";
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        bool flag = false;

        for (int j = 0; j < str.size(); j++)
        {
            char c = str[j];

            if (c >= '1' && c <= '9')
            {
                temp += c;

                flag = true;
            }
            else if (c == '0')
            {
                if (flag) // 0앞에 숫자인 경우.
                {
                    temp += c;
                }
                else
                {
                   if(j == str.size() - 1) // 0 끝에 있는 경우
                   {
                       temp += c;
                   }
                   else if (j == 0 && str.size() == 1) // 가장 앞이 0이고, 사이즈가 1인경우.
                   {
                       temp += c;
                   }
                   else if (temp == "" && !(str[j + 1] >= '0' && str[j + 1] <= '9')) // 뒤가 문자인 경우
                   {
                       temp += c;
                   }
                }
            }
            else // 문자인 경우.
            {
                if (temp == "")
                    continue;

                result.push_back(temp);
                temp = "";
                flag = false;
            }
        }

        if (temp != "")
        {
            result.push_back(temp);
            temp = "";
        }
    }

    if (temp != "")
    {
        result.push_back(temp);
    }

    sort(result.begin(), result.end(), comp);

    for (auto s : result)
    {
        cout << s << '\n';
    }


    return 0;
}