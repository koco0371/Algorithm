#include <iostream>
using namespace std;
class Node {
public:
	int num;
	Node* left;
	Node* right;
};
void DFS(Node* cur);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int TC = 1; TC <= T; TC++) {
		int V, E;
		cin >> V >> E;
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
		DFS(&node_list[0]);
	}
}
void DFS(Node* cur) {
	cout << cur->num << " ";
	if (cur->left != NULL) {
		DFS(cur->left);
	}
	if (cur->right != NULL) {
		DFS(cur->right);
	}

}
