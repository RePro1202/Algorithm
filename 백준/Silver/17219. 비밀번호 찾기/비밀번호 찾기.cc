#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, string> str;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string name, pass;

		cin >> name >> pass;

		str.insert({ name, pass });
	}

	for (int i = 0; i < m; i++)
	{
		string name;

		cin >> name;

		cout << str[name] << '\n';
	}


	return 0;
}