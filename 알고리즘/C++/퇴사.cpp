#include <iostream>
#include <vector>
using namespace std;
int N;
int arr[15][2];
int max_total = -1;
void solution(vector<int> talk, int cur, int time) {
	if (cur >= N) {	//cur의 크기가 N과 같으면 탈출
		int size = talk.size();
		int total = 0;
		for (int i = 0; i < size; i++)
			total += arr[talk[i]][1];
		max_total = total > max_total ? total : max_total;
		return;
	}
	//cur을 포함하는 경우와 포함하지 않는 경우로 나누어 진행한다.
	//time이 0일 때만 진행한다.
	if (time == 0) {
		//cur을 포함하는 경우, 단, cur+time이 N을 넘으면 포함하지 않는다.
		int time = arr[cur][0];
		if (cur + time <= N) {
			talk.push_back(cur);
			solution(talk, cur + 1, time - 1);
			talk.pop_back();
		}
		//cur을 포함하지 않는 경우
		time = 0;
		solution(talk, cur + 1, time);
	}
	else {//time이 0이 아니므로 다음으로 넘긴다.
		solution(talk, cur + 1, time - 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int T, P;
		cin >> T >> P;
		arr[i][0] = T;
		arr[i][1] = P;
	}
	vector<int> talk;
	int cur = 0;
	int time = 0;
	solution(talk, cur, time);
	cout << max_total;
}