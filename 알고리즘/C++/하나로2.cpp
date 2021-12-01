#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int T,N;
double E;
class Island {
public:
	long long int x, y;
};
class Edge {
public:
	long long int length;
	vector<int> vertex;
	bool operator< (const Edge& n) const {
		return length < n.length;
	}
};
Island list[1000];
int island[1000];
int get_set(int a) {
	if (a == island[a])	return a;
	return get_set(island[a]);
}
bool find_set(int a, int b) {
	a = get_set(a);
	b = get_set(b);
	if (a == b)	return true;
	else	return false;
}
void union_set(int a, int b) {
	a = get_set(a);
	b = get_set(b);
	if (a > b)	island[a] = b;
	else	island[b] = a;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	T++;
	for (int TC = 1; TC < T; TC++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			int x;
			cin >> x;
			list[i].x = x;
			island[i] = i;
		}
		for (int i = 0; i < N; i++) {
			int y;
			cin >> y;
			list[i].y = y;
		}
		cin >> E;
		priority_queue<Edge> q;
		for (int i = 0; i < N; i++) {	
			for (int j = i + 1; j < N; j++) {
				Edge temp;
				temp.vertex.push_back(i);
				temp.vertex.push_back(j);
				temp.length = pow(list[i].x - list[j].x, 2) + pow(list[i].y - list[j].y, 2);
				temp.length = -temp.length;
				q.push(temp);
			}
		}
		int size = q.size();
		double answer = 0;
		for (int i = 0; i < size; i++) {
			Edge temp = q.top();
			q.pop();
			if (!find_set(temp.vertex[0], temp.vertex[1])) {
				union_set(temp.vertex[0], temp.vertex[1]);
				long long int temp_len = -temp.length;
				answer += temp_len * E;
			}
		}
		long long int real_answer = answer + 0.5;
		cout << "#" << TC << " " << real_answer << "\n";
	}
}