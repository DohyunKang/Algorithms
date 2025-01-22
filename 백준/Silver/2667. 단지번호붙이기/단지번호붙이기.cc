#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

//vector<vector<int>> map;
//vector<vector<int>> visited;

int map[25][25];
int visited[25][25];

int A;
int N;

void DFS(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= N || nx < 0 || ny >= N || ny < 0)
        {
            continue;
        }

        if (visited[nx][ny] == 0 && map[nx][ny] == 1)
        {
            visited[nx][ny] = 1;
            A+=1;
            DFS(nx, ny);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    //map.resize(N);
    //visited.resize(N);

    string str;

    for (int i = 0; i < N; i++)
    {
        cin >> str;
        for (int j = 0; j < str.length(); j++)
        {
            visited[i][j] = 0;

            if (str[j] == '1')
            {
                map[i][j] = 1;
            }
            else
            {
                map[i][j] = 0;
            }
        }
    }

    int count = 0;
    vector<int> A_count;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visited[i][j] == 0 && map[i][j] == 1)
            {
                visited[i][j] = 1;
                A = 1;
                DFS(i, j);
                count++;
                A_count.push_back(A);
            }
        }
    }

    cout << count << "\n";

    sort(A_count.begin(), A_count.end());

    for (int i = 0; i < A_count.size(); i++)
    {
        if (A_count[i] != 0)
        {
            cout << A_count[i] << "\n";
        }
    }

    return 0;
}