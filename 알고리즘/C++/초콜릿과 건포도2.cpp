#include <iostream>
#include <cstring>
using namespace std;
int dp[50][50][50][50];
int map[50][50]; 
int partial_sum[50][50];
int DFS(int x, int y, int h, int w);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		int N, M;
		cin >> N >> M;
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < N; i++) {
			partial_sum[i][0] = map[i][0];
			for (int j = 1; j < M; j++) {
				partial_sum[i][j] = partial_sum[i][j - 1] + map[i][j];
			}
		}

		int min = DFS(0, 0, N, M);
		cout << "#" << TC << " " << min << endl;
	}
}
int DFS(int x, int y, int h, int w) {
	if (w == 1 && h == 1)
		return 0;
	if (dp[x][y][h][w] != -1)
		return dp[x][y][h][w];
	int sum = 0;
	for (int i = x; i < x + h; i++) {
		for (int j = y; j < y + w; j++) {
			sum += map[i][j];
		}
	}
	//가로로 나누기
	for (int i = 1; i < h; i++) {
		if (dp[x][y][i][w] == -1)
			dp[x][y][i][w] = DFS(x, y, i, w);
		if (dp[x + i][y][h - i][w] == -1)
			dp[x + i][y][h - i][w] = DFS(x + i, y, h - i, w);
		int sum2 = dp[x][y][i][w] + dp[x + i][y][h - i][w] + sum;
		if (dp[x][y][h][w] != -1)
			dp[x][y][h][w] = sum2 < dp[x][y][h][w] ? sum2 : dp[x][y][h][w];
		else
			dp[x][y][h][w] = sum2;
	}
	//세로로 나누기
	for (int i = 1; i < w; i++) {
		if (dp[x][y][h][i] == -1)
			dp[x][y][h][i] = DFS(x, y, h, i);
		if (dp[x][y + i][h][w - i] == -1)
			dp[x][y + i][h][w - i] = DFS(x, y + i, h, w - i);
		int sum2 = dp[x][y][h][i] + dp[x][y + i][h][w - i] + sum;
		if (dp[x][y][h][w] != -1)
			dp[x][y][h][w] = sum2 < dp[x][y][h][w] ? sum2 : dp[x][y][h][w];
		else
			dp[x][y][h][w] = sum2;
	}
	return dp[x][y][h][w];
}