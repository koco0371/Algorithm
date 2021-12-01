#include <iostream>
#include <vector>
using namespace std;
class Node {
public:
	int num;
	Node* left;
	Node* right;
};
vector<int> find_node(Node* cur, int target, vector<int> path);
void find_size(Node* cur, int* size);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		int V, E, target1, target2;
		cin >> V >> E >> target1 >> target2;
		target1--;
		target2--;
		Node* node_list = new Node[V];
		for (int i = 0; i < V; i++) {
			node_list[i].num = i;
			node_list[i].left = NULL;
			node_list[i].right = NULL;
		}
		for (int i = 0; i < E; i++) {
			int start, end;
			cin >> start >> end;
			start--;
			end--;
			if (node_list[start].left == NULL)
				node_list[start].left = &node_list[end];
			else
				node_list[start].right = &node_list[end];
		}
		vector<int> temp1;
		temp1.push_back(0);
		temp1=find_node(&node_list[0], target1, temp1);
		vector<int> temp2;
		temp2.push_back(0);
		temp2=find_node(&node_list[0], target2, temp2);
		int size1 = temp1.size();
		int size2 = temp2.size();
		vector<int> ans;
		for (int i = 0; i < size1; i++) {
			for (int j = 0; j < size2; j++) {
				if (temp1[i] == temp2[j])
					ans.push_back(temp1[i]);
			}
		}
		size1 = ans.size();
		int ans1 = ans[size1 - 1];
		size1 = 0;
		find_size(&node_list[ans1], &size1);
		ans1++;
		cout << "#" << TC << " " << ans1 << " " << size1 << endl;
	}
}
vector<int> find_node(Node* cur, int target, vector<int> path) {
	if (cur->num == target)
		return path;
	bool check = false;
	vector<int> temp;
	if (cur->left != NULL) {
		check = true;
		path.push_back(cur->left->num);
		temp = find_node(cur->left, target, path);
		if (temp.size() != 0) {
			path = temp;
			return path;
		}
		path.pop_back();
	}
	if (cur->right != NULL) {
		check = true;
		path.push_back(cur->right->num);
		temp = find_node(cur->right, target, path);
		if (temp.size() != 0) {
			path = temp;
			return path;
		}
		path.pop_back();
	}
	return temp;
}
void find_size(Node* cur, int* size) {
	(*size)++;
	if (cur->left != NULL) 
		find_size(cur->left, size);
	if (cur->right != NULL)
		find_size(cur->right, size);
}