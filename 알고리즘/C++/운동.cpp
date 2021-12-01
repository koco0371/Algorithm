#include <iostream>
#include <vector>
using namespace std;
class Edge {
public:
	int start, end;
	int len;
};
class Point {
public:
	friend Edge;
	int num;
	bool visit;
	vector<Edge> edge;
};
int min_len = -1;
Point* greedy(Point* point_list, Point* start, Point* cur, int len);
void DFS(Point* point_list, Point* start, Point* cur, int len);
int main() {
	int T;
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		int N, M;
		cin >> N >> M;
		min_len = -1;
		Point* point_list = new Point[N];
		for (int i = 0; i < N; i++) {
			point_list[i].num = i;
			point_list[i].visit = false;
		}
		for (int i = 0; i < M; i++) {
			int s, e, c;
			Edge* edge = new Edge;
			cin >> s >> e >> c;
			s--;
			e--;
			edge->start = s;
			edge->end = e;
			edge->len = c;
			point_list[s].edge.push_back(*edge);
		}
		int* mem = new int[N];
		for (int i = 0; i < N; i++) {
			mem[i] = 0;
		}
		for (int i = 0; i < N; i++) {
			if (mem[i] == 1)
				continue;
			Point* temp = &point_list[i];
			temp = greedy(point_list, &point_list[i], &point_list[i], 0);
			if (temp != &point_list[i] && mem[temp->num] != 1) {
				DFS(point_list, temp, temp, 0);
				mem[temp->num] = 1;
			}
		}
		cout << "#" << TC << " " << min_len << endl;
	}
}
Point* greedy(Point* point_list, Point* start, Point* cur, int len) {
	if (min_len != -1 && len > min_len)
		return start;
	if (len != 0 && start == cur) {
		if (min_len != -1)
			min_len = len < min_len ? len : min_len;
		else
			min_len = len;
		return start;
	}
	int size = cur->edge.size();
	for (int i = 0; i < size; i++) {
		if (!point_list[cur->edge[i].end].visit) {
			len += cur->edge[i].len;
			point_list[cur->edge[i].end].visit = true;
			Point* point = start;
			point = greedy(point_list, start, &point_list[cur->edge[i].end], len);
			point_list[cur->edge[i].end].visit = false;
			len -= cur->edge[i].len;
			if (point != start) {
				return point;
			}
		}
		else
			return &point_list[cur->edge[i].end];
	}
	return start;
}
void DFS(Point* point_list, Point* start, Point* cur, int len) {
	if (min_len != -1 && len > min_len)
		return;
	if (len != 0 && start == cur) {
		if (min_len != -1)
			min_len = len < min_len ? len : min_len;
		else
			min_len = len;
		return;
	}
	int size = cur->edge.size();
	for (int i = 0; i < size; i++) {
		if (!point_list[cur->edge[i].end].visit) {
			len += cur->edge[i].len;
			point_list[cur->edge[i].end].visit = true;
			DFS(point_list, start, &point_list[cur->edge[i].end], len);
			point_list[cur->edge[i].end].visit = false;
			len -= cur->edge[i].len;
		}
	}
}