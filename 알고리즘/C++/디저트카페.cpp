#include <iostream>
using namespace std;
class Point {
public:
	int x, y;
};
int dx[4] = { 1,1,-1,-1 };
int dy[4] = { 1,-1,-1,1 };
int max_len = -1;
void DFS(int** map, bool* dessert, int len, int dir, Point start, Point cur, int N);
int main() {
	int T;
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		int N;
		cin >> N;
		max_len = -1;
		bool dessert[101] = { false };
		int** map = new int*[N];
		for (int i = 0; i < N; i++) {
			map[i] = new int[N];
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				Point start;
				start.x = i;
				start.y = j;
				if (start.y == 0 || start.y == N - 1 || start.x >= N - 2)
					continue;
				int temp = map[i][j];
				dessert[temp] = true;
				DFS(map, dessert, 0, 0, start, start, N);
				dessert[temp] = false;
			}
		}
		cout << "#" << TC << " " << max_len << endl;
	}
}
void DFS(int** map, bool* dessert, int len, int dir, Point start, Point cur, int N) {
	if (len != 0 && start.x == cur.x && start.y == cur.y) {
		max_len = len > max_len ? len : max_len;
		return;
	}
	for (int i = 0; i < 2; i++) {
		if (start.x == cur.x && start.y == cur.y)
			if (i == 1)
				continue;
		int tempx = cur.x + dx[dir + i];
		int tempy = cur.y + dy[dir + i];
		if (tempx < 0 || tempx >= N || tempy < 0 || tempy >= N)
			continue;
		int temp = map[tempx][tempy];
		Point next;
		next.x = tempx;
		next.y = tempy;
		if (!dessert[temp]) {
			dessert[temp] = true;
			DFS(map, dessert, len + 1, dir + i, start, next, N);
			dessert[temp] = false;
		}
		else if (start.x == tempx && start.y == tempy)
			DFS(map, dessert, len + 1, dir + i, start, next, N);
	}
	return;
}