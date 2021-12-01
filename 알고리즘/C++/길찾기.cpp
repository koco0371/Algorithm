#include <iostream>
using namespace std;
class Point {
public:
	int index = 0;
	int n[2];
};
Point route[100];
bool visited[100];
int answer = 0;
void DFS(int index);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int TC = 1; TC < 11; TC++) {
		int a;
		cin >> a;
		int total;
		cin >> total;
		for (int i = 0; i < 100; i++) {
			visited[i] = false;
			route[i].index = 0;
		}
		answer = 0;
		for (int i = 0; i < total; i++) {
			int x, y;
			cin >> x >> y;
			route[x].n[route[x].index++] = y;
		}
		DFS(0);
		cout << "#" << TC << " " << answer << "\n";
	}
}
void DFS(int index) {
	if (index == 99) {
		answer = 1;
		return;
	}
	for (int i = 0; i < route[index].index; i++) {
		if (!visited[route[index].n[i]]) {
			visited[route[index].n[i]] = true;
			DFS(route[index].n[i]);
		}
		if (answer)
			return;
	}
}