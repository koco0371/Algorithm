#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int max_dist = -1;
class Point {
public:
	int num;
	vector<int> next;
};
void DFS(Point* point_list, bool* visited, int cur, int level, int N);
int main() {
	int T;
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		int N, M;
		cin >> N >> M;
		max_dist = -1;
		Point* point_list = new Point[N];
		bool* visited = new bool[N];
		for (int i = 0; i < N; i++) {
			point_list[i].num = i;
			visited[i] = false;
		}
		for (int i = 0; i < M; i++) {
			int x, y;
			cin >> x >> y;
			x--;
			y--;
			point_list[x].next.push_back(y);
			point_list[y].next.push_back(x);
		}
		for (int i = 0; i < N; i++) {
			visited[i] = true;
			DFS(point_list, visited, i, 1, N);
			visited[i] = false;
		}
		cout << "#" << TC << " " << max_dist << endl;
	}
}
void DFS(Point* point_list, bool* visited, int cur, int level, int N) {
	bool check = false;
	int size = point_list[cur].next.size();
	for (int i = 0; i < size; i++) {
		int temp = point_list[cur].next[i];
		if (!visited[temp]) {
			visited[temp] = true;
			DFS(point_list, visited, temp, level + 1, N);
			visited[temp] = false;
			check = true;
		}
	}
	if (!check) {
		max_dist = level > max_dist ? level : max_dist;
		return;
	}
	return;
}