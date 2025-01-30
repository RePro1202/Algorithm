#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> tree;
int sumLenth[1000001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		tree.push_back(temp);
	}

	sort(tree.begin(), tree.end(), greater<>());

	if (m == 1)
	{
		cout << tree[0] - 1;
		return 0;
	}

	if (n == 1)
	{
		cout << tree[0] - m;
		return 0;
	}


	int sum = 0;

	for (int i = 1; i < n; i++)
	{
		int gap = tree[i - 1] - tree[i];

		sum += gap * i;

		if (sum == m)
		{
			cout << tree[i];
			return 0;
		}
		else if (sum > m)
		{
			cout << tree[i] + (sum - m) / i;
			return 0;
		}
		else 
		{
			if (i == n - 1)
			{
				int result = tree[i] - ((m - sum) / n) - (m - sum) % n;

				cout << result;

				return 0;
			}
		}
	}



	return 0;
}