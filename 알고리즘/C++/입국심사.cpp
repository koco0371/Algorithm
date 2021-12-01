#include <iostream>
using namespace std;
class Judge {
public:
	int time;
	bool operator>(const Judge& n) const {
		return time > n.time;
	}
	bool operator<(const Judge& n)const {
		return time < n.time;
	}
};
Judge list[100000];
int N, M;
long long int binary_search(long long int low, long long int high);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	T++;
	for (int TC = 1; TC < T; TC++) {
		cin >> N >> M;
		long long int max = -1;
		for (int i = 0; i < N; i++) {
			cin >> list[i].time;
			max = max < list[i].time ? list[i].time : max;
		}
		long long int ans = binary_search(1, max * M);
		cout << "#" << TC << " " << ans << "\n";
	}
}
long long int binary_search(long long int low, long long int high) {
	long long int mid = (low + high) / 2;
	if (low == high)
		return low;
	if (low < high) {
		long long int sum = 0;
		for (int i = 0; i < N; i++) {
			sum += mid / list[i].time;
		}
		long long int ans = low;
		if (sum < M) {
			ans = binary_search(mid + 1, high);
		}
		else {
			ans = binary_search(low, mid);
		}
		return ans;
	}
}