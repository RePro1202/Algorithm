#include <iostream>

using namespace std;

long long fi[91];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	fi[0] = 0;
	fi[1] = 1;
	fi[2] = fi[1] + fi[2];

	for (int i = 3; i <= n; i++)
	{
		fi[i] = fi[i - 1] + fi[i - 2];
	}

	cout << fi[n];

	return 0;
}