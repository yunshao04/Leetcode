#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
	比较两个子树的高度
	实现起来一开始没想出来，看了网上答案
*/

int checkSubTree(TreeNode* root) {
	if (root == NULL)
		return 0;
	int leftHeight = checkSubTree(root->left);
	if (leftHeight == -1)
		return -1;

	int rightHeight = checkSubTree(root->right);
	if (rightHeight == -1)
		return -1;

	if (abs(rightHeight - leftHeight) > 1)
		return -1;
	return max(rightHeight, leftHeight) + 1;
}

bool isBalanced(TreeNode* root) {
	int flag = checkSubTree(root);
	if (flag == -1)
		return false;
	else
		return true;
}

/*
	第一次提交成功
*/

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

	bool rs = isBalanced(a1);
	cout << rs << endl;
	system("pause");
	return 0;
}