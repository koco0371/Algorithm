//#include <iostream>
//#include <queue>
//
//using namespace std;
//#define N 50
//#define M 50
//
//int dx[4] = { -1,1,0,0 };      //��, ��, ��, ��
//int dy[4] = { 0,0,-1,1 };
//
//int a[N][M];
//int n, m, r, c, l;
//
//int check[N][M];
//int main()
//{
//    
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//
//    int tNum = 0, tc;
//    cin >> tc;
//
//    while (tNum < tc)
//    {
//        tNum++;
//        cin >> n >> m >> r >> c >> l;
//
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < m; j++)
//            {
//                cin >> a[i][j];
//                check[i][j] = 0;
//            }
//        }
//
//        queue<pair<int, int> > q;
//        check[r][c] = 1;
//        q.push(make_pair(r, c));
//        int result = 1;
//
//        while (!q.empty())
//        {
//            //result++;
//            int x = q.front().first;
//            int y = q.front().second;
//            q.pop();
//
//            int tType = a[x][y];
//
//            switch (tType)
//            {
//            case 1:   //��,��,��,��
//            {
//                for (int i = 0; i < 4; i++)
//                {
//                    int ndx = x + dx[i];
//                    int ndy = y + dy[i];
//                    if (0 <= ndx && ndx < n && 0 <= ndy && ndy < m && !check[ndx][ndy])
//                    {
//                        int ntType = a[ndx][ndy];
//                        if (i == 0)   //��
//                        {
//                            if (ntType == 1 || ntType == 2 || ntType == 5 || ntType == 6)
//                            {
//                                check[ndx][ndy] = check[x][y] + 1;
//                                if (check[ndx][ndy] <= l)
//                                {
//                                    q.push(make_pair(ndx, ndy));
//                                    result++;
//                                }
//
//                            }
//                        }
//                        else if (i == 1) //��
//                        {
//                            if (ntType == 1 || ntType == 2 || ntType == 4 || ntType == 7)
//                            {
//                                check[ndx][ndy] = check[x][y] + 1;
//                                if (check[ndx][ndy] <= l)
//                                {
//                                    q.push(make_pair(ndx, ndy));
//                                    result++;
//                                }
//                            }
//                        }
//                        else if (i == 2)   //��
//                        {
//                            if (ntType == 1 || ntType == 3 || ntType == 4 || ntType == 5)
//                            {
//                                check[ndx][ndy] = check[x][y] + 1;
//                                if (check[ndx][ndy] <= l)
//                                {
//                                    q.push(make_pair(ndx, ndy));
//                                    result++;
//                                }
//                            }
//                        }
//                        else if (i == 3)   //��
//                        {
//                            if (ntType == 1 || ntType == 3 || ntType == 6 || ntType == 7)
//                            {
//                                check[ndx][ndy] = check[x][y] + 1;
//                                if (check[ndx][ndy] <= l)
//                                {
//                                    q.push(make_pair(ndx, ndy));
//                                    result++;
//                                }
//                            }
//                        }
//
//                    }
//                }
//                break;
//            }
//            case 2:   //��,��
//            {
//                for (int i = 0; i < 2; i++)
//                {
//                    int ndx = x + dx[i];
//                    int ndy = y + dy[i];
//
//                    if (0 <= ndx && ndx < n && 0 <= ndy && ndy < m && !check[ndx][ndy])
//                    {
//                        int ntType = a[ndx][ndy];
//                        if (i == 0)   //��
//                        {
//                            if (ntType == 1 || ntType == 2 || ntType == 5 || ntType == 6)
//                            {
//                                check[ndx][ndy] = check[x][y] + 1;
//                                if (check[ndx][ndy] <= l)
//                                {
//                                    q.push(make_pair(ndx, ndy));
//                                    result++;
//                                }
//                            }
//                        }
//                        else if (i == 1) //��
//                        {
//                            if (ntType == 1 || ntType == 2 || ntType == 4 || ntType == 7)
//                            {
//                                check[ndx][ndy] = check[x][y] + 1;
//                                if (check[ndx][ndy] <= l)
//                                {
//                                    q.push(make_pair(ndx, ndy));
//                                    result++;
//                                }
//                            }
//                        }
//                    }
//                }
//                break;
//            }
//            case 3:   //��,��
//            {
//                for (int i = 2; i < 4; i++)
//                {
//                    int ndx = x + dx[i];
//                    int ndy = y + dy[i];
//
//                    if (0 <= ndx && ndx < n && 0 <= ndy && ndy < m && !check[ndx][ndy])
//                    {
//                        int ntType = a[ndx][ndy];
//                        if (i == 2)   //��
//                        {
//                            if (ntType == 1 || ntType == 3 || ntType == 4 || ntType == 5)
//                            {
//                                check[ndx][ndy] = check[x][y] + 1;
//                                if (check[ndx][ndy] <= l)
//                                {
//                                    q.push(make_pair(ndx, ndy));
//                                    result++;
//                                }
//                            }
//                        }
//                        else if (i == 3)   //��
//                        {
//                            if (ntType == 1 || ntType == 3 || ntType == 6 || ntType == 7)
//                            {
//                                check[ndx][ndy] = check[x][y] + 1;
//                                if (check[ndx][ndy] <= l)
//                                {
//                                    q.push(make_pair(ndx, ndy));
//                                    result++;
//                                }
//                            }
//                        }
//                    }
//                }
//                break;
//            }
//            case 4:   //��,��
//            {
//                for (int i = 0; i < 4; i++)
//                {
//                    if (i % 3 != 0)
//                        continue;
//                    int ndx = x + dx[i];
//                    int ndy = y + dy[i];
//
//                    if (0 <= ndx && ndx < n && 0 <= ndy && ndy < m && !check[ndx][ndy])
//                    {
//                        int ntType = a[ndx][ndy];
//                        if (i == 0)   //��
//                        {
//                            if (ntType == 1 || ntType == 2 || ntType == 5 || ntType == 6)
//                            {
//                                check[ndx][ndy] = check[x][y] + 1;
//                                if (check[ndx][ndy] <= l)
//                                {
//                                    q.push(make_pair(ndx, ndy));
//                                    result++;
//                                }
//                            }
//                        }
//                        else if (i == 3)   //��
//                        {
//                            if (ntType == 1 || ntType == 3 || ntType == 6 || ntType == 7)
//                            {
//                                check[ndx][ndy] = check[x][y] + 1;
//                                if (check[ndx][ndy] <= l)
//                                {
//                                    q.push(make_pair(ndx, ndy));
//                                    result++;
//                                }
//                            }
//                        }
//                    }
//                }
//                break;
//            }
//            case 5:   //��,��
//            {
//                for (int i = 0; i < 4; i++)
//                {
//                    if (i % 2 == 0)
//                        continue;
//                    int ndx = x + dx[i];
//                    int ndy = y + dy[i];
//
//                    if (0 <= ndx && ndx < n && 0 <= ndy && ndy < m && !check[ndx][ndy])
//                    {
//                        int ntType = a[ndx][ndy];
//                        if (i == 1) //��
//                        {
//                            if (ntType == 1 || ntType == 2 || ntType == 4 || ntType == 7)
//                            {
//                                check[ndx][ndy] = check[x][y] + 1;
//                                if (check[ndx][ndy] <= l)
//                                {
//                                    q.push(make_pair(ndx, ndy));
//                                    result++;
//                                }
//                            }
//                        }
//                        else if (i == 3)   //��
//                        {
//                            if (ntType == 1 || ntType == 3 || ntType == 6 || ntType == 7)
//                            {
//                                check[ndx][ndy] = check[x][y] + 1;
//                                if (check[ndx][ndy] <= l)
//                                {
//                                    q.push(make_pair(ndx, ndy));
//                                    result++;
//                                }
//                            }
//                        }
//                    }
//                }
//                break;
//            }
//            case 6:   //��,��
//            {
//                for (int i = 1; i < 3; i++)
//                {
//                    int ndx = x + dx[i];
//                    int ndy = y + dy[i];
//
//                    if (0 <= ndx && ndx < n && 0 <= ndy && ndy < m && !check[ndx][ndy])
//                    {
//                        int ntType = a[ndx][ndy];
//                        if (i == 1) //��
//                        {
//                            if (ntType == 1 || ntType == 2 || ntType == 4 || ntType == 7)
//                            {
//                                check[ndx][ndy] = check[x][y] + 1;
//                                if (check[ndx][ndy] <= l)
//                                {
//                                    q.push(make_pair(ndx, ndy));
//                                    result++;
//                                }
//                            }
//                            else if (i == 2)   //��
//                            {
//                                if (ntType == 1 || ntType == 3 || ntType == 4 || ntType == 5)
//                                {
//                                    check[ndx][ndy] = check[x][y] + 1;
//                                    if (check[ndx][ndy] <= l)
//                                    {
//                                        q.push(make_pair(ndx, ndy));
//                                        result++;
//                                    }
//                                }
//                            }
//                        }
//                    }
//                }
//                break;
//            }
//            case 7:   //��,��
//            {
//                for (int i = 0; i < 4; i++)
//                {
//                    if (i % 2 != 0)
//                        continue;
//                    int ndx = x + dx[i];
//                    int ndy = y + dy[i];
//
//                    if (0 <= ndx && ndx < n && 0 <= ndy && ndy < m && !check[ndx][ndy])
//                    {
//                        int ntType = a[ndx][ndy];
//                        if (i == 0)   //��
//                        {
//                            if (ntType == 1 || ntType == 2 || ntType == 5 || ntType == 6)
//                            {
//                                check[ndx][ndy] = check[x][y] + 1;
//                                if (check[ndx][ndy] <= l)
//                                {
//                                    q.push(make_pair(ndx, ndy));
//                                    result++;
//                                }
//                            }
//                        }
//                        else if (i == 2)   //��
//                        {
//                            if (ntType == 1 || ntType == 3 || ntType == 4 || ntType == 5)
//                            {
//                                check[ndx][ndy] = check[x][y] + 1;
//                                if (check[ndx][ndy] <= l)
//                                {
//                                    q.push(make_pair(ndx, ndy));
//                                    result++;
//                                }
//                            }
//                        }
//                    }
//                }
//                break;
//            }
//            }
//        }
//
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < m; j++)
//            {
//                if (check[i][j])
//                    cout << 1 << " ";
//                else
//                    cout << 0 << " ";
//            }
//            cout << '\n';
//        }
//        cout << "#" << tNum << " " << result << '\n';
//    }
//    return 0;
//}
#include <iostream>
#include <queue>
using namespace std;
int map[50][50];
bool visited[50][50];
int T, N, M, R, C, L;
int answer;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
int directions[7][4] = { {1,1,1,1}, {1,0,0,1},{0,1,1,0},{1,0,1,0},{0,0,1,1},{0,1,0,1},{1,1,0,0} };
class Point {
public:
	int x, y;
	int move;
};
void BFS(int cur_x, int cur_y, int move);
int main() {
	ios_base::sync_with_stdio(false);
	cin >> T;
	T++;
	for (int TC = 1; TC < T; TC++){
		cin >> N >> M >> R >> C >> L;
		answer = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[i][j];
				map[i][j]--;
				visited[i][j] = false;
			}
		}
		
		BFS(R, C, L - 1);
		cout << "#" << TC << " " << answer << "\n";
	}
}
void BFS(int cur_x, int cur_y, int move) {
	answer++;
	visited[cur_x][cur_y] = true;
	int index = map[cur_x][cur_y];
	Point* start = new Point;
	start->x = cur_x;
	start->y = cur_y;
	start->move = move;
	queue<Point> next_node;
	next_node.push(*start);
	while (!next_node.empty()) {
		Point next = next_node.front();
		next_node.pop();
		index = map[next.x][next.y];
		if (next.move > 0) {
			for (int i = 0; i < 4; i++) {
				if (directions[index][i] == 1) {
					int tempx = next.x + dx[i];
					int tempy = next.y + dy[i];
					if (tempx < 0 || tempx >= N || tempy < 0 || tempy >= M)
						continue;
					int next_i = map[tempx][tempy];
					bool check = false;
					if (next_i != -1) {
						switch (i) {
						case 0:	//���� ĭ���� ���� �����̹Ƿ�, ���� ĭ���� �Ʒ����� �����־�� ��.(3)
							if (directions[next_i][3])
								check = true;
							break;
						case 1:	//���� ĭ���� ���� �����̹Ƿ�, ���� ĭ���� �������� �����־�� ��.(2)
							if (directions[next_i][2])
								check = true;
							break;
						case 2:	//���� ĭ���� ������ �����̹Ƿ�, ���� ĭ���� ������ �����־�� ��.(1)
							if (directions[next_i][1])
								check = true;
							break;
						case 3:	//���� ĭ���� �Ʒ��� �����̹Ƿ�, ���� ĭ���� �� ���� �����־�� ��.(0)
							if (directions[next_i][0])
								check = true;
							break;
						}
					}
					if (!visited[tempx][tempy] && check) {
						visited[tempx][tempy] = true;
						answer++;
						Point* tmp = new Point;
						tmp->x = tempx;
						tmp->y = tempy;
						tmp->move = next.move - 1;
						next_node.push(*tmp);
					}
				}
			}
		}
	}
}