#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> Split(string& str, string del)
{
    vector<string> result;

    int delSize = del.size();

    int start = 0;
    int end = str.find(del);

    while (end != string::npos)
    {
        result.push_back(str.substr(start, end - start));
        start = end + delSize;
        end = str.find(del, start);
    }
    result.push_back(str.substr(start));

    return result;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string pattern;

    cin >> n;
    cin >> pattern;

    vector<string> splitPattern = Split(pattern, "*");

    for (int i = 0; i < n; i++)
    {
        string file;
        cin >> file;

        if (file.size() < splitPattern[0].size() + splitPattern[1].size())
        {
            cout << "NE\n";
            continue;
        }

        if (file.find(splitPattern[0]) == 0)
        {
            reverse(file.begin(), file.end());
            reverse(splitPattern[1].begin(), splitPattern[1].end());

            if (file.find(splitPattern[1]) == 0)
            {
                cout << "DA\n";
                reverse(splitPattern[1].begin(), splitPattern[1].end());
                continue;
            }

            reverse(splitPattern[1].begin(), splitPattern[1].end());
        }

        cout << "NE\n";
    }

    return 0;
}