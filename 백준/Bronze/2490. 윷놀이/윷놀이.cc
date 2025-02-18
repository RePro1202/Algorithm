#include <iostream>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;

        for (int j = 0; j < 4; j++)
        {
            int temp;
            cin >> temp;

            sum += temp;
        }

        if (sum == 0)
            cout << 'D';
        else if (sum == 1)
            cout << 'C';
        else if (sum == 2)
            cout << 'B';
        else if (sum == 3)
            cout << 'A';
        else if (sum == 4)
            cout << 'E';

        cout << '\n';
    }


    return 0;
}