#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;
int map[20][20];
bool visited[20][20];
int T,N,M;
int max_home;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
int DFS(int start_x, int start_y, int cur_x, int cur_y, int dist, int home);
int main() {
	ios::sync_with_stdio(false);
	cin >> T;
	T++;
	for (int TC = 1; TC < T; TC++) {
		cin >> N >> M;
		max_home = 0;
		int total_home = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				visited[i][j] = false;
				if (map[i][j])
					total_home++;
			}
		}
		for (int count = 1; count < 30; count++) {
			int total = total_home * M - (count * count + (count - 1)*(count - 1));
			if (total >= 0) {
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++) {
						visited[i][j] = true;
						int home = DFS(i, j, i, j, count, 0);
						int temp = home * M - (count * count + (count - 1) * (count - 1));
						if (temp >= 0 && home > max_home) {
							max_home = home;
						}
						memset(visited, false, sizeof(visited));
					}
				}
			}
			else
				break;
		}
		cout << "#" << TC << " " << max_home << "\n";
	}
}
int DFS(int start_x, int start_y, int cur_x, int cur_y, int dist, int home) {
	if (map[cur_x][cur_y])
		home++;
	for (int i = 0; i < 4; i++) {
		int tempx = cur_x + dx[i]; 
		int tempy = cur_y + dy[i];
		if (tempx < 0 || tempx >= N || tempy < 0 || tempy >= N)
			continue;
		if (!visited[tempx][tempy]&&abs(tempx-start_x)+abs(tempy-start_y)<dist) {
			visited[tempx][tempy] = true;
			home += DFS(start_x, start_y, tempx, tempy, dist, 0);
		}
	}
	return home;
}