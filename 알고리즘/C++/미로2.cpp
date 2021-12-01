#include <iostream>
#include <cstring>
using namespace std;
int T;
int map[100][100];
bool visited[100][100];
int answer = 0;
class Point {
public:
	int x, y;
};
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };
void DFS(Point cur);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int TC = 1; TC < 11; TC++) {
		int a;
		cin >> a;
		string temp;
		answer = 0;
		Point start;
		for (int i = 0; i < 100; i++) {
			cin >> temp;
			for (int j = 0; j < 100; j++) {
				map[i][j] = temp[j] - '0';
				visited[i][j] = false;
				if (map[i][j] == 2) {
					start.x = i;
					start.y = j;
				}
			}
		}
		visited[start.x][start.y] = true;
		DFS(start);
		cout << "#" << TC << " " << answer << "\n";
	}
}
void DFS(Point cur) {
	if (answer) {
		return;
	}
	if (map[cur.x][cur.y] == 3) {
		answer = 1;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int tempx = cur.x + dx[i];
		int tempy = cur.y + dy[i];
		if (tempx < 0 || tempx>100 || tempy < 0 || tempy>100)
			continue;
		if (!visited[tempx][tempy] && map[tempx][tempy] != 1) {
			Point temp;
			temp.x = tempx;
			temp.y = tempy;
			visited[tempx][tempy] = true;
			DFS(temp);
		}
	}
}