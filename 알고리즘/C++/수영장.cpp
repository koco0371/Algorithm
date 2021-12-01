#include <iostream>
#include <vector>
using namespace std;
int min_ans = 999999;
int DFS(int* fee, int* month, int sum, int cur_mon);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		int fee[4] = { 0 };	//1일 1달 3달 1년 이용권 금액
		int month[12] = { 0 };	//각 달 이용 계획
		min_ans = 999999;
		for (int i = 0; i < 4; i++) 
			cin >> fee[i];
		for (int i = 0; i < 12; i++)
			cin >> month[i];
		int ans = DFS(fee, month, 0, 0);
		cout << "#" << TC << " " << min_ans << endl;
	}
}
int DFS(int* fee, int* month, int sum, int cur_mon) {
	if (sum > min_ans)	//현재 최소값보다 커지면 들어가지 않는다.
		return 999999;
	if (cur_mon >= 12) {	//끝에 다다르면 비교 후 리턴한다.
		min_ans = sum < min_ans ? sum : min_ans;
		return min_ans;
	}
	while (!month[cur_mon])	//이용일자가 없는 달은 넘긴다.
		cur_mon++;
	if (cur_mon >= 12) {	//끝에 다다르면 비교 후 리턴한다.
		min_ans = sum < min_ans ? sum : min_ans;
		return min_ans;
	}
	int result = 999999;
	for (int i = 0; i < 4; i++) {	// 0-> 1일, 1-> 1달, 2-> 3달, 3-> 1년
		int temp;
		switch (i) {
		case 0:	// 1일
			sum += month[cur_mon] * fee[i];
			temp = DFS(fee, month, sum, cur_mon + 1);
			result = temp < result ? temp : result;
			sum -= month[cur_mon]*fee[i];
			break;
		case 1:	// 1달
			sum += fee[i];
			temp = DFS(fee, month, sum, cur_mon + 1);
			result = temp < result ? temp : result;
			sum -= fee[i];
			break;
		case 2:	// 3달
			sum += fee[i];
			temp = DFS(fee, month, sum, cur_mon + 3);
			result = temp < result ? temp : result;
			sum -= fee[i];
			break;
		case 3:	// 1년
			sum += fee[i];
			result = sum < result ? sum : result;
			min_ans = sum < min_ans ? sum : min_ans;
			sum -= fee[i];
			break;
		}
	}

	return result;
}