#include <iostream>
#include <vector>
using namespace std;
class Point {
public:
	int color;	//0: white, 1: black
	long long int num;
	vector<long long int> next;
};
long long int N;
long long int ans = 0;
bool* visited;
Point* point_list;
long long int DFS(Point* cur, int before);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T; 
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		cin >> N;
		ans = 1;
		point_list = new Point[N];
		visited = new bool[N];
		visited[N - 1] = false;
		point_list[N - 1].color = -1;
		point_list[N - 1].num = N - 1;
		for (long long int i = 0; i < N - 1; i++) {
			long long int x, y;
			cin >> x >> y;
			x--;
			y--;
			point_list[x].next.push_back(y);
			point_list[y].next.push_back(x);
			visited[i] = false;
			point_list[i].color = -1;
			point_list[i].num = i;
		}
		visited[0] = true;
		DFS(&point_list[0], -1);
		cout << "#" << TC << " " << ans << endl;
		delete visited;
		delete point_list;
	}
}
long long int DFS(Point* cur, int before) {
	long long int result = 0;
	if (before == -1) {
		for (int i = 0; i < 2; i++) {
			cur->color = i;
			int size = cur->next.size();
			for (int j = 0; j < size; j++) {
				long long int temp = cur->next[j];
				if (!visited[temp]) {
					visited[temp] = true;
					DFS(&point_list[temp], cur->num);
					visited[temp] = false;
				}
			}
		}
	}
	else {
		if (point_list[before].color == 0) {
			for (int i = 0; i < 2; i++) {
				cur->color = i;
				int size = cur->next.size();
				for (int j = 0; j < size; j++) {
					int temp = cur->next[j];
					if (!visited[temp]) {
						visited[temp] = true;
						DFS(&point_list[temp], cur->num);
						visited[temp] = false;
					}
				}
			}
		}
		else {
			cur->color = 0;
			int size = cur->next.size();
			for (int j = 0; j < size; j++) {
				int temp = cur->next[j];
				if (!visited[temp]) {
					visited[temp] = true;
					DFS(&point_list[temp], cur->num);
					visited[temp] = false;
				}
			}
			
		}
	}
	
	return;
}