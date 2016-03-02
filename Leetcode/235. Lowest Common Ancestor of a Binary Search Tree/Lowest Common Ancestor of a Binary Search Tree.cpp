#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	queue<TreeNode*> bfsQueue;
	int minValue = min(p->val, q->val);
	int maxValue = max(p->val, q->val);
	bfsQueue.push(root);
	while (!bfsQueue.empty()) {
		if (bfsQueue.front()->val < minValue) {
			bfsQueue.push(bfsQueue.front()->right);
			bfsQueue.pop();
		}
		else if (bfsQueue.front()->val > maxValue) {
			bfsQueue.push(bfsQueue.front()->left);
			bfsQueue.pop();
		}
		else {
			return bfsQueue.front();
		}
	}
}

int main() {
	TreeNode *a1 = new TreeNode(5);
	TreeNode *a2 = new TreeNode(3);
	TreeNode *a3 = new TreeNode(7);
	TreeNode *a4 = new TreeNode(1);
	TreeNode *a5 = new TreeNode(4);
	TreeNode *a6 = new TreeNode(6);

	a1->left = a2;
	a1->right = a3;
	a2->right = a4;
	a2->left = a5;
	a3->left = a6;

	TreeNode *rs = lowestCommonAncestor(a1, a4, a5);
	cout << rs->val << endl;
	system("pause");
	return 0;
}