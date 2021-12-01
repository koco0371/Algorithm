#include <iostream>
#include <vector>
using namespace std;
int main() {
	int T;
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		int N;
		cin >> N;
		int op[4] = { 0 };
		for (int i = 0; i < 4; i++)
			cin >> op[i];
		int* num = new int[N];
		for (int i = 0; i < N; i++)
			cin >> num[i];
		vector<long> buf;
		vector<int*> op_buf;
		buf.push_back(num[0]);
		op_buf.push_back(op);
		for (int i = 1; i < N; i++) {	//N���� �ǿ����ڸ� ��� ����� ������ �ݺ�
			int size = buf.size();
			vector<long> temp;
			vector<int*> op_temp;
			for (int j = 0; j < size; j++) {	//���� ���� �ȿ� �ִ� �ǿ����ڿ� ���� �ݺ�
				long cur = buf[j];
				for (int k = 0; k < 4; k++) {
					int* oper = new int[N];
					for (int l = 0; l < 4; l++)
						oper[l] = op_buf[j][l];
					if (oper[k]) {
						oper[k]--;
						switch (k) {
						case 0:	// ���ϱ�
							temp.push_back(cur + num[i]);
							break;
						case 1:	//����
							temp.push_back(cur - num[i]);
							break;
						case 2:	//���ϱ�
							temp.push_back(cur * num[i]);
							break;
						case 3:	//������
							temp.push_back(cur / num[i]);
							break;
						}
						op_temp.push_back(oper);
					}
				}
			}
			buf = temp;
			op_buf = op_temp;
		}
		long max = -100000000;
		long min = 100000000;
		int size = buf.size();
		for (int i = 0; i < size; i++) {
			max = max < buf[i] ? buf[i] : max;
			min = min > buf[i] ? buf[i] : min;
		}
		long ans = max - min;
		cout << "#" << TC << " " << ans << endl;
	}
}