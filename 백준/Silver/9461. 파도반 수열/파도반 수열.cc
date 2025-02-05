#include <iostream>

using namespace std;

long long arr[101];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	arr[5] = 2;

	for (int i = 6; i <= 100; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 5];
	}

	int t;
	cin >> t;

	for (int test = 0; test < t; test++)
	{
		int n;
		cin >> n;

		cout << arr[n] << '\n';
	}

	return 0;
}