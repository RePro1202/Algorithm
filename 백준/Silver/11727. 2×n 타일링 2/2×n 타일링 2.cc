#include <iostream>

using namespace std;

int check[1001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	check[1] = 1;
	check[2] = 3; 

	for (int i = 3; i <= n; i++)
	{
		if (i % 2 == 0)
		{
			check[i] = (check[i-1] * 2 + 1) % 10007;
		}
		else
		{
			check[i] = (check[i-1] * 2 - 1) % 10007;
		}
	}

	cout << check[n];

	return 0;
}