#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, K;
    cin >> N;
    cin >> K;
    
    int start = 1;
    int end = K;
    
    while(start <= end)
    {
        int middle = (start+end)/2;
        int count = 0;
            
        for(int i = 1; i < N+1; i++)
        {
            count = count + min(middle/i, N);
        }
        
        if(count < K)
        {
            start = middle +1;
        }
        else
        {
            end = middle - 1;
        }
    }
    
    cout << start << "\n";
    
    return 0;
}