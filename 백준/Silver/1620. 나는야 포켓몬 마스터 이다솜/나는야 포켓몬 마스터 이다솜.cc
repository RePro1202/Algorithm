#include <iostream>
#include <string>
#include <map>
#include <utility>

using namespace std;

map<string, int> poket;
string names[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		string input;
		cin >> input;

		poket.insert({ input, i });
		names[i] = input;
	}

	for (int i = 0; i < m; i++)
	{
		string str;
		cin >> str;
		
		if (str[0] >= 'A' && str[0] <= 'z')
		{
			cout << poket[str] << '\n';
		}
		else
		{
			cout << names[stoi(str)] << '\n';
		}
	}

	return 0;
}