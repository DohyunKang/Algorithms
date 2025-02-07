#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static vector<vector<int>> A;
static vector<int> build_time;
static vector<int> indegree;
static vector<int> answer;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	A.resize(N + 1);
	build_time.resize(N + 1);
	indegree.resize(N + 1);
	answer.resize(N + 1);

	for (int i = 1; i <= N; i++)
	{
		cin >> build_time[i];

		while (true)
		{
			int a;

			cin >> a;

			if (a == -1)
			{
				break;
			}

			A[a].push_back(i);
			indegree[i]++;
		}
	}

	queue <int> queue;

	for (int i = 1; i <= N; i++)
	{
		if (indegree[i] == 0)
		{
			queue.push(i);
		}
	}

	while (!queue.empty())
	{
		int now = queue.front();
		queue.pop();

		for (int i : A[now])
		{
			indegree[i]--;
			
			answer[i] = max(answer[i],answer[now] + build_time[now]);

			if (indegree[i] == 0)
			{
				queue.push(i);
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		cout << answer[i] + build_time[i] << "\n";
	}

	return 0;
}