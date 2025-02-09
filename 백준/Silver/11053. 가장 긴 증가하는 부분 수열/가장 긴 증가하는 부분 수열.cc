#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int a[1001];
int d[1001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	a[0] = 0;
	d[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= i - 1; j++)
		{
			if (a[i] > a[j]) 
				d[i] = max(d[i], d[j] + 1);
		}
	}

	cout << *max_element(d, d + n + 1);

	return 0;
}