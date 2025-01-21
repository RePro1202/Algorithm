#include <iostream>
#include <string>

using namespace std;

bool nums[21];

int main(void)
{
    ios::sync_with_stdio(0);
	cin.tie(0);
    
	int m;
	
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		string str;
		int n;

		cin >> str;

		if (str == "all")
		{
			for (int i = 0; i < 21; i++)
				nums[i] = true;
		}
		else if (str == "empty")
		{
			for (int i = 0; i < 21; i++)
				nums[i] = false;
		}
		else
		{
			cin >> n;

			if (str == "add")
			{
				nums[n] = true;
			}
			else if (str == "remove")
			{
				nums[n] = false;
			}
			else if (str == "check")
			{
				cout << (int)nums[n] <<'\n';
			}
			else if (str == "toggle")
			{
				nums[n] = !nums[n];
			}
		}
	}

	return 0;
}