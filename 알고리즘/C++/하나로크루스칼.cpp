#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
class Island {
public:
	int num;
	long long int x, y;
	bool visit;
};
class Bridge {
public:
	int start, end;
	double dist;
	bool operator>(const Bridge& n) const {
		return dist > n.dist;
	}
	bool operator<(const Bridge& n)const {
		return dist < n.dist;
	}
};
int set[1000];
Island list[1000];
int get_set(int a) {
	if (set[a] == a) return a;
	return set[a]= get_set(set[a]);
}
void union_set(int a, int b) {
	a = get_set(a);
	b = get_set(b);
	if (a < b)	set[b] = a;
	else   set[a] = b;
}
bool find_set(int a, int b) {
	if (get_set(a) == get_set(b)) return true;
	else return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	T++;
	for (int TC = 1; TC < T; TC++) {
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			long long int x;
			cin >> x;
			list[i].num = i;
			list[i].x = x;
			list[i].visit = false;
			set[i] = i;
		}
		for (int i = 0; i < N; i++) {
			long long int y;
			cin >> y;
			list[i].y = y;
		}
		double E;
		cin >> E;
		vector<Bridge> edge;
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				Bridge* bridge = new Bridge;
				bridge->start = i;
				bridge->end = j;
				bridge->dist = pow(list[i].x - list[j].x, 2) + pow(list[i].y - list[j].y, 2);
				bridge->dist *= E;
				edge.push_back(*bridge);
			}
		}
		sort(edge.begin(), edge.end());
		int size = edge.size();
		double ans = 0;
		for (int i = 0; i < size; i++) {
			if (!find_set(edge[i].start, edge[i].end)) {
				ans += edge[i].dist;
				union_set(edge[i].start, edge[i].end);
			}
		}
		long long int real_ans = ans + 0.5;
		cout << "#" << TC << " " << real_ans << endl;
	}
}