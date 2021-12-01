#include <iostream>
using namespace std;
int map[100][100];
int min_x;
int min;
class Point {
public:
	int x, y;
	int dir;	//1�� ��, 2�� ���� 3�� ������
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int TC = 1; TC < 11; TC++) {
		int a;
		cin >> a;
		int min_x = -1;
		int min = 99999999;
		Point start;
		start.x = 0;
		start.y = 0;
		start.dir = 1;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> map[i][j];
			}
		}
		for (int j = 0; j < 100; j++) {
			if (map[99][j]) {
				int count = 0;
				start.x = 99;
				start.y = j;
				start.dir = 1;
				while (start.x != 0) {
					count++;
					int tempx = start.x;
					int tempy = start.y;
					switch (start.dir) {
					case 1:	//�� --> �����̳� �����ʿ� 1�� �ִ��� üũ�ϰ� ������ ���� �ö�
						tempx = start.x;
						tempy = start.y - 1;
						//���� üũ
						if (tempx >= 0 && tempx < 100 && tempy >= 0 && tempy < 100) {
							if (map[tempx][tempy]) {
								start.dir = 2;
								start.x = tempx;
								start.y = tempy;
								break;
							}
						}
						tempy = start.y + 1;
						//������ üũ
						if (tempx >= 0 && tempx < 100 && tempy >= 0 && tempy < 100) {
							if (map[tempx][tempy]) {
								start.dir = 3;
								start.x = tempx;
								start.y = tempy;
								break;
							}
						}
						tempx = start.x - 1;
						tempy = start.y;
						if (tempx >= 0 && tempx < 100 && tempy >= 0 && tempy < 100) {
							if (map[tempx][tempy]) {
								start.x = tempx;
								start.y = tempy;
							}
						}
						break;
					case 2:	//���� --> ���� �˻��ϰ� 0�̸� ����
						tempx = start.x;
						tempy = start.y - 1;
						//���� üũ
						if (tempx >= 0 && tempx < 100 && tempy >= 0 && tempy < 100) {
							if (map[tempx][tempy]) {
								start.x = tempx;
								start.y = tempy;
								break;
							}
						}
						//�� üũ
						tempx = start.x - 1;
						tempy = start.y;
						if (tempx >= 0 && tempx < 100 && tempy >= 0 && tempy < 100) {
							if (map[tempx][tempy]) {
								start.x = tempx;
								start.y = tempy;
								start.dir = 1;
							}
						}
						break;
					case 3:	//������ --> ������ �˻��ϰ� 0�̸� ����
						tempx = start.x;
						tempy = start.y + 1;
						//������ üũ
						if (tempx >= 0 && tempx < 100 && tempy >= 0 && tempy < 100) {
							if (map[tempx][tempy]) {
								start.x = tempx;
								start.y = tempy;
								break;
							}
						}
						tempx = start.x - 1;
						tempy = start.y;
						if (tempx >= 0 && tempx < 100 && tempy >= 0 && tempy < 100) {
							if (map[tempx][tempy]) {
								start.x = tempx;
								start.y = tempy;
								start.dir = 1;
							}
						}
						break;
					}
				}
				if (count < min) {
					min = count;
					min_x = start.y;
				}
				else if (count == min) {
					min_x = min_x < start.y ? start.y : min_x;
				}
			}
		}
		cout << "#" << TC << " " << min_x << "\n";
	}
}