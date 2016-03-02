#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

ListNode* reverseList(ListNode* head) {
	if (head == NULL || head->next == NULL)
		return head;
	ListNode* cur = head;
	ListNode* next = head->next;
	ListNode* pre = NULL;
	while (cur->next != NULL) {
		cur->next = pre;
		pre = cur;
		cur = next;
		next = cur->next;
	}
	cur->next = pre;
	return cur;
}

/*
���Ͽ�����һ�ֵݹ鷽����
�Ȱ�ĩ�ڵ㱣�棬Ȼ���ͷ�ڵ㿪ʼ�ݹ飬�����ĩ�ڵ㣬�����Լ����ѵ�ǰ�ڵ���Ϊ��һ�㷵�ؽڵ��next
*/
ListNode* reverseList(ListNode* head) {
	if (head == NULL || head->next == NULL)
		return head;
	ListNode* newhead = head;
	while (newhead->next != NULL)
		newhead = newhead->next;
	reverse(head);
	return newhead;
}
ListNode* reverse(ListNode* head)
{
	if (head->next == NULL)
		return head;
	else
	{
		ListNode* tail = reverse(head->next);
		tail->next = head;
		tail = tail->next;
		tail->next = NULL;
		return tail;
	}
}


int main() {
	ListNode *a1 = new ListNode(1);
	ListNode *a2 = new ListNode(2);
	ListNode *a3 = new ListNode(3);

	a1->next = a2;
	a2->next = a3;

	ListNode *rs = reverseList(a1);
	while (rs != NULL) {
		cout << rs->val << "->";
		rs = rs->next;
	}
	system("pause");
	return 0;
}
