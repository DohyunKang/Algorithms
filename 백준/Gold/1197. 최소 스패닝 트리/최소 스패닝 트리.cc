#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct edge{
    int s,e,v;
    bool operator > (const edge& temp) const{
        return v > temp.v;
    }
}edge;

static vector<int> parent;
priority_queue<edge, vector<edge>, greater<edge>> q;

void munion(int a, int b);
int find(int a);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,M;
    
    cin >> N >> M;
    
    parent.resize(N+1);
    
    for(int i = 0; i <= N; i++)
    {
        parent[i] = i;
    }
    
    for(int i = 0; i < M; i++)
    {
        int s, e, v;
        cin >> s >> e >> v;
        q.push(edge{s,e,v});
    }
    
    int uEdge = 0;
    int result = 0;
    
    while(uEdge < N - 1)
    {
        edge now = q.top();
        q.pop();
        
        if(find(now.s) != find(now.e))
        {
            munion(now.s, now.e);
            result = result + now.v;
            uEdge++;
        }
    }
    
    cout << result;
    
    return 0;
}

void munion(int a, int b)
{
    a = find(a);
    b = find(b);
    
    if(a!=b)
    {
        parent[b] = a;
    }
}

int find(int a)
{
    if(a == parent[a])
    {
        return a;
    }
    else
    {
        return parent[a] = find(parent[a]);
    }
}