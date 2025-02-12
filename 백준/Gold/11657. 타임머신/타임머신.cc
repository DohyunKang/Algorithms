#include <iostream>
#include <vector>
#include <limits.h>
#include <tuple>

using namespace std;

typedef tuple<int,int,int> edge;

static int N, M;
static vector<long> md;
static vector<edge> egs;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    md.resize(N+1);
    fill(md.begin(),md.end(),LONG_MAX);
    
    for(int i = 0; i < M; i++)
    {
        int start, end, time;
        cin >> start >> end >> time;
        egs.push_back(make_tuple(start,end,time));
    }
    
    md[1] = 0;
    
    for(int i = 1; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            edge medge = egs[j];
            int start = get<0>(medge);
            int end = get<1>(medge);
            int time = get<2>(medge);
            
            if(md[start]!= LONG_MAX && md[end] > md[start]+time)
            {
                md[end] = md[start] + time;
            }
        }
    }
    
    bool mc = false;
    
    for(int i = 0; i < M; i++)
    {
        edge medge = egs[i];
        int start = get<0>(medge);
        int end = get<1>(medge);
        int time = get<2>(medge);
        
        if(md[start] != LONG_MAX && md[end] > md[start] + time)
        {
            mc = true;
        }
    }
    
    if(!mc)
    {
        for(int i = 2; i <= N; i++)
        {
            if(md[i] == LONG_MAX)
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << md[i] << "\n";
            }
        }
        
    }
    else
    {
        cout << -1 << "\n";
    }
    
    return 0;
}