#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

typedef pair<int,int> edge;

static vector<vector<edge>> A;
static vector<int> mdistance;
static vector<bool> visited;
static priority_queue<edge, vector<edge>, greater<edge>> q; 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int V,E,K;
    cin >> V >> E;
    cin >> K;
    
    A.resize(V+1);
    mdistance.resize(V+1);
    visited.resize(V+1);
    
    for(int i = 0; i <= V; i++)
    {
        mdistance[i] = INT_MAX;
        visited[i] = false;
    }
    
    for(int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        
        A[u].push_back(make_pair(v,w));
    }
    
    q.push(make_pair(0,K));
    mdistance[K] = 0;
    
    while(!q.empty())
    {
        edge now = q.top();
        q.pop();
        int now_v = now.second;
        
        if(visited[now_v])
        {
            continue;
        }
        
        visited[now_v] = true;
        
        for(int i = 0; i < A[now_v].size(); i++)
        {
            edge temp = A[now_v][i];
            int next = temp.first;
            int value = temp.second;
            
            if(mdistance[next] > mdistance[now_v] + value)
            {
                mdistance[next] = mdistance[now_v] + value;
                q.push(make_pair(mdistance[next], next));
            }
        }
    }
    
    for(int i = 1; i <= V; i++)
    {
        if(visited[i])
        {
            cout << mdistance[i] << "\n";
        }
        else
        {
            cout << "INF" << "\n";
        }
    }
    
    return 0;
}