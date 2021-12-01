#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
class Island {
public:
	int num;
	long long int x, y;
	bool visit;
};
double map[1000][1000];
double prim(Island* list, vector<int> select, double total, int N, double E);
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
		Island* list = new Island[N];
		memset(map, 0, sizeof(map));
		for (int i = 0; i < N; i++) {
			long long int x;
			cin >> x ;
			list[i].num = i;
			list[i].x = x;
			list[i].visit = false;
		}
		for (int i = 0; i < N; i++) {
			long long int y;
			cin >> y;
			list[i].y = y;
		}
		double E;
		cin >> E;
		vector<int> temp;
		temp.push_back(0);
		list[0].visit = true;
		double ans = 0;
		ans = prim(list, temp, ans, N, E);
		long long int answer = ans + 0.5;
		cout << "#" << TC << " " << answer << endl;
	}
}
double prim(Island* list, vector<int> select, double total, int N, double E) {
	int size = select.size();
	if (size == N)
		return total;
	double min = -1;
	int min_i = -1;
	for (int i = 0; i < size; i++) {
		int cur = select[i];
		for (int j = 0; j < N; j++) {
			if (!list[j].visit) {
				if (map[cur][j] == 0) {
					double len = pow(list[cur].x - list[j].x, 2) + pow(list[cur].y - list[j].y, 2);
					len *= E;
					map[cur][j] = len;
					map[j][cur] = len;
					if (min == -1) {
						min = len;
						min_i = j;
					}
					else {
						if (len < min) {
							min = len;
							min_i = j;
						}
					}
				}
				else {
					if (min == -1) {
						min = map[cur][j];
						min_i = j;
					}
					else {
						if (map[cur][j] < min) {
							min = map[cur][j];
							min_i = j;
						}
					}
				}
			}
		}
	}
	select.push_back(min_i);
	list[min_i].visit = true;
	total += min;
	total = prim(list, select, total, N, E);
	return total;
}