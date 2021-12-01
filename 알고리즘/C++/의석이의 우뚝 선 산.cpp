#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		int N;
		cin >> N;
		int* mountain = new int[N];
		for (int i = 0; i < N; i++) 
			cin >> mountain[i];
		int ans = 0;
		for (int i = 0; i < N; i++) {
			int count = 2;
			int start = i;
			int before = mountain[i];
			int max_i = -1;
			int end = i;
			while (count) {
				i++;
				if (i >= N && count == 2) {
					end = N;
					break;
				}
				else if (i >= N)
					break;
				switch (count) {
				case 2:	//이전의 값이 현재 값보다 작아야 함
					if (before > mountain[i]) {
						max_i = i - 1;
						if (max_i == start)
							count--;
						count--;
					}
					break;
				case 1: //이전의 값이 현재 값보다 커야 함.
					if (before < mountain[i]) 
						count--;
					break;
				}
				before = mountain[i];
			}
			if (end == N)
				continue;
			i--;
			end = i;
			if (end - start >= 2) {
				int rlen = end - max_i;
				int llen = max_i - start;
				ans += rlen * llen;
				i = end - 1;
			}
			else
				i = end;
		}
		cout << "#" << TC << " " << ans<< endl;
	}
}