#include <iostream>
using namespace std;
int max_ans = -1;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
void DFS(int** map, bool** visited, int prev, int len, int x, int y, int N, int K);
int main() {
	int T;
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		int N, K;
		cin >> N >> K;
		max_ans = -1;
		int max = -1;
		int** map = new int*[N];
		bool** visited = new bool*[N];
		for (int i = 0; i < N; i++) {
			map[i] = new int[N];
			visited[i] = new bool[N];
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				visited[i][j] = false;
				max = map[i][j] > max ? map[i][j] : max;
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == max) {
					visited[i][j] = true;
					DFS(map, visited, max , 0, i, j, N, K);
					visited[i][j] = false;
				}
			}
		}
		cout << "#" << TC << " " << max_ans << endl;
	}
}
void DFS(int** map, bool** visited, int prev, int len, int x, int y, int N, int K) {
	bool check = false;
	len++;
	for (int i = 0; i < 4; i++) {
		int tempx = x + dx[i];
		int tempy = y + dy[i];
		if (tempx < 0 || tempx >= N || tempy < 0 || tempy >= N)
			continue;
		int temp = map[tempx][tempy];
		if (!visited[tempx][tempy]) {
			if (temp >= prev && temp - prev < K) {	//이전의 높이보다 높지만, K가 있어 등산이 가능한 경우
				check = true;
				temp = prev - 1;
				visited[tempx][tempy] = true;
				DFS(map, visited, temp, len, tempx, tempy, N, 0);
				visited[tempx][tempy] = false;
			}
			else if (temp < prev) {
				check = true;
				visited[tempx][tempy] = true;
				DFS(map, visited, temp, len, tempx, tempy, N, K);
				visited[tempx][tempy] = false;
			}
		}
	}
	if (!check) {
		max_ans = max_ans < len ? len : max_ans;
		return;
	}
	return;
}