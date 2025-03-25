#include <iostream>
#include <string>

using namespace std;

string board[51];
int result[5];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    cin >> r >> c;

    for (int y = 0; y < r; y++)
        cin >> board[y];


    for (int y = 0; y <= r - 2; y++){
        for (int x = 0; x <= c - 2; x++){
            int empty = 0, car = 0;

            for (int i = 0; i < 2; i++){
                for (int j = 0; j < 2; j++){

                    if (board[y + i][x + j] == 'X')
                        car++;
                    else if (board[y + i][x + j] == '.')
                        empty++;
                }
            }
           
            if (empty == 4)
                result[0]++;
            else if (empty + car == 4)
                result[car]++;
        }
    }
    
    for (auto a : result)
        cout << a << '\n';

    return 0;
}