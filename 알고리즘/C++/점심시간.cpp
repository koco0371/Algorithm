#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Point {
public:
	int x, y;
};
class Stair {
public:
	Point location;
	int length;
	int capacity;
	int timer[3] = { -1, -1, -1 };
};
int min_ans = 999999;
void Simulate(Stair* stair, vector<Point> set1, vector<Point> set2, int N);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		int N;
		cin >> N;
		min_ans = 999999;
		int** map = new int*[N];
		vector<Point> people;
		Stair stair[2];
		int count = 0;
		for (int i = 0; i < N; i++) {
			map[i] = new int[N];
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				int temp = map[i][j];
				if (temp == 1) {
					Point person;
					person.x = i;
					person.y = j;
					people.push_back(person);
				}
				else if (temp > 1) {
					stair[count].location.x = i;
					stair[count].location.y = j;
					stair[count].length = temp;
					stair[count].capacity = 0;
					count++;
				}
			}
		}
		vector<Point> set1;
		vector<Point> set2;
		int size = people.size();
		for (int i = 0; i < size; i++) {	//가까운 것부터 방문 하도록 greedy 하게 근처 값을 찾음
			int dist1 = abs(people[i].x - stair[0].location.x) + abs(people[i].y - stair[0].location.y);
			int dist2 = abs(people[i].x - stair[1].location.x) + abs(people[i].y - stair[1].location.y);
			if (dist1 < dist2)
				set1.push_back(people[i]);
			else
				set2.push_back(people[i]);
		}
		Simulate(stair, set1, set2, N);
		set1.clear();
		set2.clear();
		size = pow(2, N);
		for (int i = 0; i < size; i++) {
			int temp = i;
			int j = 0;
			while (temp) {
				int standard = 1;
				int result = standard & temp;
				if (result) {
					set1.push_back(people[j]);
				}
				else {
					set2.push_back(people[j]);
				}
				j++;
				temp >>= 1;
			}
			int p_size = people.size();
			while (j < p_size) {
				set2.push_back(people[j]);
				j++;
			}
			Simulate(stair, set1, set2, N);
			set1.clear();
			set2.clear();
		}
		cout << "#" << TC << " " << min_ans << endl;
	}
}
void Simulate(Stair* stair, vector<Point> set1, vector<Point> set2, int N) {
	int time = 1;
	bool check = true;
	while (check) {
		time++;
		if (time > min_ans)
			break;
		int size1 = set1.size();
 		if (stair[0].capacity) {	//현재 채워져 있을 경우, 해당 번호까지 timer를 증가 시킨다.
			for (int i = 0; i < 3; i++) {
				if (stair[0].timer[i] != -1)
					stair[0].timer[i]++;
				if (stair[0].timer[i] >= stair[0].length) {
					stair[0].timer[i] = -1;
					stair[0].capacity--;
				}
			}
		}
		if (stair[1].capacity) {
			for (int i = 0; i < 3; i++) {
				if (stair[1].timer[i] != -1)
					stair[1].timer[i]++;
				if (stair[1].timer[i] >= stair[1].length) {
					stair[1].timer[i] = -1;
					stair[1].capacity--;
				}
			}
		}
		for (int i = 0; i < size1; i++) {	// 1번 계단으로 향하는 집합
			if (set1[i].x != stair[0].location.x && set1[i].y!=stair[0].location.y) {	// 좌표가 모두 다르다면, x좌표부터 이동한다.
				if (set1[i].x > stair[0].location.x)
					set1[i].x--;
				else
					set1[i].x++;
			}
			else if (set1[i].x != stair[0].location.x && set1[i].y == stair[0].location.y) {	//y좌표가 같고 x좌표가 다르면 x좌표를 이동한다.
				if (set1[i].x > stair[0].location.x)
					set1[i].x--;
				else
					set1[i].x++;
			}
			else if (set1[i].x == stair[0].location.x && set1[i].y != stair[0].location.y) {	//x좌표가 같고 y좌표가 다르면 y좌표를 이동한다.
				if (set1[i].y > stair[0].location.y)
					set1[i].y--;
				else
					set1[i].y++;
			}
			if (set1[i].x == stair[0].location.x&&set1[i].y == stair[0].location.y) {	//위치가 같으면 stair가 꽉차있는지 확인하고, 차있지 않다면 진입한 후, set에서 삭제한다.
				if (stair[0].capacity < 3) {
					for (int j = 0; j < 3; j++) {
						if (stair[0].timer[j] == -1) {
							stair[0].timer[j] = 0;
							break;
						}
					}
					stair[0].capacity++;
					vector<Point>::iterator itr;
					itr = set1.begin();
					itr += i;
					set1.erase(itr);
					i--;
					size1 = set1.size();
				}
			}
		}
		int size2 = set2.size();
		for (int i = 0; i < size2; i++) {	// 2번 계단으로 향하는 집합
			
			if (set2[i].x != stair[1].location.x && set2[i].y != stair[1].location.y) {	// 좌표가 모두 다르다면, x좌표부터 이동한다.
				if (set2[i].x > stair[1].location.x)
					set2[i].x--;
				else
					set2[i].x++;
			}
			else if (set2[i].x != stair[1].location.x && set2[i].y == stair[1].location.y) {
				if(set2[i].x > stair[1].location.x)
					set2[i].x--;
				else
					set2[i].x++;
			}
			else if (set2[i].x == stair[1].location.x && set2[i].y != stair[1].location.y) {	//x좌표가 같고 y좌표가 다르면 y좌표를 이동한다.
				if (set2[i].y > stair[1].location.y)
					set2[i].y--;
				else
					set2[i].y++;
			}
			if (set2[i].x == stair[1].location.x&&set2[i].y == stair[1].location.y) {	//위치가 같으면 stair가 꽉차있는지 확인하고, 차있지 않다면 진입한 후, set에서 삭제한다.
				if (stair[1].capacity < 3) {
					for (int j = 0; j < 3; j++) {
						if (stair[1].timer[j] == -1) {
							stair[1].timer[j] = 0;
							break;
						}
					}
					stair[1].capacity++;
					vector<Point>::iterator itr;
					itr = set2.begin();
					itr += i;
					set2.erase(itr);
					i--;
					size2 = set2.size();
				}
			}
		}
		if (size1 == 0 && size2 == 0 && stair[0].capacity == 0 && stair[1].capacity == 0)
			check = false;
	}
	min_ans = time < min_ans ? time : min_ans;
	return;
}