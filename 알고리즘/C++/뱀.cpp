#include <iostream>

using namespace std;
class Point {	//������ ����� �� ����, val�� 0�� �ƹ��͵� ���� ��, 1�� ��, 2�� ����� �ǹ��Ѵ�.
public:
	int x;
	int y;
	int val = 0;
	bool visit = false;
};
class Snake {
public:
	int dir;	//������ ��Ÿ���� ����, 0�� ����, 1�� ������, 2�� �Ʒ���, 3�� ������ �ǹ��Ѵ�.
	Point start;	//���� �Ӹ� �κ��� ��Ÿ���� ����, �ش� �κк��� �Ųٷ� �̵��Ѵ�.
};
int N;
int K;
int L;
int** dir;
Point** board;
void go(Point cur, int direction) {	//���� �̵��� ��Ÿ���� �Լ�

}
void turn() {	//���� ȸ���� ��Ÿ���� �Լ�

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
	//�ùķ��̼�
	while (1) {
		go(snake.start, snake.dir);
		time++;
	}
}