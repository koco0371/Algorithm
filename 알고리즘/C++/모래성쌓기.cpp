#include <iostream>
#include <string>
#include <queue>
using namespace std;
int dx[8] = { 1,1,1,0,0,-1,-1, -1 };
int dy[8] = { 1,0,-1,1,-1,1, 0, -1 };
class Point {
public:
	int x, y;
};
int Simulation(int H, int W);
int map[1000][1000] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		int H, W;
		cin >> H >> W;
		string* temp = new string[H];
		for (int i = 0; i < H; i++) {
			cin >> temp[i];
			for (int j = 0; j < W; j++) {
				if (temp[i][j] == '.')
					map[i][j] = -1;
				else {
					map[i][j] = temp[i][j] - '0';
				}
				
			}
		}

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (map[i][j] == -1) {
					for (int k = 0; k < 8; k++) {
						int tempx = i + dx[k];
						int tempy = j + dy[k];
						if (tempx < 0 || tempx >= H || tempy < 0 || tempy >= W)
							continue;
						if (map[tempx][tempy]>=0)
							map[tempx][tempy]--;
					}
				}
			}
		}
		
		int min = Simulation(H, W);
		min--;
		cout << "#" << TC << " " << min << endl;
	}
}
int Simulation(int H, int W) {
	bool check = true;
	int time = 0;

	queue<Point> buf;
	while (check) {
		time++;
		check = false;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (map[i][j] == 0) {	//ºØ±«
					map[i][j] = 0;
					Point* point = new Point;
					point->x = i;
					point->y = j;
					buf.push(*point);
					check = true;
					i--;
				}
			}
		}
		int buf_size = buf.size();
		for(int i=0; i<buf_size; i++){
			Point point = buf.front();
			int x = point.x;
			int y = point.y;
			for (int k = 0; k < 8; k++) {
				int tempx = x + dx[k];
				int tempy = y + dy[k];
				if (tempx <= 0 || tempx >= H - 1 || tempy <= 0 || tempy >= W - 1)
					continue;
				if (map[tempx][tempy] != 0)
					map[tempx][tempy]--;
			}
			buf.pop();
		}
	}
	return time;
}