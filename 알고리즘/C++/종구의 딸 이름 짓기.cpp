#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		int N, M;
		cin >> N >> M;
		string* map = new string[N];
		string* before = new string[M];
		string now = "";
		for (int i = 0; i < N; i++) {
			cin >> map[i];
			if (i == 0) {
				for (int j = 0; j < M; j++) {
					now += map[i][j];
					before[j] = now;
				}
			}
		}
		string cur = "";	//현재 줄 이전 상태를 나타냄
		string temp[2] = { "" };
		
		if (N > 1) {
			for (int i = 1; i < N; i++) {
				for (int j = 0; j < M; j++) {
					int count = 0;
					if (before[j] != "") {
						temp[count] = before[j];
						count++;
					}
					if (j > 0 && cur != "") {
						temp[count] = cur;
						count++;
					}
					if (count == 2) {
						if (temp[0].compare(temp[1]) < 0) {
							temp[0] += map[i][j];
							cur = temp[0];
							before[j - 1] = "";
						}
						else {
							temp[1] += map[i][j];
							cur = temp[1];
						}
					}
					else if(count==1) {	//비교 대상이 1가지
						cur = temp[0] + map[i][j];
					}
					else {	//비교 대상이 없음
						cur = "";
					}
					before[j] = cur;
				}
			}
			cout << "#" << TC << " " << cur << endl;
		}
		else {
			cout << "#" << TC << " " << before[M - 1] << endl;
		}
	}
}