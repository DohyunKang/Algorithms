#include <iostream>
#include <vector>
#include <tuple>
#include <limits.h>

using namespace std;

typedef tuple<int,int,int> edge;

static int N,M,sc,ec;
static vector<long> md;
static vector<long> money;
static vector<edge> egs;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> sc >> ec >> M;
    
    md.resize(N);
    money.resize(N);
    fill(md.begin(),md.end(),LONG_MIN);
    
    for(int i = 0; i < M; i++)
    {
        int s, e, p;
        cin >> s >> e >> p;
        egs.push_back(make_tuple(s,e,p));
    }
    
    for(int i = 0; i < N; i++)
    {
        cin >> money[i];
    }
    
    md[sc] = money[sc];
    
    for(int i = 0; i <= N + 50; i++)
    {
        for(int j = 0; j < M; j++)
        {
            int s = get<0>(egs[j]);
            int e = get<1>(egs[j]);
            int p = get<2>(egs[j]);
            
            if(md[s] == LONG_MIN)
            {
                continue;
            }
            else if(md[s] == LONG_MAX)
            {
                md[e] = LONG_MAX;
            }
            else if(md[e] < md[s] + money[e] - p)
            {
                md[e] = md[s] + money[e] - p;
                
                if(i >= N - 1)
                {
                    md[e] = LONG_MAX;
                }
            }
        }
    }
    
    if(md[ec] == LONG_MIN)
    {
        cout << "gg" << "\n";
    }
    else if(md[ec] == LONG_MAX)
    {
        cout << "Gee" << "\n";
    }
    else
    {
        cout << md[ec] << "\n";
    }
    
    return 0;
}