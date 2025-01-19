#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string str;
	int num;

	for (int i = 0; i < 3; i++)
	{
		cin >> str;

		if (str == "FizzBuzz" || str == "Fizz" || str == "Buzz")
		{

		}
		else
		{
			num = stoi(str) + (3 - i);

			int mod3, mod5;
			mod3 = num % 3;
			mod5 = num % 5;

			if (mod3 != 0 && mod5 != 0)
			{
				cout << num;
			}
			else if (mod3 != 0 && mod5 == 0)
			{
				cout << "Buzz";
			}
			else if (mod3 == 0 && mod5 != 0)
			{
				cout << "Fizz";
			}
			else if (mod3 == 0 && mod5 == 0)
			{
				cout << "FizzBuzz";
			}

			break;
		}
	}

	return 0;
}