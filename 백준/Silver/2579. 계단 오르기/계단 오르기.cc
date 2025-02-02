#include <iostream>

using namespace std;

int stair[301];
int check[301][3];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> stair[i];
	}

	check[1][1] = stair[1];
	check[1][2] = stair[1];

	check[2][1] = stair[2];
	check[2][2] = check[1][1] + stair[2];

	check[3][1] = check[1][2] + stair[3];
	check[3][2] = check[2][1] + stair[3];

	for (int i = 4; i <= n; i++)
	{
		if(check[i - 2][2] > check[i - 2][1])
			check[i][1] = check[i - 2][2] + stair[i];
		else
			check[i][1] = check[i - 2][1] + stair[i];

		check[i][2] = check[i - 1][1] + stair[i];
	}

	if (check[n][1] > check[n][2])
		cout << check[n][1];
	else
		cout << check[n][2];

	return 0;
}