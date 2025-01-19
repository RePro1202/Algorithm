#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> v;

int main(void)
{
	int k, n;

	cin >> k >> n;

	for (int i = 0; i < k; i++)
	{
		long long num;
		cin >> num;

		v.push_back(num);
	}

	sort(v.begin(), v.end());

    if (n == 1)
    {
	    cout << v.back();
	    return 0;
    }
	if (v.front() == v.back() && v.size() != 1)
	{
		cout << v.front();
		return 0;
	}


	long long begin = 0;
	long long end = v[k - 1];
	long long mid = (begin + end) / 2;

	int result = 0;

	while (mid != begin && mid != end)
	{
		int count = 0;

		for (auto num : v)
		{
			count += num / mid;

			if (count > n)
				break;
		}

		if (count < n)
		{
			end = mid;
		}
		else if (count >= n)
		{
			begin = mid;

			if (result < mid)
			{
				result = mid;
			}
		}

		mid = (begin + end) / 2;
	}

	cout << result;


	return 0;
}