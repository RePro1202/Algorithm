#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int timeLine[101];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    for (int i = 0; i < 3; i++)
    {
        int inTime, outTime;
        cin >> inTime >> outTime;

        for (int time = inTime; time < outTime; time++)
        {
            timeLine[time]++;
        }
    }


    int sum = 0;

    for (int time = 1; time <= 100; time++)
    {
        if (timeLine[time] == 0)
            continue;

        if (timeLine[time] == 1)
        {
            sum += a;
        }
        else if (timeLine[time] == 2)
        {
            sum += b * 2;
        }
        else if (timeLine[time] == 3)
        {
            sum += c * 3;
        }
    }
        
    cout << sum;

    return 0;
}