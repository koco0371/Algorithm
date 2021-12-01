#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
class Array {
public:
	int start_x, start_y;
	int row;
	int column;
	int size;
	bool operator>(const Array& n)const {
		if (size == n.size)
			return row > n.row;
		return size > n.size;
	}
	bool operator<(const Array& n)const {
		if (size == n.size)
			return row < n.row;
		return size < n.size;
	}
};
int map[100][100];
bool visited[100][100];
vector<Array> ans;
void find_array(Array* cur, int x, int y, int N);
int main() {
	int T;
	scanf("%d", &T);
	T++;
	for (int TC = 1; TC < T; TC++) {
		int N;
		scanf("%d", &N);
		ans.clear();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
				if (map[i][j])
					visited[i][j] = false;
				else
					visited[i][j] = true;
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) {
					Array* temp = new Array;
					temp->start_x = i;
					temp->start_y = j;
					find_array(temp, i, j, N);
					ans.push_back(*temp);
				}
			}
		}
		sort(ans.begin(), ans.end());
		int size = ans.size();
		printf("#%d %d", TC, size);
		
		for (int i = 0; i < size; i++) {
			printf("%d %d ", ans[i].row, ans[i].column);
		}
		printf("\n");
	}
}
void find_array(Array* cur, int x, int y, int N) {
	int row = 0;
	for (int i = x; i < N; i++) {
		if (map[i][y] == 0)
			break;
		row++;
	}
	int column = 0;
	for (int i = y; y < N; i++) {
		if (map[x][i] == 0)
			break;
		column++;
	}
	cur->row = row;
	cur->column = column;
	cur->size = row * column;
	for (int i = x; i < x + row; i++) {
		for (int j = y; j < y + column; j++) {
			visited[i][j] = true;
		}
	}

}