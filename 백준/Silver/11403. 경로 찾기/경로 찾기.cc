#include <iostream>

using namespace std;

static long md[101][101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    
    cin >> N;
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> md[i][j];
        }
    }
    
    for(int k = 0; k < N; k++)
    {
        for(int i =0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(md[i][k] == 1 && md[k][j] == 1)
                {
                    md[i][j] = 1;
                }
            }
        }
    }
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << md[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}