#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        string str;
        int age, weight;

        cin >> str >> age >> weight;

        if (str == "#")
            break;

        if (age > 17 || weight >= 80)
        {
            cout << str << " " << "Senior\n";
        }
        else
        {
            cout << str << " " << "Junior\n";
        }
    }

    return 0;
}