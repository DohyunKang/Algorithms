#include <iostream>
#include <vector>

using namespace std;

int T, M, N, K;
vector<vector<int>> field;
vector<vector<bool>> visited;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void DFS(int x, int y) {
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
            if (field[nx][ny] == 1 && !visited[nx][ny]) {
                DFS(nx, ny);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while (T--) {
        cin >> M >> N >> K;

        // 벡터 크기 초기화 (기존 데이터 삭제 후 다시 생성)
        field = vector<vector<int>>(M, vector<int>(N, 0));
        visited = vector<vector<bool>>(M, vector<bool>(N, false));

        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            field[x][y] = 1;
        }

        int count = 0;

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (field[i][j] == 1 && !visited[i][j]) {
                    DFS(i, j);
                    count++;
                }
            }
        }

        cout << count << "\n";
    }

    return 0;
}
