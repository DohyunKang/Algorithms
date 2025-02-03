#include <iostream>
#include <vector>

using namespace std;

static vector<vector <int>> A;
static vector<bool> visited;
static bool arrive;

void DFS(int now, int depth);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    
    cin >> N >> M;
    
    A.resize(N+1);
    visited.resize(N+1, false);
    
    for(int i = 0; i < M; i++)
    {
        int s,e;
        cin >> s >> e;
        
        A[s].push_back(e);
        A[e].push_back(s);
    }
    
    for(int i = 1; i <= N; i++)
    {
        DFS(i,1);
        if(arrive)
        {
            break;
        }
    }
    
    if(arrive)
    {
        cout << 1 << "\n";
    }
    else
    {
        cout << 0 << "\n";
    }
}

void DFS(int now, int depth)
{
    if(depth == 5 || arrive)
    {
        arrive = true;
        
        return;
    }
    
    visited[now] = true;
    
    for(int i : A[now])
    {
        if(visited[i] == false)
        {
            DFS(i, depth + 1);
        }
    }
    
    visited[now] = false;
}
