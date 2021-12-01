#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
class Island {
public:
	long long int x, y;
};
class Edge {
public:
	int a[2];
	double len;
	bool operator>(const Edge& n)const {
		return len > n.len;
	}
	bool operator<(const Edge& n)const {
		return len < n.len;
	}
};
Island list[1000];
int set[1000];
int N, T;
double E;
int get_set(int a) {
	if (set[a] == a)	return a;
	else
		return set[a] = get_set(set[a]);
}
bool find_set(int a, int b) {
	if (get_set(a) == get_set(b))	return true;
	return false;
}
void union_set(int a, int b) {
	a = get_set(a);
	b = get_set(b);
	if (a < b)	set[b] = a;
	else  set[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	T++;
	for (int TC = 1; TC < T; TC++) {
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> list[i].x;
		for (int i = 0; i < N; i++) {
			cin >> list[i].y;
			set[i] = i;
		}
		cin >> E;
		vector<Edge> edge;
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				Edge* temp = new Edge;
				temp->a[0] = i;
				temp->a[1] = j;
				temp->len = pow(list[i].x - list[j].x, 2) + pow(list[i].y - list[j].y, 2);
				edge.push_back(*temp);
			}
		}
		sort(edge.begin(), edge.end());
		int size = edge.size();
		double ans = 0;
		for (int i = 0; i < size; i++) {
			if (!find_set(edge[i].a[0], edge[i].a[1])) {
				ans += edge[i].len;
				union_set(edge[i].a[0], edge[i].a[1]);
			}
		}
		ans *= E;
		long long int real_ans = ans + 0.5;
		cout << "#" << TC << " " << real_ans << "\n";
	}
}