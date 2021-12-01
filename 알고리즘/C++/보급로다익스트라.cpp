#include <iostream>
#include <string>
#include <queue>
#define INF 999999
//DFS
using namespace std;
int map[100][100];
int arr[100][100];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
class Node {
public:
	int x, y;
	int dist;
	int post_x, post_y;
	bool operator >(const Node& n) const{
		return dist > n.dist;
	}
	bool operator <(const Node& n) const{
		return dist < n.dist;
	}
};
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
			string temp;
			cin >> temp;
			for (int j = 0; j < N; j++) {
				map[i][j] = temp[j] - '0';
				arr[i][j] = INF;
			}
		}
		arr[0][0]=0;
		priority_queue<Node> pq;
		Node start;
		start.x = 0;
		start.y = 0;
		start.dist = 0;
		pq.push(start);
		int size = pq.size();
		while (size) {
			Node temp = pq.top();
			pq.pop();
			for (int i = 0; i < 4; i++) {
				int tempx = temp.x + dx[i];
				int tempy = temp.y + dy[i];
				int cost = (-1*temp.dist) + map[tempx][tempy];
				if (tempx < 0 || tempx >= N || tempy < 0 || tempy >= N)
					continue;
				if (arr[tempx][tempy] > cost) {
					Node* next = new Node;
					arr[tempx][tempy] = cost;
					next->x = tempx;
					next->y = tempy;
					next->post_x = temp.x;
					next->post_y = temp.y;
					next->dist = -1*cost;
					pq.push(*next);
				}
			}
			size = pq.size();
		}
		cout << "#" << TC << " " << arr[N - 1][N - 1] << endl;
	}
}
