#include <iostream>
#include <set>
#include <utility>

using namespace std;

multiset<pair<int, bool>> se;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		if (temp == 0)
		{
			if (se.empty())
			{
				cout << 0 << '\n';
				continue;
			}
			
			pair<int, bool> x = *se.begin();
			se.erase(se.begin());
			
			if (x.second == true)
			{
				cout << x.first;
			}
			else
			{
				cout << x.first * -1;
			}

			cout << '\n';
		}
		else if (temp < 0)
		{
			se.insert({ temp * -1, false });
		}
		else
		{
			se.insert({ temp, true });
		}
	}

	return 0;
}