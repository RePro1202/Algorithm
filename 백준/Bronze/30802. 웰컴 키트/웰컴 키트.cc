#include <iostream>

using namespace std;

int main(void)
{
	int n;
	int shirt[6];
	int t, p;

	cin >> n;
	for (int i = 0; i < 6; i++)
		cin >> shirt[i];
	cin >> t >> p;


	int shirtBundle = 0;
	int penBundle, penEach = 0;

	for (int i = 0; i < 6; i++)
	{
		shirtBundle += shirt[i] / t;

		if (shirt[i] % t != 0)
			shirtBundle++;
	}

	penBundle = n / p;
	penEach = n % p;

	cout << shirtBundle << '\n'
		<< penBundle << ' ' << penEach;

	return 0;
}