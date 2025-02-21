#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n, m;
int arr[10];
vector<int> v;
set<int> s;

vector<int> result;

void func(int num)
{
    if (num == m)
    {
        for (auto a : result)
        {
            if (a == 0)
                break;
            cout << a << ' ';
        }

        cout << '\n';
        return;
    }


    for (int i = 0; i < v.size(); i++)
    {
        if (num > 0)
        {
            if (v[i] >= result[num - 1])
            {
                result[num] = v[i];
                func(num + 1);
            }
            else
            {
                continue;
            }
        }
        else
        {
            result[num] = v[i];
            func(num + 1);
        }
    }
    
}

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        s.insert(temp);
    }

    for (int i = 0; i < m; i++)
    {
        result.push_back(0);
    }

    for (auto a : s)
        v.push_back(a);

    sort(v.begin(), v.end());

    func(0);
       
    return 0;
}