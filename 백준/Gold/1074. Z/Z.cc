#include <iostream>
#include <math.h>

using namespace std;

void func(int n, int r, int c, long long sum)
{
	if (r == 0) r = n;
	if (c == 0) c = n;

	if (n <= 1)
	{
		if (r == 1 && c == 1)
			cout << sum;
		else if (r == 1 && c == 2)
			cout << sum + 1;
		else if (r == 2 && c == 1)
			cout << sum + 2;
		else
			cout << sum + 3;

		return;
	}

	long long num = pow(2, n);

	if (r <= num / 2 && c <= num / 2)
		func(n - 1, r, c, sum);
	else if (r <= num / 2 && c > num / 2)
		func(n - 1, r, c - num / 2, sum + num *(num / 4));
	else if (r > num / 2 && c <= num / 2)
		func(n - 1, r - num / 2, c, sum + num * (num / 2));
	else if (r > num / 2 && c > num / 2)
		func(n - 1, r - num / 2, c - num / 2, sum + num * ((num / 4) * 3));
}

int main(void)
{
	int n, r, c;

	cin >> n >> r >> c;

	func(n, r + 1, c + 1, 0);

	return 0;
}