#include <iostream>
#include <vector>
using namespace std;
int N;
int arr[15][2];
int max_total = -1;
void solution(vector<int> talk, int cur, int time) {
	if (cur >= N) {	//cur�� ũ�Ⱑ N�� ������ Ż��
		int size = talk.size();
		int total = 0;
		for (int i = 0; i < size; i++)
			total += arr[talk[i]][1];
		max_total = total > max_total ? total : max_total;
		return;
	}
	//cur�� �����ϴ� ���� �������� �ʴ� ���� ������ �����Ѵ�.
	//time�� 0�� ���� �����Ѵ�.
	if (time == 0) {
		//cur�� �����ϴ� ���, ��, cur+time�� N�� ������ �������� �ʴ´�.
		int time = arr[cur][0];
		if (cur + time <= N) {
			talk.push_back(cur);
			solution(talk, cur + 1, time - 1);
			talk.pop_back();
		}
		//cur�� �������� �ʴ� ���
		time = 0;
		solution(talk, cur + 1, time);
	}
	else {//time�� 0�� �ƴϹǷ� �������� �ѱ��.
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