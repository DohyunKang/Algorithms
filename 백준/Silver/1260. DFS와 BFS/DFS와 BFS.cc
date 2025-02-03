#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

static vector<vector <int>> A;
static vector<bool> visited;
void DFS(int node);
void BFS(int node);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M, k;
    
    cin >> N >> M >> k;
    
    A.resize(N + 1);

    for(int i = 0; i < M; i++)
    {
        int s, e;
        cin >> s >> e;
        
        A[s].push_back(e);
        A[e].push_back(s);
    }
    
    for(int i = 1; i < N + 1; i++)
    {
        sort(A[i].begin(), A[i].end());
    }
    
    visited = vector<bool>(N+1, false);
    DFS(k);
    cout << "\n";
    visited = vector<bool>(N+1, false);
    BFS(k);
    cout << "\n";
    
    return 0;
}

void BFS(int node)
{
    queue<int> myqueue;
    myqueue.push(node);
    visited[node] = true;
    
    while(!myqueue.empty())
    {
        int now = myqueue.front();
        myqueue.pop();
        cout << now << " ";
        for(int i : A[now])
        {
            if(!visited[i])
            {
                visited[i] = true;
                myqueue.push(i);
            }
        }
    }
}

void DFS(int node)
{
    if(visited[node])
    {
        return;
    }
    
    cout << node << " ";
    visited[node] = true;
    
    for(int i : A[node])
    {
        if(!visited[i])
        {
            DFS(i);
        }
    }
}