#include <iostream>
#include <vector>
#define MAX 987654321
using namespace std;
int combi[20][20];
int N;
int min_diff = MAX;
void solution(vector<int> A, int cur) {
	if (cur >= N)
		return;
	int size = A.size();
	if (size >= N / 2) {
		int total_A = 0;
		int total_B = 0;
		vector<int> B;
		for (int i = 0; i < N; i++) {
			bool check = false;
			for (int j = 0; j < size; j++) {
				if (A[j] == i) {
					check = true;
					break;
				}
			}
			if (!check)
				B.push_back(i);
		}
		for (int i = 0; i < size; i++) {
			for (int j = i; j < size; j++) {
				int x = A[i];
				int y = A[j];
				total_A += combi[x][y];
				total_A += combi[y][x];
				x = B[i];
				y = B[j];
				total_B += combi[x][y];
				total_B += combi[y][x];
			}
		}
		int diff = abs(total_B - total_A);
		min_diff = diff < min_diff ? diff : min_diff;
		return;
	}
	//포함하는 경우 포함하지 않는 경우로 나눔
	A.push_back(cur);
	solution(A, cur + 1);
	A.pop_back();
	solution(A, cur + 1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			combi[i][j] = temp;
		}
	}
	vector<int> A;
	int cur = 0;
	solution(A, cur);
	cout << min_diff;
}