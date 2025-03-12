#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string re;
    int num;

    cin >> re >> num;
    
    int count = 0;
    for (int i = 0; i < num; i++)
    {
        string str;

        cin >> str;

        for (int j = 0; j < 5; j++)
        {
            if (str[j] != re[j])
                break;

            if (j == 4)
                count++;
        }
    }

    cout << count;

    return 0;
}
