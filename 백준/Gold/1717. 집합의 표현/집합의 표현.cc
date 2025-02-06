#include <iostream>
#include <vector>

using namespace std;

static vector<int> A;
void unionfunc(int a, int b);
int find(int a);
bool check(int a, int b);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    
    cin >> N >> M;
    
    A.resize(N+1);
    
    for(int i = 0; i <= N; i++)
    {
        A[i] = i;
    }
    
    for(int i = 0; i < M; i++)
    {
        int q, a, b;
        
        cin >> q >> a >> b;
        
        if(q == 0)
        {
            unionfunc(a,b);
        }
        else
        {
            if(check(a,b))
            {
                cout << "YES" << "\n";
            }
            else
            {
                cout << "NO" << "\n";
            }
        }
    }
    
    return 0;
}

void unionfunc(int a, int b)
{
    a = find(a);
    b = find(b);
    
    if(a != b)
    {
        A[b] = a;
    }
}

int find(int a)
{
    if(a == A[a])
    {
        return a;
    }
    else
    {
        return find(A[a]);
    }
}

bool check(int a, int b)
{
    a = find(a);
    b = find(b);
    
    if(a == b)
    {
        return true;
    }
    
    return false;
}