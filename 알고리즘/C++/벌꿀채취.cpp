#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int max_ans = -999999;
void DFS(int** honey, int**bucket, int cur, int level, int x, int y, int N, int M, int C);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		int N, M, C;
		max_ans = -999999;
		cin >> N >> M >> C;
		int** honey = new int*[N];
		for (int i = 0; i < N; i++) {
			honey[i] = new int[N];
			for (int j = 0; j < N; j++)
				cin >> honey[i][j];
		}
		int** bucket = new int*[2];
		for (int i = 0; i < 2; i++) {
			bucket[i] = new int[M];
			for (int j = 0; j < M; j++)
				bucket[i][j] = -1;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				DFS(honey, bucket, 0, 0, i, j, N, M, C);
		}
		cout << "#" << TC << " " << max_ans << endl;
	}
}
void DFS(int** honey, int**bucket, int cur, int level, int x, int y, int N, int M, int C) {
	if (level == 2) {		//���� ����, 2���� ��� ä��� ����
		max_ans = max_ans < cur ? cur : max_ans;
		return;
	}
	int tempy = y + M;
	if (tempy <= N) {
		int l = 0;
		int total = 0;
		int sum = 0;
		for (int i = y; i < tempy; i++) {	//�������� ä��
			bucket[level][l] = honey[x][i];
			total += pow(honey[x][i], 2);
			sum += honey[x][i];
			l++;
		}
		if (sum <= C) {	//�������� ä�� ���� ���Ѻ��� ���� ���
			cur += total;
		}
		else {	//���Ѻ��� ���ִ� ���� Ŭ ��� ���� ū ���� ������ ������ ã�´�.
			int limit = pow(2, M);
			total = 0;
			int max_total = -1;
			int sum = 0;
			for (int i = 0; i < limit; i++) {
				int temp = i;
				total = 0;
				sum = 0;
				int j = 0;
				while (temp) {
					int standard = 1;
					int result = temp & standard;
					if (result) {
						sum += bucket[level][j];
						total += pow(bucket[level][j], 2);
					}
					j++;
					temp >>= 1;
				}
				if (sum <= C)
					max_total = total > max_total ? total : max_total;
			}
			cur += max_total;
		}
		level++;
		y = tempy;
		if (level == 1) {
			for (int i = x; i < N; i++) {
				for (int j = y; j < N; j++) {
					DFS(honey, bucket, cur, level, i, j, N, M, C);
					if (j == N - 1)	//���� ����
						y = 0;
				}
				if (y == N)
					y = 0;
			}
		}
		else  // �����̹Ƿ� �ѹ��� ����
			DFS(honey, bucket, cur, level, x, y, N, M, C);
	}
	return;
}