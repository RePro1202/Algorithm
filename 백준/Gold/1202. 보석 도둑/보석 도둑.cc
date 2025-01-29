#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> jewel; // 가격, 무게
multiset<int> bag;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		int weight, value;
		cin >> weight >> value;

		jewel.push_back({ value, weight });
	}

	for (int i = 0; i < k; i++)
	{
		int capa;
		cin >> capa;

		bag.insert(capa);
	}


	sort(jewel.begin(), jewel.end(), greater<>());

	long long result = 0;

	for (auto j : jewel)
	{
		auto a = bag.lower_bound(j.second);

		if (a == bag.end())
			continue;

		result += j.first;

		bag.erase(a);

		if (bag.empty())
			break;
	}
	

	cout << result;

	return 0;
}