#include <iostream>
#include <vector>
#include <cmath>
#define MAX 987654321
using namespace std;
int T, N;
int map[20][20];
int answer;
class Restaurant {
public:
	int x, y;
	int price;
	int num;
	int map[20][20];
};
class Home {
public:
	int x, y;
	bool visit;
	int min_dist;
};
vector<Restaurant> rest_list;
vector<Home> home_list;
void DFS(bool* choice, int cur) {

	int rest_size = rest_list.size();
	if (cur >= rest_size)
		return;
	int cost = 0;
	//현재 조합을 가지고 비용 계산
	int size = choice.size();
	int home_size = home_list.size();
	size--;
	for (int j = 0; j < home_size; j++) {
		int cur_distance = home_list[j].min_dist;
		int x = home_list[j].x;
		int y = home_list[j].y;
		int distance = rest_list[size].map[x][y];
		home_list[j].min_dist = cur_distance > distance ? distance : cur_distance;
	}
	size++;
	for (int i = 0; i < size; i++)
		cost += choice[i].price;
	for (int i = 0; i < home_size; i++)
		cost += home_list[i].min_dist;

	if (cost < answer)
		answer = cost;

	for (int i = cur + 1; i < rest_size; i++) {
		DFS(choice, cur + 1);	//다음 노드를 포함하지 않는 경우
		choice.push_back(rest_list[i]);
		DFS(choice, cur + 1);	//다음 노드를 포함하는 경우
		choice.pop_back();
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	T++;
	for (int Test_Case = 1; Test_Case < T; Test_Case++) {
		cin >> N;
		rest_list.clear();
		home_list.clear();
		answer = MAX;
		int rest_num = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (map[i][j] > 1) {
					Restaurant* temp;
					temp = new Restaurant;
					temp->x = i;
					temp->y = j;
					temp->price = map[i][j];
					temp->num = rest_num;
					rest_list.push_back(*temp);
					rest_num++;
				}
				else if(map[i][j] == 1){
					Home* tmp;
					tmp = new Home;
					tmp->min_dist = MAX;
					tmp->visit = false;
					tmp->x = i;
					tmp->y = j;
					home_list.push_back(*tmp);
				}
			}
		}
		
		int len = rest_list.size();
		int home_size = home_list.size();
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < home_size; j++) {
				int distance = abs(rest_list[i].x - home_list[j].x) + abs(rest_list[i].y - home_list[j].y);
				int x = home_list[j].x;
				int y = home_list[j].y;
				rest_list[i].map[x][y] = distance;
			}
		}
		bool* choice = new bool[len];
		choice = { false };
		for (int i = 0; i < len; i++) {
			choice[i] = true;
			for (int j = 0; j < home_size; j++)
				home_list[j].min_dist = MAX;
			DFS(choice, i);
		}
		if (len == 0)
			answer = 0;
		cout <<"#"<<Test_Case<<" "<<answer << "\n";
	}
	return 0;
}