#include <iostream>
using namespace std;
int N, M;
int** board;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
class Robot {
public:
	int dir;	//0은 위, 1은 왼쪽, 2는 아래, 3은 오른쪽
	int x;
	int y;
};
int clean(Robot* robot) {
	//1. 현재위치 청소
	int x = robot->x;
	int y = robot->y;
	board[x][y] = 0;
	
	//2. 현재방향 기준 왼쪽방향부터 차례대로 탐색
	int dir = robot->dir;
	bool check = false;
	for (int i = 0; i < 4; i++) {
		dir++;
		if (dir == 4)
			dir = 0;
		int tmpx = x + dx[dir];
		int tmpy = y + dy[dir];
		if (tmpx < 0 || tmpx >= N || tmpy < 0 || tmpy >= M)
			continue;
		if (board[tmpx][tmpy] == 2) {	//해당 방향에 청소하지 않은 공간 존재
			robot->x = tmpx;
			robot->y = tmpy;
			robot->dir = dir;
			check = true;
			break;
		}
	}
	if (!check) {	//네 방향 모두 청소가 되어 있거나 벽인 경우
		dir += 2;
		if (dir >= 4)
			dir -= 4;
		int tmpx = x + dx[dir];
		int tmpy = y + dy[dir];
		if (board[tmpx][tmpy] == 1) {	//해당 방향이 벽
			return -1;
		}
		else {
			robot->x = tmpx;
			robot->y = tmpy;
			return 0;
		}
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	Robot robot;
	int x, y, d;
	cin >> x >> y >> d;
	robot.x = x;
	robot.y = y;
	robot.dir = d;
	board = new int* [N];
	for (int i = 0; i < N; i++) {
		board[i] = new int[M];
		for (int j = 0; j < M; j++) {
			cin >> x;
			if (x == 0)
				board[i][j] = 2;
			else
				board[i][j] = x;
		}
	}
	while (1) {
		int status = clean(&robot);
		if (status == -1) {
			break;
		}
	}
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 0)
				count++;
		}
	}
	cout << count;
	return 0;
}