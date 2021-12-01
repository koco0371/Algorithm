#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Node {
public:
	bool visit = false;
	vector<int> next;
};
Node list[101];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int TC = 1; TC < 11; TC++) {
		int edge,start;
		cin >> edge >> start;
		for (int i = 0; i < 100; i++) {
			list[i].visit = false;
			list[i].next.clear();
		}
		edge /= 2;
		for (int i = 0; i < edge; i++) {
			int before, next;
			cin >> before >> next;
			list[before].next.push_back(next);
		}
		queue<Node> q;
		list[start].visit = true;
		q.push(list[start]);
		int max = start;
		while (!q.empty()) {
			queue<Node> next_turn;
			int size = q.size();
			int cur_max = -1;
			for (int i = 0; i < size; i++) {
				Node cur = q.front();
				q.pop();
				int neighbor = cur.next.size();
				for (int j = 0; j < neighbor; j++) {
					int index = cur.next[j];
					if (!list[index].visit) {
						cur_max = index > cur_max ? index : cur_max;
						list[index].visit = true;
						next_turn.push(list[index]);
					}
				}
			}
			q = next_turn;
			if (cur_max != -1)
				max = cur_max;
		}
		cout << "#" << TC << " " << max << "\n";
	}
}