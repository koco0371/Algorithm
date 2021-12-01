#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
	int len = s.length();
	vector<int> number;
	for (int i = 0; i < len; i++) {	//s 문자열의 숫자를 밝히는 반복문
		int cur = s[i] - '0';	
		if (cur > -1 && cur < 10) {//0을 빼서 나오는 숫자가 0-9 사이일 경우 숫자이므로 바로 number 벡터에 넣는다.
			number.push_back(cur);
			continue;
		}
		//0-9 사이가 아닐 경우 문자이므로 문자->숫자 변환을 위한 처리를 진행한다.
		string str = "";
		str += s[i];
		char next;
		switch (str[0]) {
		case 'z':	//0
			while (str != "zero") {
				i++;
				str += s[i];
			}
			number.push_back(0);
			break;
		case 'o':	//1
			while (str != "one") {
				i++;
				str += s[i];
			}
			number.push_back(1);
			break;
		case 't':	//2 or 3
			next = s[i + 1];
			if (next == 'w') {	//2
				while (str != "two") {
					i++;
					str += s[i];
				}
				number.push_back(2);
			}
			else {	//3
				while (str != "three") {
					i++;
					str += s[i];
				}
				number.push_back(3);
			}
			break;
		case 'f':	//4 or 5
			next = s[i + 1];
			if (next == 'o') {	//4
				while (str != "four") {
					i++;
					str += s[i];
				}
				number.push_back(4);
			}
			else {	//5
				while (str != "five") {
					i++;
					str += s[i];
				}
				number.push_back(5);
			}
			break;
		case 's':	//6 or 7
			next = s[i + 1];
			if (next == 'i') {	//6
				while (str != "six") {
					i++;
					str += s[i];
				}
				number.push_back(6);
			}
			else {	//7
				while (str != "seven") {
					i++;
					str += s[i];
				}
				number.push_back(7);
			}
			break;
		case 'e':	//8
			while (str != "eight") {
				i++;
				str += s[i];
			}
			number.push_back(8);
			break;
		case 'n':	//9
			while (str != "nine") {
				i++;
				str += s[i];
			}
			number.push_back(9);
			break;
		}
	}
	int answer = 0;
	len = number.size();
	for (int i = 0; i < len; i++) {
		answer *= 10;
		answer += number[i];
	}
	return answer;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	int ans = solution(s);
	cout << ans;
}