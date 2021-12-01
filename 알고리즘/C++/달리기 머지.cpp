#include <stdio.h>
using namespace std;
class Runner {
public:
	int num;
	int index;
};
Runner *list;
Runner* arr;
int* mem;
void partition(int low, int high);
void merge(int low, int high);
int main() {
	int N;
	scanf("%d", &N);
	arr = new Runner[N];
	list = new Runner[N];
	mem = new int[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &list[i].num);
		list[i].index = i;
		mem[i] = i + 1;
	}
	partition(0, N - 1);
	for (int i = 0; i < N; i++) {
		printf("%d\n", mem[i]);
	}
}
void partition(int low, int high) {
	if (low < high) {
		int mid = (low + high + 1) / 2;
		partition(low, mid - 1) ;
		partition(mid, high);
		merge(low, high);
	}
}
void merge(int low, int high) {
	if (low > high) return;
	int mid = (low + high + 1) / 2;
	int i = low;
	int j = mid;
	int k = low;
	while (i < mid && j <= high) {
		if (list[i].num > list[j].num) {
			arr[k++] = list[i++];
		}
		else {
			arr[k++] = list[j];
			mem[list[j++].index]-= mid - i;
		}
	}
	while (i < mid)	arr[k++] = list[i++];
	while (j <= high) arr[k++] = list[j++];
	for (int i = low; i <= high; i++) {
		list[i] = arr[i];
	}
}