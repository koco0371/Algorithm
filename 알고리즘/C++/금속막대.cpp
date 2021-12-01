#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Screw {
public:
	int front;
	int back;
	int num;
	bool operator>(const Screw& n)const {
		return front > n.front;
	}
	bool operator<(const Screw& n)const {
		return front < n.front;
	}
};
Screw* list;
int* visited;
vector<Screw> ans;
int binary_search(int low, int high, int target);
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
		ans.clear();
		list = new Screw[N];
		int max = -1;
		for (int i = 0; i < N; i++) {
			int front, back;
			cin >> front >> back;
			list[i].front = front;
			list[i].back = back;
			list[i].num = i;
			if (max < front) {
				max = front;
			}
		}
		visited = new int[max + 1];
		for (int i = 0; i < max + 1; i++)
			visited[i] = -1;
		for (int i = 0; i < N; i++) {
			int temp = list[i].front;
			visited[temp] = list[i].back;
		}
		sort(list, list + N);
		int cnt = 0;
		while (true) {
			for (int i = 0; i < max + 1; i++) {
				if (visited[i] != -1) {
					vector<Screw> cur;
					int size = ans.size();
					int temp;
					cnt = binary_search(0, N - 1, i);
					temp = list[cnt].front;
					cur.push_back(list[cnt]);
					int next = visited[temp];
					while (visited[next] != -1) {
						if (size != 0) {
							if (next != ans[0].front) {
								if (next <= max)
									visited[temp] = visited[next];
								visited[next] = -1;
								cnt = binary_search(0, N - 1, next);
								cur.push_back(list[cnt]);
								next = visited[temp];
							}
							else
								break;
						}
						else {
							if (visited[next] <= max)
								visited[temp] = visited[next];
							visited[next] = -1;
							cnt = binary_search(0, N - 1, next);
							cur.push_back(list[cnt]);
							next = visited[temp];
						}
					}
					if (size != 0) {
						size = cur.size();
						if (cur[size - 1].back == ans[0].front) {
							size = ans.size();
							for (int i = 0; i < size; i++)
								cur.push_back(ans[i]);
						}
					}
					ans = cur;
					size = ans.size();
					if (size == N)
						break;
				}
			}
			int size = ans.size();
			if (size == N)
				break;
		}
		int size = ans.size();
		cout << "#" << TC << " ";
		for (int i = 0; i < size; i++) {
			cout << ans[i].front <<" "<< ans[i].back<<" ";
		}
		cout << endl;
		delete list;
		delete visited;
	}
}
int binary_search(int low, int high, int target) {
	int mid = (low + high) / 2;
	if (low == high && list[mid].front != target)
		return -1;
	if (list[mid].front == target)
		return mid;
	int result;
	if (list[mid].front > target)
		result=binary_search(low, mid, target);
	else
		result=binary_search(mid + 1, high, target);
	return result;
}