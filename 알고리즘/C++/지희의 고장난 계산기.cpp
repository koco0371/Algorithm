#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;
int min_ans = -1;
int num[10] = { 0 };
int find_num(set<int> ans, int len, int result);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		string number="";
		for (int i = 0; i < 10; i++) {
			int temp;
			cin >> temp;
			num[i] = temp;
			if (temp)
				number += i + '0';
		}
		string target="";
		cin >> target;
		min_ans = -1;
		int size = number.length();
		int* use_number = new int[size];
		for (int i = 0; i < size; i++) 
			use_number[i] = number[i] - '0';
		size = target.length();
		int purpose = atoi(target.c_str());
		int* target_num = new int[size];
		for (int i = 0; i < size; i++)
			target_num[i] = target[i] - '0';
		bool check = true;
		for (int i = 0; i < size; i++) {
			int temp = target_num[i];
			if (!num[temp]) {
				check = false;
				break;
			}
		}
		if (check) {
			min_ans = size + 1;
			cout << "#" << TC << " " << min_ans << endl;
			continue;
		}
		set<int> ans;
		vector<int> buf;
		size = number.length();
		for (int i = 0; i < size; i++) {
			if (use_number[i]) {
				ans.insert(use_number[i]);
				buf.push_back(use_number[i]);
			}
		}
		check = true;
		while (check) {
			vector<int> next;
			for (auto n : buf) {
				string temp = "";
				temp += to_string(n);
				for (int i = 0; i < size; i++) {
					string new_temp = temp;
					new_temp += use_number[i] + '0';
					int mem = atoi(new_temp.c_str());
					if (mem < purpose)
						next.push_back(mem);
					else {
						check = false;
						break;
					}
				}
				if (!check)
					break;
			}
			int len = next.size();
			buf.clear();
			for (int i = 0; i < len; i++) {
				ans.insert(next[i]);
				buf.push_back(next[i]);
			}
			if (!check)
				break;
			
		}
		set<int>::iterator itr = ans.begin();
		size = ans.size();
		for (int i = 0; i < size; i++) {
			if (purpose%*itr != 0 || *itr == 1) {
				itr = ans.erase(itr);
			}
			else
				itr++;
		}
		for (auto n : ans) {
			if (purpose%n == 0) {
				int result = purpose / n;
				string temp = "";
				temp += to_string(n);
				int len = temp.length() + 2;
				check = true;
				temp = to_string(result);
				size = temp.length();
				for (int i = 0; i < size; i++) {
					int mem = temp[i] - '0';
					if (!num[mem]) {
						check = false;
						break;
					}
				}
				if (check) {
					int result_len = len;
					len += temp.length();
					if (min_ans != -1)
						min_ans = len < min_ans ? len : min_ans;
					else
						min_ans = len;
				}
				else {
					min_ans = find_num(ans, len, result);
				}
			}
		}
		cout << "#" << TC << " " << min_ans << endl;
	}
}
int find_num(set<int> ans, int len, int result) {
	if (min_ans != -1 && len > min_ans)
		return min_ans;
	if (result == 0) {
		min_ans = len < min_ans ? len : min_ans;
		return min_ans;
	}
	bool check;
	
	for (auto l : ans) {
		if (result%l == 0) {
			result /= l;
			string temp = "";
			temp += to_string(l);
			len += temp.length() + 1;
			check = true;
			temp = to_string(result);
			int size = temp.length();
			for (int i = 0; i < size; i++) {
				int mem = temp[i] - '0';
				if (!num[mem]) {
					check = false;
					break;
				}
			}
			if (check) {
				int result_len = len;
				len += temp.length();
				if (min_ans != -1)
					min_ans = len < min_ans ? len : min_ans;
				else
					min_ans = len;
				return min_ans;
			}
			else {
				min_ans = find_num(ans, len, result);
			}
			temp = to_string(l);
			len -= temp.length() + 1;
			result *= l;
		}
	}
	return min_ans;
}