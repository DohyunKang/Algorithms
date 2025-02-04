#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

static vector<vector<int>> A;
static vector<int> visited;
static vector<int> answer;

void BFS(int node);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,M,K,X;
    
    cin >> N >> M >> K >> X;
    
    A.resize(N+1);
    int s,e;
    
    for(int i = 0; i < M; i++)
    {
        cin >> s >> e;
        A[s].push_back(e);
    }
    
    visited.resize(N+1);
    
    for(int i = 0; i <= N; i++)
    {
        visited[i] = -1;
    }
    
    BFS(X);
    
    for(int i = 0; i <= N; i++)
    {
        if(visited[i] == K)
        {
            answer.push_back(i);
        }
    }
    
    if(answer.empty())
    {
        cout << -1 << "\n";
    }
    else
    {
        sort(answer.begin(),answer.end());
        
        for(int i = 0; i < answer.size(); i++)
        {
            cout << answer[i] << "\n";
        }
    }
    
    return 0;
}

void BFS(int node)
{
    queue<int> myqueue;
    myqueue.push(node);
    visited[node]++;
    
    while(!myqueue.empty())
    {
        int now_node = myqueue.front();
        myqueue.pop();
        
        for(int i : A[now_node])
        {
            if(visited[i] == -1)
            {
                visited[i] = visited[now_node] + 1;
                myqueue.push(i);
            }
        }
    }
}