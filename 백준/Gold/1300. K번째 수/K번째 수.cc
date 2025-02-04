#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, K;

    cin >> N;
    cin >> K;

    vector<int> A(N + 1, 0);

    int start = 1;
    int end = K;
    int middle = 0;

    while (start <= end)
    {
        middle = (start + end) / 2;
        int count = 0;

        for (int i = 1; i < N + 1; i++)
        {
            A[i] = min(middle / i, N);
            count = count + A[i];
        }

        if (count < K)
        {
            start = middle + 1;
        }
        else
        {
            end = middle - 1;
        }
    }

    cout << start << "\n";

    return 0;
}