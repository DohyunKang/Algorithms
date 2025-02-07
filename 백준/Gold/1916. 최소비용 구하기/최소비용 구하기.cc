#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

typedef pair<int, int> edge;

static vector<vector<edge>> A;
static vector<int> md;
static vector<bool> visited;
static priority_queue<edge, vector<edge>, greater<edge>> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	cin >> N;
	cin >> M;

	A.resize(N + 1);
	md.resize(N + 1);
	visited.resize(N + 1);

	for (int i = 0; i <= N; i++)
	{
		md[i] = INT_MAX;
		visited[i] = false;
	}

	for (int i = 0; i < M; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		A[u].push_back(make_pair(v, w));
	}

	int S, E;

	cin >> S >> E;

	md[S] = 0;

	q.push(make_pair(0, S));

	while (!q.empty())
	{
		edge now = q.top();
		int now_v = now.second;
		q.pop();

		if (visited[now_v])
		{
			continue;
		}

		visited[now_v] = true;

		for (int i = 0; i < A[now_v].size(); i++)
		{
			edge temp = A[now_v][i];
			int next = temp.first;
			int value = temp.second;

			if (md[next] > md[now_v] + value)
			{
				md[next] = md[now_v] + value;
				q.push(make_pair(md[next], next));
			}
		}
	}

	cout << md[E] << "\n";

	return 0;
}