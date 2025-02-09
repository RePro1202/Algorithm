#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// I로 시작 I로 끝
	int n, m;
	cin >> n >> m;

	string str;
	cin >> str;

	vector<char> st;

	int result = 0;

	// 9 101010101		7 1010101	5 10101		3 101
	// 1 = 4(2			1 = 3(2		1 = 2(2		1 = 1(2
	// 2 = 3(3			2 = 2(3		2 = 1(3
	// 3 = 2(4			3 = 1(4

	// 15 101010101010101
	// 1 = 7(2
	// 2 = 6(

	if (m < 3)
	{
		cout << 0;
		return 0;
	}

	for (int i = 0; i < str.size(); i++)
	{
		if (st.empty())
		{
			if (str[i] == 'I')
				st.push_back('I');
		}
		else
		{
			if(st.back() == str[i] || i == str.size() - 1)
			{
				if (str[i] == 'I' && st.back() != 'I')
					st.push_back('I');
				else if (str[i] == 'O' && st.back() == 'O')
					st.pop_back();


				if (st.size() > n * 2)
				{
					result += (st.size() / 2) - (n - 1);
				}
					
				st.clear();

				if (str[i] == 'I')
				{
					st.push_back('I');
				}
				
			}
			else if (st.back() != str[i])
				st.push_back(str[i]);
		}
	}

	cout << result;
	
	return 0;
}