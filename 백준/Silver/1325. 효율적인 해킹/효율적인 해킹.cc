#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static vector<vector<int>> A;
static vector<bool> visited;
static vector<pair<int,int>> answer;
static int c = 0;
void DFS(int node);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	cin >> N >> M;

	A.resize(N + 1);
	visited.resize(N + 1, false);

	int s, e;

	for (int i = 0; i < M; i++)
	{
		cin >> s >> e;
		A[e].push_back(s);
	}

	int max = 0;

	for (int i = 1; i <= N; i++)
	{
		visited.assign(N + 1, false);

		DFS(i);

		if (c > max)
		{
			answer.clear();
			max = c;
			answer.push_back(make_pair(c, i));
		}
		else if (c == max)
		{
			answer.push_back(make_pair(c, i));
		}
		else
		{
			answer.push_back(make_pair(c, 0));
		}

		c = 0;
	}

	sort(answer.begin(), answer.end());

	for (int i = 0; i < answer.size(); i++)
	{
		if (answer[i].second != 0)
		{
			cout << answer[i].second << " ";
		}
	}

	return 0;
}

void DFS(int node)
{
	if (visited[node])
	{
		return;
	}

	visited[node] = true;

	c++;

	for (int i : A[node])
	{
		if (visited[i] == false)
		{
			DFS(i);
		}
	}
}