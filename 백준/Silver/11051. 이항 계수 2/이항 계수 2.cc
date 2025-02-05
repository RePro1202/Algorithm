#include <iostream>

using namespace std;

int check[1001][1001];

// nCk = n-1Ck + n-1Ck-1
// 1ck = 0 (k!=1)
// nc1 = n
// ncn = 1
// nc0 = 1

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= 1000; i++)
	{
		check[1][i] = 0;
		check[i][1] = i;
		check[i][i] = 1;
		check[i][0] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 2; j <= n; j++)
		{
			check[i][j] = (check[i - 1][j - 1] + check[i - 1][j]) % 10007;
		}
	}

	cout << check[n][k];

	return 0;
}