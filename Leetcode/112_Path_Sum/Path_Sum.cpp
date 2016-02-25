#include <iostream>
#include <stack>
#include <unordered_set>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//bool hasPathSum(TreeNode* root, int sum) {
//	if (root == NULL) {
//		return false;
//	}
//	unordered_set<TreeNode*> visited;
//	stack<TreeNode*> dfsStack;
//
//	int pathSum = root->val;
//	dfsStack.push(root);
//	visited.insert(root);
//	while (!dfsStack.empty()) {
//		if (dfsStack.top()->left == NULL && dfsStack.top()->right == NULL && pathSum == sum)
//			return true;
//		if (dfsStack.top()->left != NULL && visited.count(dfsStack.top()->left) == 0) {
//			dfsStack.push(dfsStack.top()->left);
//			visited.insert(dfsStack.top());
//			pathSum += dfsStack.top()->val;
//		}
//		else if (dfsStack.top()->right != NULL && visited.count(dfsStack.top()->right) == 0) {
//			dfsStack.push(dfsStack.top()->right);
//			visited.insert(dfsStack.top());
//			pathSum += dfsStack.top()->val;
//		}
//		else {
//			pathSum -= dfsStack.top()->val;
//			dfsStack.pop();
//		}
//	}
//	return false;
//}

/*
	��һ���ύʧ��
	Wrong Answer��  Input: [] 0  Output: true  Expected: false 
	ԭ��
	��Ŀ��������⣬����Ϊ��rootΪ��ʱ��ֱ�ӷ���false������ʱҪ��ͨ

	�ڶ����ύʧ��
	Wrong Answer��  Input: [1, 2] 1  Output: true  Expected: false
	ԭ��
	��Ŀ��������⣬��Ŀ˵ root-to-leaf path.

	�������ύ�ɹ�����Ч�ʺܵͣ�ԭ��Ӧ�������˹�ϣ��
*/


/*
	dfs�ĵݹ�ʵ�֣�Ч�ʸߺܶ�
*/
int dfs(TreeNode* root, int pathSum, int givenSum) {
	if (root->left == NULL && root->right == NULL) {
		if (pathSum == givenSum)
			return 1;
	}
	int leftRs = 0;
	if (root->left != NULL)
		leftRs = dfs(root->left, pathSum + root->left->val, givenSum);
	if (leftRs == 1)
		return 1;
	int rightRs = 0;
	if (root->right != NULL)
		rightRs = dfs(root->right, pathSum + root->right->val, givenSum);
	if (rightRs == 1)
		return 1;
	return 0;
}

/*
	�������Ͽ���һ�ָ����ĵݹ�汾
*/
//bool dfs(TreeNode *node, int sum, int curSum)
//{
//	if (node == NULL)
//		return false;
//
//	if (node->left == NULL && node->right == NULL)
//		return curSum + node->val == sum;
//
//	return dfs(node->left, sum, curSum + node->val) || dfs(node->right, sum, curSum + node->val);
//}
//
//bool hasPathSum(TreeNode *root, int sum) {
//	return dfs(root, sum, 0);
//}

bool hasPathSum(TreeNode* root, int sum) {
	if (root == NULL)
		return false; 
	int rs = dfs(root, root->val, sum);
	if (rs == 1)
		return true;
	else
		return false;
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

	bool rs = hasPathSum(a1, 7);
	cout << rs << endl;
	system("pause");
	return 0;
}