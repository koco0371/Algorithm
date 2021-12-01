#include <iostream>
#include <set>
#include <string>
#include <cmath>
using namespace std;
int T, N, K;
string number;
int myatoi(char* target, int size);
int main() {
	ios_base::sync_with_stdio(false);
	cin >> T;
	T++;
	for (int TC = 1; TC < T; TC++) {
		cin >> N >> K;
		cin >> number;
		int standard = N / 4;
		set<int> answers;
		char* tmp = new char[standard];
		for (int i = 0; i < standard; i++) {	//모든 루프 횟수(한 변의 숫자만큼 돌아야 모든 조합 완성) & 시작 위치
			int count = 0;	//집합 전체를 돌았는지 체크하는 변수
			int index = i;	//집합을 도는 인덱스로 사용할 변수
			while (count < N) {
				for (int j = 0; j < standard; j++) {
					tmp[j] = number[index];
					index++;
					count++;
					if (index == N)
						index = 0;
				}
				int combi = myatoi(tmp,standard);
				answers.insert(combi);
			}
		}
		set<int>::iterator itr;
		itr = answers.end();
		for (int i = 0; i < K; i++)
			itr--;
		int answer = *itr;
		cout << "#" << TC << " " << answer << "\n";
	}
}
int myatoi(char* target, int size) {
	int ret = 0;
	for (int i = 0; i < size; i++) {
		ret *= 16;
		int num = 0;
		switch (target[i]) {
		case 'A':
			num = 10;
			break;
		case 'B':
			num = 11;
			break;
		case 'C':
			num = 12;
			break;
		case 'D':
			num = 13;
			break;
		case 'E':
			num = 14;
			break;
		case 'F':
			num = 15;
			break;
		default:
			num = target[i] - '0';
			break;
		}
		ret += num;
	}
	return ret;
}