#include <iostream>
#include <vector>

using namespace std;

static vector<int> p;
static vector<int> plan;
void unionfnc(int a, int b);
int find(int a);
bool check(int a, int b);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	cin >> N;
	cin >> M;

	int a;

	p.resize(N + 1, 0);

	for (int i = 0; i <= N; i++)
	{
		p[i] = i;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> a;

			if (a == 1)
			{
				unionfnc(i, j);
			}
		}
	}

	plan.resize(M, 0);

	for (int i = 0; i < M; i++)
	{
		cin >> plan[i];
	}

	bool possible = true;

	for (int i = 0; i < M - 1; i++)
	{
		if (!check(plan[i], plan[i + 1]))
        {
            possible = false;
            break;
        }
	}

	if (possible)
	{
		cout << "YES" << "\n";

	}
	else
	{
		cout << "NO" << "\n";
	}

	return 0;
}

void unionfnc(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a != b)
	{
		p[b] = a;
	}
}

int find(int a)
{
	if (a == p[a])
	{
		return a;
	}
	else
	{
		return find(p[a]);
	}
}

bool check(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a == b)
	{
		return true;
	}

	return false;
}