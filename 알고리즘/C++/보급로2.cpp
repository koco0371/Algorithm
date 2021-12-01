#include <iostream>
#include <cstring>
#define MAX 987654321
using namespace std;
int map[100][100];
int dp[100][100];
int T, N;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
void change(int x, int y);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	T++;
	for (int TC = 1; TC < T; TC++) {
		cin >> N;
		string temp;
		for (int i = 0; i < N; i++) {
			cin >> temp;
			for (int j = 0; j < N; j++) {
				map[i][j] = temp[j] - '0';
				dp[i][j] = MAX;
			}
		}
		dp[0][0] = 0;
		for (int i = 0; i < N; i++) {	//ù���� �׳� ä��
			int tempy = i - 1;
			if (tempy < 0)
				continue;
			dp[0][i] = dp[0][tempy] + map[0][i];
		}
		for (int i = 1; i < N; i++) {
			for (int j = 0; j < N; j++) {	//���ʰ� ���� ���� �� ��� ����
				int min = MAX;
				int min_k = -1;
				for (int k = 0; k < 2; k++) {
					int tempx = i + dx[k];
					int tempy = j + dy[k];
					if (tempx < 0 || tempx >= N || tempy < 0 || tempy >= N)
						continue;
					if (min > dp[tempx][tempy]) {
						min_k = k;
						min = dp[tempx][tempy];
					}
				}
				int tempx = i + dx[min_k];
				int tempy = j + dy[min_k];
				dp[i][j] = dp[tempx][tempy] + map[i][j];	//�� �� ���� �� ��� ���� ���� ����
				change(i, j);	//�ٲ� ���� ���� ���� �ֺ��� ���� �ٲ� �� �ִ��� üũ��
			}
		}
		cout << "#" << TC << " " << dp[N - 1][N - 1] << "\n";
	}
}
void change(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int tempx = x + dx[i];
		int tempy = y + dy[i];
		if (tempx < 0 || tempx >= N || tempy < 0 || tempy >= N)
			continue;
		if (dp[tempx][tempy] != MAX) {	//�湮�ߴ� �κп� ���ؼ��� ���� �ٲ���
			int cur = dp[x][y];
			int total = cur + map[tempx][tempy];
			if (total < dp[tempx][tempy]) {
				dp[tempx][tempy] = total;
				change(tempx, tempy);
			}
		}
	}
}