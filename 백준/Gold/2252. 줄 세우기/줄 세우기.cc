#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static vector<vector<int>> A;
static vector<int> indegree;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,M;
    
    cin >> N >> M;
    
    A.resize(N+1);
    indegree.resize(N+1);
    
    int s,e;
    
    for(int i = 0; i < M; i++)
    {
        cin >> s >> e;
        A[s].push_back(e);
        indegree[e]++;
    }
    
    queue <int> queue;
    
    for(int i = 1; i <= N; i++)
    {
        if(indegree[i] == 0)
        {
            queue.push(i);
        }
    }
    
    while(!queue.empty())
    {
        int now = queue.front();
        queue.pop();
        cout << now << " ";
        
        for(int i : A[now])
        {
            indegree[i]--;
            
            if(indegree[i] == 0)
            {
                queue.push(i);
            }
        }
    }
    
    return 0;
}