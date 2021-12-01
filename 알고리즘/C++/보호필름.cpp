#include <iostream>
using namespace std;
int map[13][20];
int copy_map[13][20];
int total[13];
int medicine[13];
bool visited[13];
int T, D, W, K;
int answer;
bool check_std();
bool insert_medi(int size);
bool DFS(int size);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	T++;
	for (int TC = 1; TC < T; TC++) {
		cin >> D >> W >> K;
		answer = K + 1;
		for (int i = 0; i < D; i++) {
			visited[i] = false;
			total[i] = -1;
			medicine[i] = -1;
			for (int j = 0; j < W; j++) {
				cin >> map[i][j];
				copy_map[i][j] = map[i][j];
			}
		}
		bool check = check_std();
		if (!check) {
			DFS(1);
		}
		else
			answer = 0;
		
		cout << "#" << TC << " " << answer << "\n";
	}
}

bool check_std() {
	int pass = 0;
	int num = 1;
	bool check = false;
	for (int j = 0; j < W; j++) {
		int before = copy_map[0][j];
		num = 1;
		check = false;
		for (int i = 1; i < D; i++) {
			if (before != copy_map[i][j]) {
				before = copy_map[i][j];
				num = 1;
			}
			else {
				num++;
			}
			if (num >= K) {
				pass++;
				check = true;
				num = 1;
				break;
			}
		}
		if (!check)
			return false;
	}
	if (pass == W)
		return true;
	else
		return false;
}

bool insert_medi(int size) {
	bool check = false;
	
	for (int i = 0; i < size; i++) {
		int k = total[i];
		for (int j = 0; j < W; j++) {
			copy_map[k][j] = medicine[i];
		}
	}
	
	check = check_std();
	for (int i = 0; i < size; i++) {
		int k = total[i];
		for (int j = 0; j < W; j++) {
			copy_map[k][j] = map[k][j];
		}
	}

	return check;
}
bool DFS(int size) {
	if (size >= answer)
		return false;
	bool check = false;
	int index = size - 1;
	int standard = -1;
	if (index > 0)
		standard = total[index - 1];
	for (int i = 0; i < D; i++) {
		if (!visited[i]) {
			if (standard > i)
				continue;
			check = false;
			total[index]=i;
			visited[i] = true;
			for (int j = 0; j < 2; j++) {
				medicine[index] = j;
				check = insert_medi(size);
				if (check) {
					answer = answer > size ? size : answer;
					break;
				}
				medicine[index]=-1;
			}
			total[index] = -1;
			visited[i] = false;
			if (size >= answer)
				return check;
		}
	}
	for (int i = 0; i < D; i++) {
		if (!visited[i]) {
			if (standard > i)
				continue;
			check = false;
			total[index] = i;
			visited[i] = true;
			for (int j = 0; j < 2; j++) {
				medicine[index] = j;
				check = DFS(size + 1);
				medicine[index] = -1;
			}
			total[index] = -1;
			visited[i] = false;
			if (size >= answer)
				return check;
		}
	}
	return check;
}