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
ͬ������DFSɨһ�飬���returen��ʱ����iterator�е�rbegin()��rend()
�����������Ч�ʲ������
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
	��һ���ύ�ɹ�
*/


/*
	DFS�ĵ���ʵ�֣���Ч��û�䣬�����
	����ע�⼸����
	1 Node����û��Ҫ��visited��flag����Ϊ��ʼ��һ���µ�Node�ڵ�ʱ���ĺ��Ӷ���NULL����ôֻ��Ҫ����TreeNode��û�к����ж�Node��û�к��ӾͿ��Եó�Node��ĳ��������û�б����ʹ���
	  ��������ʹ�����һ������NULL�����û�����ʹ�����һ����NULL
	2 ����NodeΪ�ڵ��Tree��ʱ��Ҫע���ջ�Ͳ���vector��˳��Ҫ��level++��Ȼ�����ж�vector rs�Ƿ�Խ�磻
	  ����if����Ҫ����һ��д����Ȼ�ֿ�д�Ļ���������if�����if������û�ﵽ������һ������if��elseҲ�ᱻ���� =��������ѭ��
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
	BFS����ʵ�� �ж�����һ�㣬��Ҫ����һ������������¼��ÿһ���ж��ٸ��ڵ㣬Ȼ�󳬹�����ڵ�ͻ���һ��
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