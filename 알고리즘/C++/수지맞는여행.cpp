#include <iostream>
#include <string>
using namespace std;
int max_len = -1;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
void DFS(string* map, bool* alpha, int level, int x, int y, int R, int C);
int main() {
	int T;
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		int R, C;
		cin >> R >> C;
		max_len = -1;
		bool alpha[26] = { false };
		string* map = new string[R];
		for (int i = 0; i < R; i++)
			cin >> map[i];
		DFS(map, alpha, 1, 0, 0, R, C);
		cout << "#" << TC << " " << max_len << endl;
	}
}
void DFS(string* map, bool* alpha, int level, int x, int y, int R, int C) {
	int index = map[x][y] - 'A';
	alpha[index] = true;
	bool check = false;
	for (int i = 0; i < 4; i++) {
		int tempx = x + dx[i];
		int tempy = y + dy[i];
		if (tempx < 0 || tempx >= R || tempy < 0 || tempy >= C)
			continue;
		int temp_i = map[tempx][tempy] - 'A';
		if (!alpha[temp_i]) {
			alpha[temp_i] = true;
			DFS(map, alpha, level + 1, tempx, tempy, R, C);
			alpha[temp_i] = false;
			check = true;
		}
	}
	if (!check)
		max_len = level > max_len ? level : max_len;
	return;
}