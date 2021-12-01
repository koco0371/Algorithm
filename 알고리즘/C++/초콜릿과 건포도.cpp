#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define Max 55
#define INF 987654321

int R, C, m[Max][Max], cache[Max][Max][Max][Max];

int simulation(int r, int c, int rlen, int clen)
{
	if (rlen == 1 && clen == 1) {
		return 0;
	}

	int & ret = cache[r][c][rlen][clen];

	if (ret != -1) {
		return ret;
	}

	ret = INF;

	int sum = m[r + rlen - 1][c + clen - 1] - m[r + rlen - 1][c - 1] - m[r - 1][c + clen - 1] + m[r - 1][c - 1];

	// 가로로 계속 자르기
	for (int i = 1; i < rlen; i++) {
		ret = min(ret, sum + simulation(r, c, i, clen) + simulation(r + i, c, rlen - i, clen));
	}

	// 세로로 계속 자르기
	for (int j = 1; j < clen; j++) {
		ret = min(ret, sum + simulation(r, c, rlen, j) + simulation(r, c + j, rlen, clen - j));
	}

	return ret;
}

int main()
{
	cin.tie(0);
	int test_case;
	scanf("%d", &test_case);

	for (int tc = 1; tc <= test_case; tc++) {
		memset(cache, -1, sizeof(cache));
		memset(m, 0, sizeof(m));

		scanf("%d %d", &R, &C);

		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				scanf("%d", &m[i][j]);
			}
		}

		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C - 1; j++) {
				m[i][j + 1] += m[i][j];
			}
		}

		for (int i = 1; i <= R - 1; i++) {
			for (int j = 1; j <= C; j++) {
				m[i + 1][j] += m[i][j];
			}
		}

		printf("#%d %d\n", tc, simulation(1, 1, R, C));
	}


	return 0;
}
