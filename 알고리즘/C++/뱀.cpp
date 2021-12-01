#include <iostream>

using namespace std;
class Point {	//보드의 기반이 될 변수, val은 0은 아무것도 없는 것, 1은 뱀, 2는 사과를 의미한다.
public:
	int x;
	int y;
	int val = 0;
	bool visit = false;
};
class Snake {
public:
	int dir;	//방향을 나타내는 변수, 0은 왼쪽, 1은 오른쪽, 2는 아래쪽, 3은 위쪽을 의미한다.
	Point start;	//뱀의 머리 부분을 나타내는 변수, 해당 부분부터 거꾸로 이동한다.
};
int N;
int K;
int L;
int** dir;
Point** board;
void go(Point cur, int direction) {	//뱀의 이동을 나타내는 함수

}
void turn() {	//뱀의 회전을 나타내는 함수

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
	board = new Point * [N];
	for (int i = 0; i < N; i++) {
		board[i] = new Point[N];
		for (int j = 0; j < N; j++) {
			board[i][j].x = i;
			board[i][j].y = j;
			board[i][j].val = 0;
		}
	}
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		board[x][y].val = 2;
	}
	dir = new int* [L];
	for (int i = 0; i < L; i++) {
		dir[i] = new int[2];
		int time;
		char direction;
		cin >> time >> direction;
		dir[i][0] = time;
		if (direction == 'L') {
			dir[i][1] = 0;
		}
		else
			dir[i][1] = 1;
	}
	Snake snake;
	snake.dir = 2;
	snake.start = board[0][0];
	int time = 0;
	//시뮬레이션
	while (1) {
		go(snake.start, snake.dir);
		time++;
	}
}