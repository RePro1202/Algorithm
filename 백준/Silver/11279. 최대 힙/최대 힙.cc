#include <iostream>
#include <set>

using namespace std;

multiset<int> s;

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
			if (s.empty())
				cout << 0;
			else
			{
				cout << *prev(s.end());
				s.erase(prev(s.end()));
			}
			
			cout << '\n';
		}
		else
		{
			s.insert(temp);
		}
	}
	
	return 0;
}