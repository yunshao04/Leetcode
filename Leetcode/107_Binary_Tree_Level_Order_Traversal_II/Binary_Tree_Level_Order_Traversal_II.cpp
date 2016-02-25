#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
同样还是DFS扫一遍，最后returen的时候用iterator中的rbegin()和rend()
不过这个方法效率不是最高
*/

//vector<vector<int>> rs;
//
//void dfs(TreeNode* root, int level) {
//	if (root == NULL)
//		return;
//	if (level == rs.size()) {
//		vector<int> t;
//		rs.push_back(t);
//	}
//	rs[level].push_back(root->val);
//	dfs(root->left, level + 1);
//	dfs(root->right, level + 1);
//}
//
//vector<vector<int>> levelOrderBottom(TreeNode* root) {
//	dfs(root, 0);
//	return vector<vector<int>>(rs.rbegin(), rs.rend());
//}

/*
	第一次提交成功
*/


/*
	DFS的迭代实现，但效率没变，很奇怪
	这里注意几个点
	1 Node里面没必要开visited的flag。因为初始化一个新的Node节点时他的孩子都是NULL，那么只需要根据TreeNode有没有孩子判断Node有没有孩子就可以得出Node的某个孩子有没有被访问过。
	  如果被访问过，那一定不是NULL，如果没被访问过，那一定是NULL
	2 构建Node为节点的Tree的时候要注意插栈和插入vector的顺序，要先level++，然后在判断vector rs是否越界；
	  还有if条件要两个一起写，不然分开写的话进了外层的if，里层if的条件没达到，那下一个外层的if或else也会被跳过 =〉导致死循环
*/

//struct Node {
//	TreeNode* n;
//	Node* left;
//	Node* right;
//	Node(TreeNode* x) : n(x), left(NULL), right(NULL) {}
//};
//
//vector<vector<int>> levelOrderBottom(TreeNode* root) {
//	vector<vector<int>> rs;
//	if (root == NULL)
//		return rs;
//	stack<Node*> st;
//	int level = 0;
//	Node* r = new Node(root);
//	Node* t;
//	vector<int> v;
//	rs.push_back(v);
//	st.push(r);
//	rs[level].push_back(st.top()->n->val);
//	while (!st.empty()) {
//		if (st.top()->n->left != NULL && st.top()->left == NULL) {
//			t = new Node(st.top()->n->left);
//			st.top()->left = t;
//			st.push(t);
//			level++;
//			if (rs.size() == level) {
//				rs.push_back(v);
//			}
//			rs[level].push_back(st.top()->n->val);
//		}
//		else if (st.top()->n->right != NULL && st.top()->right == NULL) {
//			t = new Node(st.top()->n->right);
//			st.top()->right = t;
//			st.push(t);
//			level++;
//			if (rs.size() == level) {
//				rs.push_back(v);
//			}
//			rs[level].push_back(st.top()->n->val);
//		}
//		else {
//			st.pop();
//			level--;
//		}
//	}
//	return vector<vector<int>>(rs.rbegin(), rs.rend());
//}

/*
	BFS迭代实现 判断在哪一层，主要依靠一个计数器，记录下每一层有多少个节点，然后超过这个节点就换下一层
*/

vector<vector<int>> levelOrderBottom(TreeNode* root) {
	vector<vector<int>> rs;
	if (root == NULL)
		return rs;
	queue<TreeNode*> q;
	q.push(root);
	int i = 0;
	int levelNum = q.size();
	int level = 0;
	vector<int> v;
	rs.push_back(v);
	while (q.size() != 0) {
		if (level == rs.size())
			rs.push_back(v);
		for (i = 0; i < levelNum; i++) {
			if (q.front()->left != NULL) {
				q.push(q.front()->left);
			}
			if (q.front()->right != NULL) {
				q.push(q.front()->right);
			}
			rs[level].push_back(q.front()->val);
			q.pop();
		}
		levelNum = q.size();
		level++;
	}
	return vector<vector<int>>(rs.rbegin(), rs.rend());
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

	vector<vector<int>> result = levelOrderBottom(a1);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}