#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int lcs[501][501];
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
		string target1, target2;
		cin >> target1 >> target2;
		target1 = '0' + target1;
		target2 = '0' + target2;
		N++;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == 0 || j == 0) {
					lcs[i][j] = 0;
					continue;
				}
				if (target1[i] == target2[j]) {
					lcs[i][j] = lcs[i - 1][j - 1] + 1;
				}
				else {
					lcs[i][j] = lcs[i - 1][j] > lcs[i][j - 1] ? lcs[i - 1][j] : lcs[i][j - 1];
				}
			}
		}
		double ans = lcs[N - 1][N - 1];
		ans /= N - 1;
		ans *= 100;
		printf("#%d %.2lf\n", TC, ans);
	}
}