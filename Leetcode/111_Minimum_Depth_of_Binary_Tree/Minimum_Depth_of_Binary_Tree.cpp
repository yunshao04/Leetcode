#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
	BFS，找最短路径
	一开始犯了个错误，把q.front()->left == NULL && q.front()->right == NULL这个条件放在了外层的while上，这样的后果是每层只会检测第一个节点是不是叶子
*/
int minDepth(TreeNode* root) {
	if (root == NULL)
		return 0;
	int i = 0;
	int depth = 1;
	int levelNum = 1;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		for (i = 0; i < levelNum; i++) {
			if (q.front()->left == NULL && q.front()->right == NULL)
				return depth;
			if (q.front()->left != NULL)
				q.push(q.front()->left);
			if (q.front()->right != NULL)
				q.push(q.front()->right);
			q.pop();
		}
		levelNum = q.size();
		depth++;
	}
	return depth;
}

int main() {
	TreeNode *a1 = new TreeNode(0);
	TreeNode *a2 = new TreeNode(3);
	TreeNode *a3 = new TreeNode(3);
	TreeNode *a4 = new TreeNode(4);
	TreeNode *a5 = new TreeNode(5);
	TreeNode *a6 = new TreeNode(5);

	a1->left = a2;
	a1->right = a3;
	a2->right = a4;
	a3->left = a5;
	a5->right = a6;

	int rs = minDepth(a1);
	cout << rs << endl;
	system("pause");
	return 0;
}