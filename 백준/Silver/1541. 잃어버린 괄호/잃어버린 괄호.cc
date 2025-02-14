#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    queue<int> num;
    queue<char> ch;

    int curNum = 0;
    bool zeroFlag = false;

    // 문자 숫자 분리
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '-' || str[i] == '+' || i == str.size() - 1)
        {
            if (zeroFlag && curNum == 0 && i != str.size() - 1)
                num.push(0);
            else if (curNum > 0 && i == str.size() - 1)
                num.push(curNum * 10 + (str[i] - '0'));
            else if (curNum > 0)
                num.push(curNum);
            else if (str[i] != 0)
                num.push(str[i] - '0');

            if (i != str.size() - 1)
                ch.push(str[i]);

            zeroFlag = false;
            curNum = 0;
        }
        else if (str[i] == '0' && curNum == 0)
        {
            zeroFlag = true;
            curNum = 0;
            continue;
        }
        else
        {
            zeroFlag = false;
            curNum = (curNum * 10) + (str[i] - '0');
        }
    }


    // 마이너스 값을 가장 크게 만들게, 마이너스 뒤쪽 +는 다음 - 전까지 전부 더하기
    int sum = 0;

    vector<int> temp;
    temp.push_back(num.front());
    num.pop();

    while (!num.empty())
    {
        int curN = num.front();
        num.pop();

        char pm = ch.front();
        ch.pop();

        if (pm == '+' && sum != 0)
        {
            sum += curN;
        }
        else if (pm == '-' && sum != 0)
        {
            temp.push_back(sum * -1);
            sum = curN;
        }
        else if (pm == '+' && sum == 0)
        {
            temp.push_back(curN);
        }
        else if (pm == '-' && sum == 0)
        {
            sum += curN;
        }
    }

    temp.push_back(sum * -1);

    int result = 0;
    for (auto a : temp)
    {
        result += a;
    }

    cout << result;

    return 0;
}