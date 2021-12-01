#include <stdio.h>
#define INF 9223372036854775807
using namespace std;
class Point {
public:
	int x, y;
};
Point list[20];
int N, T;
long long int ans;
void DFS(int first_x, int second_x, int first_y, int second_y, int first, int second);
int main() {
	scanf("%d", &T);
	T++;
	for (int TC = 1; TC < T; TC++) {
		scanf("%d", &N);
		ans = INF;
		for (int i = 0; i < N; i++) {
			scanf("%d %d", &list[i].x, &list[i].y);
		}
		DFS(list[0].x, 0, list[0].y, 0, 1, 0);
		DFS(0, list[0].x, 0, list[0].y, 0, 1);
		printf("#%d %lld\n", TC, ans);
	}
}
void DFS(int first_x, int second_x, int first_y, int second_y, int first, int second) {
	int index = first + second;
	if (index == N) {
		long long int final_x = second_x - first_x;
		long long int final_y = second_y - first_y;
		long long int temp = final_x * final_x;
		temp += final_y * final_y;
		ans = temp < ans ? temp : ans;
		return;
	}
	if (first < N / 2)
		DFS(first_x + list[index].x, second_x, first_y + list[index].y, second_y, first + 1, second);
	if (second < N / 2)
		DFS(first_x, second_x + list[index].x, first_y, second_y + list[index].y, first, second + 1);
}