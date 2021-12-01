#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;

int** map;
int main() {
	int T;
	scanf("%d", &T);
	T++;
	for (int TC = 1; TC < T; TC++) {
		int N;
		scanf("%d", &N);
		map = new int* [N];
		for (int i = 0; i < N; i++) {
			map[i] = new int[N];
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
				if (!map[i][j]) {
					map[i][j] = INF;
				}
			}
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i != j) {
					for (int k = j + 1; k < N; k++) {
						if (i != k) {
							map[j][k] = min(map[j][k], map[j][i] + map[i][k]);
							map[k][j] = map[j][k];
						}
					}
				}
			}
		}
		int min_ans = INF;
		for (int i = 0; i < N; i++) {
			int sum = 0;
			for (int j = 0; j < N; j++)
				if (i != j)
					sum += map[i][j];
			min_ans=sum<min_ans?sum:min_ans;
		}
		printf("#%d %d\n", TC, min_ans);
	}
}