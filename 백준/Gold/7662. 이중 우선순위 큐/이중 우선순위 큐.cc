#include <iostream>
#include <set>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, k;

	cin >> t;

	for (int test = 0; test < t; test++)
	{
		multiset<int> s;

		cin >> k;

		for (int i = 0; i < k; i++)
		{
			char oper;
			int num;

			cin >> oper;
			cin >> num;

			if (oper == 'I')
			{
				s.insert(num);
			}
			else if (oper == 'D')
			{
				if (s.empty())
					continue;

				if (num == 1)
				{
					s.erase(prev(s.end()));
				}
				else if (num == -1)
				{
					s.erase(s.begin());
				}
			}
		}

		if (s.empty())
		{
			cout << "EMPTY" << '\n';
			continue;
		}

		cout << *prev(s.end()) << ' ' << *s.begin() << '\n';

	}

	return 0;
}