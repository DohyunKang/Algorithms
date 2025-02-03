#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

static vector<int> A;
static int N, M;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	A.resize(N,0);

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	sort(A.begin(), A.end());

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		bool find = false;
		int target = 0;
		cin >> target;
		int start = 0;
		int end = A.size() - 1;

		while (start <= end)
		{
			int mid = (start + end) / 2;
			int mV = A[mid];

			if (target > mV)
			{
				start = mid + 1;
			}
			else if (target < mV)
			{
				end = mid - 1;
			}
			else if (target == mV)
			{
				find = true;
				break;
			}
		}

		if (find)
		{
			cout << 1 << "\n";
		}
		else
		{
			cout << 0 << "\n";
		}
	}

	return 0;
}