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

int m = 0;

void dfs(TreeNode* n, int depth) {
	if (n == NULL)
		return;
	if (depth > m)
		m = depth;
	dfs(n->left, depth + 1);
	dfs(n->right, depth + 1);
}

int maxDepth(TreeNode* root) {
	if (root == NULL)
		return 0;
	dfs(root, 1);
	return m;
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

	int rs = maxDepth(a1);
	cout << rs << endl;
	system("pause");
	return 0;
}