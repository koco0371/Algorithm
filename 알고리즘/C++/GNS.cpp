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
		int N;
		string tt;
		cin >> tt >> N;
		int num[10] = { 0 };
		for (int i = 0; i < N; i++) {
			string temp;
			cin >> temp;
			if (temp == "ZRO") {
				num[0]++;
			}
			else if (temp == "ONE") {
				num[1]++;
			}
			else if (temp == "TWO") {
				num[2]++;
			}
			else if (temp == "THR") {
				num[3]++;
			}
			else if (temp == "FOR") {
				num[4]++;
			}
			else if (temp == "FIV") {
				num[5]++;
			}
			else if (temp == "SIX") {
				num[6]++;
			}
			else if (temp == "SVN") {
				num[7]++;
			}
			else if (temp == "EGT") {
				num[8]++;
			}
			else if (temp == "NIN") {
				num[9]++;
			}
		}
		cout << "#" << TC << " ";
		for (int i = 0; i < 10; i++) {
			while (num[i]) {
				switch (i) {
				case 0:
					cout << "ZRO ";
					break;
				case 1:
					cout << "ONE ";
					break;
				case 2:
					cout << "TWO ";
					break;
				case 3:
					cout << "THR ";
					break;
				case 4:
					cout << "FOR ";
					break;
				case 5:
					cout << "FIV ";
					break;
				case 6:
					cout << "SIX ";
					break;
				case 7:
					cout << "SVN ";
					break;
				case 8:
					cout << "EGT ";
					break;
				case 9:
					cout << "NIN ";
					break;
				}
				num[i]--;
			}
		}
		cout << endl;
	}
}