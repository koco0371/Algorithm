#include <iostream>
#include <string>
#include <set>
using namespace std;
bool compare(string a, string b) {
	return a < b;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	T++;
	for (int TC = 1; TC < T; TC++) {
		int K;
		cin >> K;
		string data;
		cin >> data;
		set<string> ans;
		int len = data.length();
		for (int i = 0; i <= len; i++) {
			for (int j = 0; j < len; j++) {
				int k = i;
				int l = j;
				string temp = "";
				if (j + k <= len) {
					while (k) {
						temp += data[l++];
						k--;
					}
					if(temp!="")
						ans.insert(temp);
				}
			}
		}
		int size = ans.size();
		if (size < K) {
			cout << "#" << TC << " " << "none" << endl;
			continue;
		}
		set<string>::iterator itr;
		itr = ans.begin();
		K--;
		for (int i = 0; i < K; i++) itr++;
		cout << "#" << TC << " " << *itr << endl;
	}
}