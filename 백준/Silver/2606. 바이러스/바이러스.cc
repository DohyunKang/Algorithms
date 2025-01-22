#include <iostream>
#include <vector>

using namespace std;

void DFS(int v);
vector<vector<int>> A;
vector<bool> visited;
static int virus_check = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    
    cin >> N;
    cin >> M;
    
    A.resize(N+1);
    visited.resize(N+1, false);
    
    int s,e;
    
    for(int i = 0; i < M; i++)
    {
        cin >> s >> e;
        A[s].push_back(e);
        A[e].push_back(s);
    }
    
    int count = 0;
    
    DFS(1);
    
    cout << virus_check-1 << "\n";
    
    return 0;
}

void DFS(int v)
{
    if(visited[v])
    {
        return;
    }
    
    visited[v] = true;
    
    for(int i : A[v])
    {
        if(!visited[i])
        {
            DFS(i);
        }
    }
    
    virus_check++;
}