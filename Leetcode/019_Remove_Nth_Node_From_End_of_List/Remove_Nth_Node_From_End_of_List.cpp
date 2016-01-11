#include <iostream> 
#include <vector>

using namespace std;

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
/** 
������һ��ʼ��˼·���������ȵߵ�һ�Σ��ټ�����Ҫɾ�����ǵڼ����ڵ㣬����ٰ�����ߵ�����
�����ĿҪ�����һ��������ɣ������������ʵ������3�顣
�͵�����ϰ����ת��
*/
	//ListNode* tmp = head;
	//if (head == NULL) {
	//	return NULL;
	//}
	//if (head->next == NULL) {
	//	return NULL;
	//}
	//ListNode* tmpNext = head->next;
	//ListNode* previous = NULL;
	//while (tmp != NULL) {
	//	tmpNext = tmp->next;
	//	tmp->next = previous;
	//	previous = tmp;
	//	tmp = tmpNext;
	//}
	//ListNode* target = previous;
	//ListNode* newHead = previous;
	//for (int i = 0; i < (n - 1); i++) {
	//	previous = target;
	//	target = target->next;
	//}
	//previous->next = target->next;
	//tmp = newHead;
	//previous = NULL;
	//while (tmp != NULL) {
	//	tmpNext = tmp->next;
	//	tmp->next = previous;
	//	previous = tmp;
	//	tmp = tmpNext;
	//}
	//return previous;


/**
�ڶ���˼·�ǿ�һ��vector��Ȼ��ѵ�ַ���δ��£��������൱�ڸ��������ֱ�ӷ��ʣ���ɾ�ĸ�ɾ�ĸ�
*/
	if (head == NULL) {
		return NULL;
	}
	if (head->next == NULL) {
		return NULL;
	}
	ListNode* cur = head;
	vector<ListNode*> ListNodeAdd;
	while (cur != NULL) {
		ListNodeAdd.push_back(cur);
		cur = cur->next;
	}
	if (n == ListNodeAdd.size()) {
		return head->next;
	}
	ListNodeAdd.push_back(NULL);
	ListNodeAdd.at(ListNodeAdd.size() - n - 2)->next = ListNodeAdd.at(ListNodeAdd.size() - n);
	return head;
}

/*
	��һ���ύʧ��
	Runtime Error�� [1, 2] 2
	ԭ��
	ListNodeAdd.at(ListNodeAdd.size() - n - 2)���˴���ɾ���׽ڵ�ʱ��Խ�硣
	���������
	�ж��Ƿ�ɾ���׽ڵ㣬����ǣ���ֱ�ӷ��صڶ����ڵ㡣
	
	�ڶ����ύͨ��
*/

int main() {
	ListNode *node1 = new ListNode(1);
	ListNode *node2 = new ListNode(2);
	//ListNode *node3 = new ListNode(3);
	//ListNode *node4 = new ListNode(4);
	//ListNode *node5 = new ListNode(5);
	node1->next = node2;
	//node2->next = node3;
	//node3->next = node4;
	//node4->next = node5;

	ListNode* rs = removeNthFromEnd(node1, 2);
	ListNode* cur = rs;
	while (cur != NULL) {
		cout << cur->val << "->";
		cur = cur->next;
	}
	return 0;
}