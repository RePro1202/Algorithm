#include <iostream>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n / 4; i++)
	{
		cout << "long" << ' ';
	}
	cout << "int";

	return 0;
}