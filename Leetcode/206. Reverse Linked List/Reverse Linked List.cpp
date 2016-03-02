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
网上看到另一种递归方法：
先把末节点保存，然后从头节点开始递归，如果是末节点，返回自己。把当前节点设为上一层返回节点的next
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
