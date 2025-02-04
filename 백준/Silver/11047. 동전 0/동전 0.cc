#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	long K;

	cin >> N >> K;

	vector<int> A(N, 0);

	int max = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	int count = 0;

	for (int i = N - 1; i >= 0; i--)
	{
		if (A[i] <= K)
		{
			max = A[i];
			int check = K / A[i];
			K = K % (check * A[i]);
			count += check;
		}
	}

	cout << count << "\n";

	return 0;
}