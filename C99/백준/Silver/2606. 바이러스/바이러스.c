#define MAX_N (100+1)
int AM[MAX_N][MAX_N] = { 0 };
int AL[MAX_N][MAX_N] = { 0 };
int visited[MAX_N] = { 0 };
int virus_host = 1;
int n, m;
int s, e;
int check = 0;

void DFS_M(int v)
{
	if (visited[v])
	{
		return;
	}

	visited[v] = 1;

	for (int i = 1; i <= n; i++)
	{
		if (AM[v][i]&&!visited[i])
		{
			DFS_M(i);
		}
	}

	check++;
}

void DFS_L(int v)
{
	if (visited[v])
	{
		return;
	}

	visited[v] = 1;

	for (int i = 1; i <= AL[v][0]; i++)
	{
		if (!visited[AL[v][i]])
		{
			DFS_L(AL[v][i]);
		}
	}

	check++;
}

void inputDataM()
{
	(void)scanf("%d", &n);
	(void)scanf("%d", &m);

	for (int i = 1; i <= m; i++)
	{
		(void)scanf("%d %d", &s, &e);
		AM[s][e] = 1;
		AM[e][s] = 1;
	}
}

void inputDataL()
{
	(void)scanf("%d", &n);
	(void)scanf("%d", &m);
	int b = 0;
	int c = 0;

	for (int i = 1; i <= m; i++)
	{
		(void)scanf("%d %d", &s, &e);
		b = ++AL[s][0];
		c = ++AL[e][0];
		AL[s][b] = e;
		AL[e][c] = s;
	}
}

void printM()
{
	printf("인접행렬 : \n");

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf("[%d][%d] : %d \n", i, j, AM[i][j]);
		}
	}
}

void printL()
{
	printf("인접리스트 : \n");

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= AL[i][0]; j++)
		{
			printf("[%d][%d] : %d \n", i, j, AL[i][j]);
		}
	}
}

int main()
{
	//(void)freopen("B2606.txt", "r", stdin);

	//inputDataM();
	inputDataL();
	
	//DFS_M(virus_host);
	DFS_L(virus_host);

	printf("%d\n", check - 1);

	//printM();
	//printL();

	return 0;
}