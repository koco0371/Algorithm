#include <iostream>
#include <cmath>
#define INF 987654321
using namespace std;

class Point {
public:
	int x, y;
};
int dp[1<<11][11];
Point list[12];
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
		N++;
		int x, y;
		cin >> x >> y;
		list[0].x = x;
		list[0].y = y;
		cin >> x >> y;
		list[N].x = x;
		list[N].y = y;
		for (int i = 1; i < N; i++) {
			cin >> x >> y;
			list[i].x = x;
			list[i].y = y;
		}
		for (int i = 0; i < 1 << N; i++) {
			for (int j = 0; j < N; j++) {
				dp[i][j] = INF;
			}
		}
		dp[1][0] = 0;
		for (int i = 1; i < 1 << N; i += 2) {
			for (int j = 1; j < N; j++) {
				if (i & (1 << j)) {
					for (int k = 0; k < N; k++) {
						if (j != k && i & (1 << k)) {
							int dist = dp[i - (1 << j)][k] + abs(list[k].x - list[j].x) + abs(list[k].y - list[j].y);
							dp[i][j] = dist < dp[i][j] ? dist : dp[i][j];
						}
					}
				}
			}
		}
		int ans = INF;
		for (int i = 1; i < N; i++) {
			int dist = dp[(1 << N) - 1][i] + abs(list[i].x - list[N].x) + abs(list[i].y - list[N].y);
			ans = ans > dist ? dist : ans;
		}
		cout << "#" << TC << " " << ans << "\n";
	}
}