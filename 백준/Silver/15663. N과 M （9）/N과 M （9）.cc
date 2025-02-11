#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

int n, m;
vector<int> v;
vector<bool> check;
set<long long> numSet;
vector<int> curNum;

void func(int num)
{
	if (num >= m)
	{
		// 숫자로 변경해서 set에 존재유무 확인후 처리, 출력
		long long inum = 0;
		for (auto a : curNum)
		{
			int t = (int)log10(a);
			if (t == 0) t = 1;

			inum = inum * (10 * t) + a;
		}
		if (numSet.find(inum) != numSet.end())
			return;


		numSet.insert(inum);
		for (auto a : curNum)
			cout << a << ' ';

		cout << '\n';

		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (check[i] == true)
			continue;

		curNum.push_back(v[i]);
		check[i] = true;

		func(num + 1);
		check[i] = false;
		curNum.pop_back();
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
		check.push_back(false);
	}

	sort(v.begin(), v.end());

	func(0);

	return 0;
}