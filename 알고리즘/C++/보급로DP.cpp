#include <iostream>
#include <string>
#define INF 999999
using namespace std;
int map[100][100];
int dp[100][100];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
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
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int min = INF;
				for (int k = 0; k < 2; k++) {
					int tempx = i + dx[k];
					int tempy = j + dy[k];
					if (tempx < 0 || tempx >= N || tempy < 0 || tempy >= N)
						continue;
					min = dp[tempx][tempy] < min ? dp[tempx][tempy] : min;
				}
				if (min != INF) {
					dp[i][j] = min + map[i][j];
					change(i, j, N);
				}
			}
		}
		cout << "#" << TC << " " << dp[N - 1][N - 1] << endl;
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
		}
	}
}