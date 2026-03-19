#define MAX_N (25 + 2)
int map[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];

int N;
int A;
int A_count[625];

void inputData(void)
{
	char temp[MAX_N];

	(void)scanf("%d", &N);

	for (int i = 0; i < N; ++i) 
	{
		(void)scanf("%s", temp);
		for (int j = 0; j < N; ++j) {
			map[i][j] = temp[j] - '0';
		}
	}
}
// R,C의 상,하,좌,우 좌표 출력
int dR[4] = { -1,1,0,0 };
int dC[4] = { 0,0,-1,1 };

void print_RC(int R, int C)
{
	for (int i = 0; i < 4; i++)
	{
		printf("%d %d\n", R + dR[i], C + dC[i]);
	}
}

void move_map(int R, int C)
{
	int nR, nC;
	for (int i = 0; i < 4; i++)
	{
		nR = R + dR[i];
		nC = C + dC[i];
		
		if (nR < 0 || nR >= N || nC < 0 || nC >= N)
		{
			continue;
		}

		if (visited[nR][nC] == 0 && map[nR][nC] == 1)
		{
			visited[nR][nC] = 1;
			A += 1;
			move_map(nR, nC);
		}
		
	}
}

int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

int main()
{
	int count = 0;

	//(void)freopen("B2667.txt", "r", stdin);
	
	inputData();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] == 0 && map[i][j] == 1)
			{
				visited[i][j] = 1;
				A = 1;
				move_map(i, j);
				A_count[count] = A;
				count++;
			}
		}
	}

	printf("%d\n", count);

	qsort(A_count, count, sizeof(int), compare);

	for (int i = 0; i < count; i++)
	{
		printf("%d\n", A_count[i]);
	}

	return 0;
}