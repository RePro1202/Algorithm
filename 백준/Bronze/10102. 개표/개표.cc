#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int v;
    string str;
    
    cin >> v >> str;

    int A = 0, B = 0;
    for (auto c : str)
    {
        if (c == 'A')
            A++;
        else
            B++;
    }

    if (A > B)
        cout << 'A';
    else if (A == B)
        cout << "Tie";
    else
        cout << 'B';

    return 0;
}
