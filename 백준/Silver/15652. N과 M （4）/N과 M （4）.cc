#include <iostream>
#include <vector>

using namespace std;

int n, m;
int check[9];
vector<int> v;

void func(int t)
{
	if (t == m)
	{
		for (auto a : v)
		{
			if(a != -1)
				cout << a << ' ';
		}

		cout << '\n';
		
		return;
	}

	int st = v.back();
	if (st == -1)
		st = 1;

	for (int i = st; i <= n; i++)
	{
		if (check[i] > t)
			continue;

		check[i]++;
		v.push_back(i);
		func(t + 1);

		check[i]--;
		v.pop_back();
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	v.push_back(-1);
	func(0);

	return 0;
}