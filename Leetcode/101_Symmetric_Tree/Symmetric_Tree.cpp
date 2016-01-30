#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSymmetric(TreeNode* root) {
	/*
	这题思路和same tree 很像。只不过是比较左右子树是不是相同，同时注意要将左子树或右子树其中的一个反转一下
	*/
	if (root == NULL)
		return true;
	if (root->left == NULL && root->right == NULL)
		return true;
	if ((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL))
		return false;
	queue<TreeNode*> lqueue, rqueue;
	lqueue.push(root->left);
	rqueue.push(root->right);
	while (!lqueue.empty()) {
		if (lqueue.front()->val != rqueue.front()->val) 
			return false;
		if ((lqueue.front()->left == NULL && rqueue.front()->right != NULL) || (lqueue.front()->left != NULL && rqueue.front()->right == NULL))
			return false;
		if ((lqueue.front()->right == NULL && rqueue.front()->left != NULL) || (lqueue.front()->right != NULL && rqueue.front()->left == NULL))
			return false;
		if (lqueue.front()->left != NULL) {
			lqueue.push(lqueue.front()->left);
			rqueue.push(rqueue.front()->right);
		}
		if (lqueue.front()->right != NULL) {
			lqueue.push(lqueue.front()->right);
			rqueue.push(rqueue.front()->left);
		}
		lqueue.pop();
		rqueue.pop();
	}
	return true;

	/*
	第一次提交成功
	*/
}

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

	bool rs = isSymmetric(a1);
	cout << rs << endl;
	system("pause");
	return 0;
}