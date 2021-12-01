#include <stdio.h>
using namespace std;
int num[9];
bool check[9];
int fact[10] = { 1,1,2,6,24,120,720,5040,40320,362880 };
long long int ans;
int sum, N;
void DFS(int left_sum, int right_sum, int left_num, int right_num);
int main() {
	int T;
	scanf("%d", &T);
	T++;
	for (int TC = 1; TC < T; TC++) {
		scanf("%d", &N);
		sum = 0;
		ans = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d", &num[i]);
			sum += num[i];
			check[i] = false;
		}
		sum /= 2;
		for (int i = 0; i < N; i++) {
			check[i] = true;
			int left = num[i];
			int right = 0;
			DFS(left, right, 1, 0);
			check[i] = false;
		}
		printf("#%d %lld\n", TC, ans);
	}
}
void DFS(int left_sum, int right_sum, int left_num, int right_num) {
	if (right_sum > left_sum)
		return;
	if (left_num + right_num == N) {
		ans++;
		return;
	}
	if (left_sum > sum) {
		int size = N - (left_num + right_num);
		long long int temp = 1 << size;
		temp *= fact[size];
		ans += temp;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!check[i]) {
			check[i] = true;
			DFS(left_sum + num[i], right_sum, left_num + 1, right_num);
			DFS(left_sum, right_sum + num[i], left_num, right_num + 1);
			check[i] = false;
		}
	}
}