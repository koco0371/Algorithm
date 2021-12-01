#include <iostream>
using namespace std;
int N, B, C;
int A[1000001];
long long solve() {
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		int rest = A[i];
		ans += 1;	//�Ѱ����� �÷��� 1
		rest -= B;	//�Ѱ������� ����� �� �ִ� �ο��� ��ŭ ���̳ʽ�
		if (rest > 0) {
			ans += rest / C;	//�ΰ������� ����� �� �ִ� �ο���, �������� ���� ��� ����
			ans = rest % C > 0 ? ans + 1 : ans;	//�������� �����Ѵٸ� 1���� �߰��Ѵ�.
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