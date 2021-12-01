#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <vector>
#include <cstring>
#define INF 987654321
using namespace std;
class Man {
public:
	int num;
	vector<Man*> next;
	int dist;
};
Man* network;
bool visited[1001];
int** map;
int main() {
	int T;
	scanf("%d", &T);
	T++;
	for (int TC = 1; TC < T; TC++) {
		int N;
		scanf("%d", &N);
		map = new int* [N];
		network = new Man[N];
		for (int i = 0; i < N; i++) {
			network[i].num = i;
			network[i].dist = 0;
		}
		for (int i = 0; i < N; i++) {
			map[i] = new int[N];
			
			visited[i] = false;
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
				if (map[i][j]) {
					network[i].next.push_back(&network[j]);
				}
			}
		}
		queue<Man> pq;
		int min_ans = 987654321;
		bool check = false;
		int temp = 0;
		for (int i = 0; i < N; i++) {
			int sum = 0;
			if (!check) {
				pq.push(network[i]);
				visited[i] = true;
				int size = pq.size();
				while (size) {
					Man temp = pq.front();
					pq.pop();
					int next_size = temp.next.size();
					for (int j = 0; j < next_size; j++) {
						int next = temp.next[j]->num;
						if (!visited[next]) {
							temp.next[j]->dist = -(-temp.dist + 1);
							visited[next] = true;
							sum += -temp.next[j]->dist;
							if (sum > min_ans) {
								while (!pq.empty())
									pq.pop();
								break;
							}

							map[temp.num][next] = min(map[temp.num][next],-temp.next[j]->dist);
							map[next][temp.num] = -temp.next[j]->dist;
							pq.push(network[next]);
						}
					}
					size = pq.size();
				}
			}
			else {
				sum = temp;
			}
			min_ans = sum < min_ans ? sum : min_ans;
			temp = 0;
			if (i + 1 < N) {
				for (int j = 0; j < N; j++) {
					if (i + 1 != j) {
						if (map[i + 1][j]) {
							temp += map[i + 1][j];
						}
						else
							check = false;
					}
					network[j].dist = 0;
					visited[j] = false;
				}
			}
		}
		printf("#%d %d\n", TC, min_ans);
	}
}