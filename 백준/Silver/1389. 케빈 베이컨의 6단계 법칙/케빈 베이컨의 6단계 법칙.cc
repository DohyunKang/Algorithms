#include <iostream>
#include <limits.h>

using namespace std;

static long md[101][101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
            {
                md[i][j] = 0;
            }
            else
            {
                md[i][j] = 10000001;
            }
        }
    }

    for (int i = 0; i < M; i++)
    {
        int s, e;

        cin >> s >> e;

        md[s][e] = 1;
        md[e][s] = 1;
    }

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (md[i][j] > md[i][k] + md[k][j])
                {
                    md[i][j] = md[i][k] + md[k][j];
                }
            }
        }
    }

    int Min = INT_MAX;
    int answer = -1;

    for (int i = 1; i <= N; i++)
    {
        int temp = 0;

        for (int j = 1; j <= N; j++)
        {
            temp = temp + md[i][j];
        }

        if (Min > temp)
        {
            Min = temp;
            answer = i;
        }
    }

    cout << answer;

    return 0;
}