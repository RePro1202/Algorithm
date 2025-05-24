#include <iostream>
#include <algorithm>

using namespace std;

int arr[101];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, j;
	cin >> n >> m >> j;

	int st, en;
	st = 1;
	en = m;

	int count = 0;

	for (int i = 0; i < j; i++)
	{
		int pos;
		cin >> pos;

		if (pos >= st && pos < en)
		{
			continue;
		}
		else
		{
			if (pos < st) // 바구니 왼쪽으로 떨어짐
			{
				count += st - pos;
				st = pos;
				en = pos + m - 1;

				if (m == 1)
				{
					en == st;
				}
			}
			else if (pos > en) // 바구니 오른쪽으로 떨어짐
			{
				count += pos - en;

				st = pos - m + 1;
				en = pos;

				if (m == 1)
					st = en;
			}
		}
	}

	cout << count;
	
	return 0;
}