#include <iostream>
#include <cstring>
#include <set>
using namespace std;
int T, R, C;
char map[20][20];
bool answer = false;
bool cond = false;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1, -1,0,0 };
class Point {
public:
	int x = 0;
	int y = 0;
	int dir = 0;
	int mem = 0;
};
class Visit {
public:
	int x;
	int y;
	int count = 0;
	set<int> num;
};
Visit visited[20][20];
void DFS(Point cur, bool check, Visit** arr);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	T++;
	for (int TC = 1; TC < T; TC++) {
		cin >> R >> C;
		string temp;
		answer = false;
		Visit** mem = new Visit * [20];
		for (int i = 0; i < R; i++) {
			cin >> temp;
			mem[i] = new Visit[20];
			for (int j = 0; j < C; j++) {
				map[i][j] = temp[j];
				visited[i][j].x = i;
				visited[i][j].y = j;
				visited[i][j].num.clear();
				visited[i][j].count = 0;
				mem[i][j] = visited[i][j];
			}
		} 
		Point cur;
		DFS(cur, false, mem);
		string ans = answer ? "YES" : "NO";
		cout << "#" << TC << " " << ans << "\n";
	}
}
void DFS(Point cur, bool check, Visit** arr) {
	if (answer)	//종료가 되는것으로 판별되면 끝낸다
		return;
	if (cur.x < 0 || cur.x >= R || cur.y < 0 || cur.y >= C){
		if (cur.x < 0 || cur.x >= R) {
			cur.x = cur.x < 0 ? R - 1 : 0;
		}
		else {
			cur.y = cur.y < 0 ? C - 1 : 0;
		}
	}
	if (check) {	//?루프이므로 mem으로 체크
		int size = arr[cur.x][cur.y].num.size();
		arr[cur.x][cur.y].num.insert(cur.mem);
		if (size == arr[cur.x][cur.y].num.size()) {
			arr[cur.x][cur.y].count++;
			if(arr[cur.x][cur.y].count>2)
				return;
		}
	}
	else {	//visited에 같은 메모리 숫자가 들어오면 리턴
		int size = visited[cur.x][cur.y].num.size();
		visited[cur.x][cur.y].num.insert(cur.mem);
		arr[cur.x][cur.y].num.insert(cur.mem);
		if (size == visited[cur.x][cur.y].num.size()) {
			visited[cur.x][cur.y].count++;
			if (visited[cur.x][cur.y].count > 2)
				return;
		}
	}
	switch (map[cur.x][cur.y]) {
	case '>':
		cur.dir = 0;
		break;
	case '<':
		cur.dir = 1;
		break;
	case '^':
		cur.dir = 2;
		break;
	case 'v':
		cur.dir = 3;
		break;
	case '_':
		cur.dir = cur.mem == 0 ? 0 : 1;
		break;
	case '|':
		cur.dir = cur.mem == 0 ? 3 : 2;
		break;
	case '?':
		for (int i = 0; i < 4; i++) {
			
			Point temp;
			temp.x = cur.x + dx[i];
			temp.y = cur.y + dy[i];
			temp.dir = i;
			DFS(temp,  true, arr);
			
		}
		break;
	case '.':
		break;
	case '@':	//종료
		answer = true;
		break;
	case '+':
		cur.mem = cur.mem == 15 ? 0 : cur.mem + 1;
		break;
	case '-':
		cur.mem = cur.mem == 0 ? 15 : cur.mem - 1;
		break;
	default:	//숫자 케이스
		cur.mem = map[cur.x][cur.y] - '0';
	}
	if (map[cur.x][cur.y] != '?') {
		cur.x += dx[cur.dir];
		cur.y += dy[cur.dir];
		DFS(cur, check,arr);
	}
}