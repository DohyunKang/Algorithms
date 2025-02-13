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
    
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(i==j)
            {
                md[i][j] = 0;
            }
            else
            {
                md[i][j] = INT_MAX;
            }
        }
    }
    
    for(int i = 0; i < M; i++)
    {
        int s, e, v;
        
        cin >> s >> e >> v;
        
        if(md[s][e] > v)
        {
            md[s][e] = v;
        }
    }
    
    for(int k = 1; k <= N; k++)
    {
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                if(md[i][j] > md[i][k] + md[k][j])
                {
                    md[i][j] = md[i][k] + md[k][j];
                }
            }
        }
    }
    
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(md[i][j] == INT_MAX)
            {
                cout << "0 ";
            }
            else
            {
                cout << md[i][j] << " ";
            }
        }
        cout << "\n";
    }
    
    return 0;
}