#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

set<string> un;
vector<string> result;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		un.insert(str);
	}

	int count = 0;

	for (int i = 0; i < m; i++)
	{
		string str;
		cin >> str;

		if (un.find(str) != un.end())
		{
			count++;
			result.push_back(str);
		}
	}

	sort(result.begin(), result.end());

	cout << count << '\n';

	for (auto s : result)
	{
		cout << s << '\n';
	}

	return 0;
}