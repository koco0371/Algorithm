#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;
class Runner {
public:
	int index;
	int num;
	bool operator> (const Runner& n)const {
		return num > n.num;
	}
	bool operator<(const Runner& n)const {
		return num < n.num;
	}
};
Runner list[500000];
int* IDT;
int level;
bool compare(Runner a, Runner b) {
	return a.index < b.index;
}
void update(int a, int b)
{
	a = pow(2, level) + a;
	IDT[a] = b;
	a >>= 1;
	while (a)
	{
		IDT[a] = IDT[2 * a] + IDT[2 * a + 1];
		a >>= 1;
	}
}
int query(int a, int b) {
	int sum = 0;
	a = pow(2, level) + a;
	b = pow(2, level) + b;
	while (a < b)
	{
		if (a % 2 == 1) sum += IDT[a], a++;
		if (b % 2 == 0) sum += IDT[b], b--;
		a >>= 1, b >>= 1;
	}
	if (a == b) sum += IDT[a];
	return sum;

}
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &list[i].num);
		list[i].index = i;
	}
	sort(list, list + N);
	for (int i = 0; i < N; i++)
		list[i].num = i;
	int sum = 0;
	int standard = 2;
	level = 0;
	for (int i = 1; i < N; i <<= 1) {
		sum += i;
		standard <<= 1;
		level++;
	}
	sum += standard;
	IDT = new int[sum];
	for (int i = 0; i < sum; i++) IDT[i] = 0;
	sort(list, list + N, compare);
	for (int i = 0; i < N; i++) {
		printf("%d\n", list[i].index - query(0, list[i].num) + 1);
		update(list[i].num, 1);
	}
	delete IDT;
}
