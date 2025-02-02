#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
bool check[10];
int arr[10];

int n, m;

void func(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (check[i])
			continue;

		check[i] = true;
		arr[k] = v[i];
		func(k + 1);
		check[i] = false;
	}

}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	func(0);

	return 0;
}