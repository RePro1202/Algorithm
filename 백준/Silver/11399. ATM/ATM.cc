#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> p;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		p.push_back(temp);
	}

	sort(p.begin(), p.end());

	int result = 0;
	
	for (int i = 1; i < n; i++)
	{
		p[i] += p[i - 1];
	}

	for (auto n : p)
	{
		result += n;
	}

	cout << result;

	return 0;
}