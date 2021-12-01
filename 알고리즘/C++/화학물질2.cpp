#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
class Array {
public:
	int row;
	int column;
	unsigned int sum;
	bool operator>(const Array& n)const {
		return row > n.row;
	}
	bool operator<(const Array& n)const {
		return row < n.row;
	}
};
int map[100][100];
bool visited[100][100];
unsigned int** dp;
int** connect;
vector<Array> ans;
vector<Array> used;
void find_array(Array* cur, int x, int y, int N);
Array find_order(int low, int high);
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
		int max = -1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) {
					Array* temp = new Array;
					find_array(temp, i, j, N);
					max = temp->row > max ? temp->row : max;
					max = temp->column > max ? temp->column : max;
					ans.push_back(*temp);
				}
			}
		}
		int size = ans.size();
		connect = new int* [max + 1];
		for (int i = 0; i < max + 1; i++) {
			connect[i] = new int[2];
			for (int j = 0; j < 2; j++)
				connect[i][j] = 0;
		}
		for (int i = 0; i < size; i++) {
			connect[ans[i].row][0] = ans[i].column;
			connect[ans[i].column][1] = ans[i].row;
		}
		used.clear();
		int ptr = 0;
		for (; !connect[ptr][0]; ptr++);
		for (; connect[ptr][1]; ptr = connect[ptr][1]);
		for (; connect[ptr][0]; ptr = connect[ptr][0])
		{
			Array* cur = new Array;
			cur->row = ptr;
			cur->column = connect[ptr][0];
			cur->sum = 0;
			used.push_back(*cur);
		}
		dp = new unsigned int* [size];
		for (int i = 0; i < size; i++) {
			dp[i] = new unsigned int[size];
		}
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				dp[i][j] = -1;
			}
		}
		Array min = find_order(0, size - 1);
		printf("#%d %d\n", TC, dp[0][size - 1]);
		delete connect;
		for (int i = 0; i < size; i++)
			delete dp[i];
		delete dp;
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
	cur->sum = 0;
	for (int i = x; i < x + row; i++) {
		for (int j = y; j < y + column; j++) {
			visited[i][j] = true;
		}
	}

}
Array find_order(int low, int high) {
	if (low == high) {
		dp[low][high] = 0;
		return used[low];
	}
	unsigned int min = INT32_MAX;
	Array ret;
	for (int i = low; i < high; i++) {
		Array a;
		Array b;
		if(dp[low][i]==-1)
			a = find_order(low, i);
		else {
			a.row = used[low].row;
			a.column = used[i].column;
			a.sum = dp[low][i];
		}
		if (dp[i + 1][high] == -1) {
			b = find_order(i + 1, high);
		}
		else {
			b.row = used[i + 1].row;
			b.column = used[high].column;
			b.sum = dp[i + 1][high];
		}
		Array c;
		c.row = a.row;
		c.column = b.column;
		c.sum = a.sum + b.sum + a.row * b.row * b.column;
		if (c.sum < min) {
			ret.row = c.row;
			ret.column = c.column;
			ret.sum = c.sum;
			min = c.sum;
		}
	}
	if (dp[low][high] == -1)
		dp[low][high] = ret.sum;
	else
		dp[low][high] = ret.sum < dp[low][high] ? ret.sum : dp[low][high];
	return ret;
}