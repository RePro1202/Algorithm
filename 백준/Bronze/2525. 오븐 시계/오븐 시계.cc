#include <iostream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;

	int h, m;
	m = (b + (c % 60)) % 60;
	h = (a + (c / 60) + ((b + (c % 60)) / 60)) % 24;

	cout << h << ' ' << m;

	return 0;
}