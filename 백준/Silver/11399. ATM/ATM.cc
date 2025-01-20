#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	vector<int> A(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	int temp;
	int index = 0;

	for (int i = 1; i < N; i++)
	{
		bool check = false;

		for (int j = i - 1; j >= 0; j--)
		{
			if (A[i] < A[j])
			{
				index = j;
				check = true;
			}
		}

		if (check)
		{
			temp = A[i];

			for (int k = i - 1; k >= index; k--)
			{
				A[k + 1] = A[k];

				if (k == index)
				{
					A[k] = temp;
				}
			}
		}
	}

	vector<int> B(N, 0);
	int total = 0;

	for (int i = 0; i < N; i++)
	{
		if (i == 0)
		{
			B[i] = A[i];
		}
		else
		{
			B[i] = B[i - 1] + A[i];
		}

		total += B[i];
	}

	cout << total;

	return 0;
}