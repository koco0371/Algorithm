#include <iostream>
#include <queue>
#include <vector>
#define INF 9223372036854775807
using namespace std;
class Edge {
public:
	int start,end;
	long long int length;
	bool operator>(const Edge& n)const {
		return length > n.length;
	}
	bool operator<(const Edge& n)const {
		return length < n.length;
	}
};
class Node {
public:
	int num;
	long long int dist;
	vector<int> next;
};
Node dist[100000];
vector<Edge> list;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	T++;
	for (int TC = 1; TC < T; TC++) {
		int N, M;
		cin >> N >> M;
		int start, end;
		cin >> start >> end;
		start--;
		end--;
		list.clear();
		for (int i = 0; i < N; i++) {
			dist[i].num = i;
			dist[i].dist = INF;
			dist[i].next.clear();
		}
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			Edge* temp = new Edge;
			temp->start = a;
			temp->end = b;
			long long int len;
			cin >> len;
			temp->length = len;
			list.push_back(*temp);
			dist[a].next.push_back(i);
			dist[b].next.push_back(i);
		}
		priority_queue<Edge> pq;
		dist[start].dist = 0;
		Edge* temp = new Edge;
		temp->start = -1;
		temp->length = 0;
		temp->end = start;
		long long int ans = INF;
		pq.push(*temp);
		int size = pq.size();
		while (size) {
			Edge mem = pq.top();
			pq.pop();
			int cur = mem.end;
			Node next_node = dist[cur];
			int next_size = next_node.next.size();
			for (int i = 0; i < next_size; i++) {
				int next = next_node.next[i];
				long long int tmp = (-mem.length) + list[next].length;
				if (mem.end != list[next].end)
					cur = list[next].end;
				else
					cur = list[next].start;
				if (dist[cur].dist > tmp) {
					Edge* next_edge = new Edge;
					next_edge->start = next_node.num;
					next_edge->end = cur;
					next_edge->length = -tmp;
					dist[cur].dist = tmp;
					pq.push(*next_edge);
				}
			}
			size = pq.size();
		}
		ans = dist[end].dist;
		cout << "#" << TC << " " << ans << "\n";
	}
}