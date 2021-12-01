#include <iostream>
#include <string>
using namespace std;
int K;
class Gear {
public:
	int pole[8] = { 0 };
	bool visited = false;
};
//2번째(오른쪽 톱니), 6번째(왼쪽 톱니)
Gear gear_list[4];
void turn(int index, int direction) {
	if (direction == 1) {	//시계방향
		int last = gear_list[index].pole[7];
		int new_pole[8] = { 0 };
		new_pole[0] = last;
		for (int i = 0; i < 7; i++)
			new_pole[i + 1] = gear_list[index].pole[i];
		for (int i = 0; i < 8; i++)
			gear_list[index].pole[i] = new_pole[i];
	}
	else {	// 반시계 방향
		int first = gear_list[index].pole[0];
		int new_pole[8] = { 0 };
		for (int i = 1; i < 8; i++)
			new_pole[i - 1] = gear_list[index].pole[i];
		new_pole[7] = first;
		for (int i = 0; i < 8; i++)
			gear_list[index].pole[i] = new_pole[i];
	}
}
void turn_out(int index, int direction, int prev_pole, int prev_index) {
	if (index >= 4 || index < 0 || gear_list[index].visited) {
		return;
	}
	gear_list[index].visited = true;
	if (prev_pole == -1) {	//처음 돌아가는 톱니바퀴의 경우
		int second = gear_list[index].pole[2];
		int six = gear_list[index].pole[6];
		turn(index, direction);
		turn_out(index + 1, -direction, second, index);	//오른쪽 톱니바퀴
		turn_out(index - 1, -direction, six, index);		//왼쪽 톱니바퀴
	}
	else {	//처음 이후에 돌아가는 톱니바퀴
		int second = gear_list[index].pole[2];
		int six = gear_list[index].pole[6];
		if (prev_index > index) {	//이전 톱니바퀴가 현재보다 오른쪽에 존재
			if (prev_pole != second) {
				turn(index, direction);
				turn_out(index + 1, -direction, second, index);	//오른쪽 톱니바퀴
				turn_out(index - 1, -direction, six, index);		//왼쪽 톱니바퀴
			}
		}
		else {	//이전 톱니바퀴가 현재보다 왼쪽에 존재
			if (prev_pole != six) {
				turn(index, direction);
				turn_out(index + 1, -direction, second, index);	//오른쪽 톱니바퀴
				turn_out(index - 1, -direction, six, index);		//왼쪽 톱니바퀴
			}
		}
	}
}


int solve() {
	for (int i = 0; i < 4; i++) {
		string temp;
		cin >> temp;
		gear_list[i].visited = false;
		for (int j = 0; j < 8; j++)
			gear_list[i].pole[j] = temp[j] - '0';
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		int num, direction;
		cin >> num >> direction;
		turn_out(num - 1, direction, -1, -1);
		for (int j = 0; j < 4; j++)
			gear_list[j].visited = false;
	}
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		int temp = gear_list[i].pole[0];
		temp <<= i;
		ans += temp;
	}
	return ans;
}
int main() {
	int answer = solve();
	cout << answer << "\n";
}