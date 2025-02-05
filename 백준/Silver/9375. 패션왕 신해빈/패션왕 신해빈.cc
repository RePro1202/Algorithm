#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int test = 0; test < t; test++)
	{
		int n;
		cin >> n;

		if (n == 0)
		{
			cout << 0 << '\n';
			continue;
		}

		map<string, int> clo;

		for (int i = 0; i < n; i++)
		{
			string type, name;
			cin >> name >> type;

			if (clo.find(type) == clo.end())
				clo.insert({ type, 1 });
			else
			{
				clo[type]++;
			}
		}

		if(clo.size() == 1)
		{
			cout << n << '\n';
			continue;
		}

	
		int temp = 1;

		for (auto c : clo)
		{
			temp *= c.second + 1;
		}

		cout << temp - 1 << '\n';
	}

	return 0;
}