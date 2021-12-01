#include <iostream>
#include <cmath>
using namespace std;
class Point {
public:
	int x, y;
};
int min_len = 999999;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
void DFS(Point* start, Point* target, int level, int dir);
int main() {
	int T;
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		int x, y;
		cin >> x >> y;
		min_len = 999999;
		Point start, target;
		start.x = x;
		start.y = y;
		cin >> x >> y;
		target.x = x;
		target.y = y;
		DFS(&start, &target, 0, 0);
		DFS(&start, &target, 0, 1);
		cout << "#" << TC << " " << min_len << endl;
	}
}
void DFS(Point* start, Point* target, int level, int dir) {
	if (level > min_len)
		return;
	if (start->x == target->x&&start->y == target->y) {
		min_len = level < min_len ? level : min_len;
		return;
	}
	if (dir == 0) {	//현재 이동은 가로 이동
		int min = 999999;
		int min_i = -1;
		for (int i = 0; i < 2; i++) {
			int tempx = start->x + dx[i];
			int tempy = start->y + dy[i];
			if (tempx < -100 || tempx>100 || tempy < -100 || tempy>100)
				continue;
			int dist = abs(target->x - tempx) + abs(target->y - tempy);
			if (min > dist) {
				min = dist;
				min_i = i;
			}
		}
		Point temp;
		temp.x = start->x + dx[min_i];
		temp.y = start->y + dy[min_i];
		DFS(&temp, target, level + 1, 1);
	}
	else {	//현재 이동은 세로 이동
		int min = 999999;
		int min_i = -1;
		for (int i = 0; i < 2; i++) {
			int tempx = start->x + dx[2+i];
			int tempy = start->y + dy[2+i];
			if (tempx < -100 || tempx>100 || tempy < -100 || tempy>100)
				continue;
			int dist = abs(target->x - tempx) + abs(target->y - tempy);
			if (min > dist) {
				min = dist;
				min_i = i;
			}
		}
		Point temp;
		temp.x = start->x + dx[2 + min_i];
		temp.y = start->y + dy[2 + min_i];
		DFS(&temp, target, level + 1, 0);
	}
	return;
}