#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
	/*
	思路很简单，把每个节点推进队列比较
	*/
	if (p == NULL && q == NULL)
		return true;
	if ((p == NULL && q != NULL) || (p != NULL && q == NULL))
		return false;
	queue<TreeNode*> q1, q2;
	q1.push(p);
	q2.push(q);
	while (!q1.empty()) {
		if (q1.front()->val != q2.front()->val)
			return false;
		if ((q1.front()->left == NULL && q2.front()->left != NULL) || (q1.front()->left != NULL && q2.front()->left == NULL))
			return false;
		if ((q1.front()->right == NULL && q2.front()->right != NULL) || (q1.front()->right != NULL && q2.front()->right == NULL))
			return false;
		if (q1.front()->left != NULL) {
			q1.push(q1.front()->left);
			q2.push(q2.front()->left);
		}
		if (q1.front()->right != NULL) {
			q1.push(q1.front()->right);
			q2.push(q2.front()->right);
		}
		q1.pop();
		q2.pop();
	}
	return true;

	/*
	第一次提交失败
	Wrong Answer   Input: [0] [1]  Output: true  Expected: false
	原因
	q2.push(q); 这里一开始笔误，写成了q2.push(p);

	第二次提交失败
	Wrong Answer   Input: [0, -5] [0, -8]  Output: true  Expected: false
	原因
	q2.push(q2.front()->left);又一处笔误。。

	第三次提交成功 beat 4.8%


	*/
	/*
	recursive solution， 感觉速度并没有快。。

	if (!p && !q) { return true; }
	if ((!p && q) || (!q && p)){ return false; }
	if (p->val != q->val){ return false; }
	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	*/
}



int main() {
	TreeNode *a1 = new TreeNode(0);
	TreeNode *a2 = new TreeNode(-5);
	TreeNode *a3 = new TreeNode(3);
	TreeNode *a4 = new TreeNode(4);
	TreeNode *a5 = new TreeNode(5);
	TreeNode *a6 = new TreeNode(6);

	a1->left = a2; 
	//a1->right = a3;
	//a2->left = a4; 
	//a2->right = a5;
	//a5->right = a6;

	TreeNode *b1 = new TreeNode(0);
	TreeNode *b2 = new TreeNode(-8);
	TreeNode *b3 = new TreeNode(3);
	TreeNode *b4 = new TreeNode(4);
	TreeNode *b5 = new TreeNode(5);
	TreeNode *b6 = new TreeNode(6);

	b1->left = b2; 
	//b1->right = b3;
	//b2->left = b4; 
	//b2->right = b5;
	//b5->right = b6;

	bool rs = isSameTree(a1, b1);
	cout << rs << endl;
	system("pause");
	return 0;
}