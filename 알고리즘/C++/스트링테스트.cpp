#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
	string test[3] = { "just1 test1", "just2 test2", "just3 test3" };
	string strbuf[6];
	int buf_idx = 0;
	for (int i = 0; i < 3; i++) {
		istringstream as(test[i]);
		for (int j = 0; j < 2; j++) {
			getline(as, strbuf[buf_idx], ' ');
			buf_idx++;
		}
	}
	for (int i = 0; i < 6; i++)
		cout << strbuf[i] << "\n";
}