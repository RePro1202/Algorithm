#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	priority_queue<int> qu;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		if (temp == 0)
		{
			if (qu.empty())
			{
				cout << '0' << '\n';
				continue;
			}

			cout << qu.top() * -1 << '\n';
			qu.pop();
		}
		else
		{
			qu.push(temp * -1);
		}
	}

	return 0;
}