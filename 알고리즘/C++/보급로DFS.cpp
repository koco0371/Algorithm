#include <iostream>
#include <string>
#define INF 999999
//DFS
using namespace std;
int map[100][100];
int dp[100][100];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
void DFS(int x, int y, int N, int cur);
void change(int x, int y, int N);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	T++;
	for (int TC = 1; TC < T; TC++) {
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			string temp;
			cin >> temp;
			for (int j = 0; j < N; j++) {
				map[i][j] = temp[j] - '0';
				
				dp[i][j] = INF;
			}
		}

		dp[0][0] = map[0][0];
		DFS(0, 0, N, 0);
		cout << "#" << TC << " " << dp[N - 1][N - 1] << endl;
	}
}

void DFS(int x, int y, int N, int cur) {
	if (x == N - 1 && y == N - 1) {
		dp[x][y] = cur < dp[x][y] ? cur : dp[x][y];
		return;
	}
	for (int i = 0; i < 2; i++) {
		int tempx = x + dx[i];
		int tempy = y + dy[i];
		if (tempx < 0 || tempx >= N || tempy < 0 || tempy >= N)
			continue;
		cur += map[tempx][tempy];
		if (cur < dp[tempx][tempy]) {
			dp[tempx][tempy] = cur;
			change(tempx, tempy, N);
			DFS(tempx, tempy, N, cur);
		}
		cur -= map[tempx][tempy];
		
	}
}
void change(int x, int y, int N) {
	if (dp[x][y] == INF)
		return;
	for (int i = 0; i < 4; i++) {
		int tempx = x + dx[i];
		int tempy = y + dy[i];
		if (tempx < 0 || tempx >= N || tempy < 0 || tempy >= N)
			continue;
		if (dp[tempx][tempy] != INF) {
			int temp = dp[x][y] + map[tempx][tempy];
			if (temp < dp[tempx][tempy]) {
				dp[tempx][tempy] = temp;
				change(tempx, tempy, N);
			}
			else {
				temp = dp[tempx][tempy] + map[x][y];
				if (temp < dp[x][y]) {
					dp[x][y] = temp;
					change(x, y, N);
				}
			}
		}
	}
}