#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/*
	����һ��ʼ���ʹ��BFS����������BFSʵ���ϱȽϷ�������DFS�ȽϺ�
	DFS���Ҫ����ʵ��Ҫ��һ����¼�Ƿ���ʹ�ĳ���ڵ�����ݽṹ��������С��vector�������hash map������������˵ݹ�
*/
vector<vector<int>> rs;

void dfs(TreeNode* n, int level) {
	if (n == NULL)
		return;
	if (level == rs.size()) {
		vector<int> t;
		rs.push_back(t);
	}
	rs[level].push_back(n->val);
	dfs(n->left, level + 1);
	dfs(n->right, level + 1);
	return;
}

vector<vector<int>> levelOrder(TreeNode* root) {
	dfs(root, 0);
	return rs;
}

/*
	��һ���ύ�ɹ�
*/


int main() {
	TreeNode *a1 = new TreeNode(0);
	TreeNode *a2 = new TreeNode(3);
	TreeNode *a3 = new TreeNode(3);
	TreeNode *a4 = new TreeNode(4);
	TreeNode *a5 = new TreeNode(5);
	//TreeNode *a6 = new TreeNode(5);

	a1->left = a2;
	a1->right = a3;
	a2->right = a4;
	a3->left = a5;

	vector<vector<int>> rs = levelOrder(a1);
	for (int i = 0; i < rs.size(); i++) {
		for (int j = 0; j < rs[i].size(); j++) {
			cout << rs[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}