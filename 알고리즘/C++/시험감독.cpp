#include <iostream>
using namespace std;
int N, B, C;
int A[1000001];
long long solve() {
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		int rest = A[i];
		ans += 1;	//총감독관 플러스 1
		rest -= B;	//총감독관이 담당할 수 있는 인원수 만큼 마이너스
		if (rest > 0) {
			ans += rest / C;	//부감독관이 담당할 수 있는 인원수, 나머지는 현재 고려 안함
			ans = rest % C > 0 ? ans + 1 : ans;	//나머지가 존재한다면 1명을 추가한다.
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	cin >> B >> C;
	long long answer = solve();
	cout << answer << "\n";
}