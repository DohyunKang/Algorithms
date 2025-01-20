#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string A;

	cin >> A;

	vector<int> B(A.size(), 0);

	for (int i = 0; i < A.size(); i++)
	{
		B[i] = stoi(A.substr(i, 1));
	}

	int temp;

	for (int i = 0; i < A.size(); i++)
	{
		int Max = i;
		
		for (int j = i; j < A.size(); j++)
		{
			if (B[Max] < B[j])
			{
				Max = j;
			}
		}

		temp = B[i];
		B[i] = B[Max];
		B[Max] = temp;

		cout << B[i];
	}

	return 0;
}