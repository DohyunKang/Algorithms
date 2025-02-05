#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	
	cin >> N;

	priority_queue<int> plus;
	priority_queue<int, vector<int>, greater<int>> minus;
	int one = 0;
	int zero = 0;
	int num;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (num > 1)
		{
			plus.push(num);
		}
		else if (num == 1)
		{
			one++;
		}
		else if (num == 0)
		{
			zero++;
		}
		else
		{
			minus.push(num);
		}
	}

	int sum = 0;

	while (plus.size() > 1)
	{
		int first = plus.top();
		plus.pop();
		int second = plus.top();
		plus.pop();
		
		sum = sum + first * second;
	}

	if (!plus.empty())
	{
		sum = sum + plus.top();
		plus.pop();
	}

	while (minus.size() > 1)
	{
		int first = minus.top();
		minus.pop();
		int second = minus.top();
		minus.pop();

		sum = sum + first * second;
	}

	if (!minus.empty())
	{
		if (zero == 0)
		{
			sum = sum + minus.top();
			minus.pop();
		}
	}

	sum = sum + one;

	cout << sum << "\n";

	return 0;
}