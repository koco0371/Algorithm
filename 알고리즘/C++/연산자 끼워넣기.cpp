#include <iostream>
#define MAX_NUM 987654321
#define MIN_NUM -98765432
using namespace std;
int N;
int A[11];
int plus_num, min_num, mul_num, div_num;
int min_ans;
int max_ans;
void DFS(int index, int cur, int plus_n, int min_n, int mul_n, int div_n) {
	if (index >= N) {
		min_ans = min_ans > cur ? cur : min_ans;
		max_ans = max_ans < cur ? cur : max_ans;
		return;
	}
	else {
		for (int i = 0; i < 4; i++) {
			switch (i) {
			case 0:
				if(plus_n)
					DFS(index + 1, cur + A[index], plus_n - 1, min_n, mul_n, div_n);
				break;
			case 1:
				if(min_n)
					DFS(index + 1, cur - A[index], plus_n, min_n - 1, mul_n, div_n);
				break;
			case 2:
				if(mul_n)
					DFS(index + 1, cur * A[index], plus_n, min_n, mul_n - 1, div_n);
				break;
			case 3:
				if(div_n)
					DFS(index + 1, cur / A[index], plus_n, min_n, mul_n, div_n - 1);
				break;
			}
		}
		return;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	min_ans = MAX_NUM;
	max_ans = MIN_NUM;
	for (int i = 0; i < N; i++) 
		cin >> A[i];
	cin >> plus_num >> min_num >> mul_num >> div_num;
	DFS(1, A[0], plus_num, min_num, mul_num, div_num);
	cout << max_ans <<"\n"<< min_ans << "\n";
}