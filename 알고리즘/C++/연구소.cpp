#include <iostream>
using namespace std;
int N, M;
int** area;
int** copy_area;
int max_area = -1;
int dx[4] = { -1, 0, 0 ,1 };
int dy[4] = { 0, -1, 1, 0 };
void spread(int x, int y) {	//2를 퍼뜨리는 함수, 1을 만나면 그만둔다.
	for (int i = 0; i < 4; i++) {
		int tmp_x = x + dx[i];
		int tmp_y = y + dy[i];
		if (tmp_x < 0 || tmp_x >= N || tmp_y < 0 || tmp_y >= M)
			continue;
		if (copy_area[tmp_x][tmp_y] == 0) {
			copy_area[tmp_x][tmp_y] = 2;
			spread(tmp_x, tmp_y);
		}
	}
}
void DFS(int count) {
	//점 한개씩 선택하여, count가 3이 되면 넓이를 계산한다.
	if (count == 3) {	//2를 퍼뜨릴 수 있는 곳까지 퍼뜨린다.
		bool check = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				copy_area[i][j] = area[i][j];
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (copy_area[i][j] == 2)
					spread(i,j);
			}
		}
		int count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (copy_area[i][j] == 0)
					count++;
			}
		}
		max_area = count > max_area ? count : max_area;
		return;
	}
	//점 선택
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (area[i][j] == 0) {
				area[i][j] = 1;
				DFS(count + 1);
				area[i][j] = 0;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	area = new int* [N];
	copy_area = new int* [N];
	for (int i = 0; i < N; i++) {
		area[i] = new int[M];
		copy_area[i] = new int[M];
		for (int j = 0; j < M; j++) {
			int tmp;
			cin >> tmp;
			area[i][j] = tmp;
			copy_area[i][j] = tmp;
		}
	}
	DFS(0);
	cout << max_area;
}