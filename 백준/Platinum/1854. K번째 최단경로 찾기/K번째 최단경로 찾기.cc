#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> Node;

static int N, M, K;
static int A[1001][1001];
static priority_queue<int> dq[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M >> K;
    
    for(int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        A[a][b] = c;
    }
    
    priority_queue<Node, vector<Node>, greater<Node>> q;
    q.push(make_pair(0,1));
    dq[1].push(0);
    
    while(!q.empty())
    {
        Node n = q.top();
        q.pop();
        
        for(int adj = 1; adj <= N; adj++)
        {
            if(A[n.second][adj] != 0)
            {
                if(dq[adj].size() < K)
                {
                    dq[adj].push(n.first + A[n.second][adj]);
                    q.push(make_pair(n.first + A[n.second][adj],adj));
                }
                else if(dq[adj].top() > n.first + A[n.second][adj])
                {
                    dq[adj].pop();
                    dq[adj].push(n.first + A[n.second][adj]);
                    q.push(make_pair(n.first+A[n.second][adj],adj));
                }
            }
        }
    }
    
    for(int i = 1; i <= N; i++)
    {
        if(dq[i].size() == K)
        {
            cout << dq[i].top() << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }
}
