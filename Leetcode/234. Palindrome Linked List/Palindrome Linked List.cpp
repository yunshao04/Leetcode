#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

/*
先算链表长度，然后中点开始，翻转前半部分的链表，然后往两侧比较
*/
bool isPalindrome(ListNode* head) {
	if (head == NULL || head->next == NULL)
		return true;
	int count = 1;
	ListNode *cur = head;
	while (cur->next != NULL) {
		cur = cur->next;
		count++;
	}
	ListNode *pre = NULL, *next = head->next;
	cur = head;
	for (int i = 0; i < ((count + 1) / 2); i++) {
		cur->next = pre;
		pre = cur;
		cur = next;
		next = next->next;
	}
	if ((count % 2) == 1)
		pre = pre->next;
	while (pre || cur) {
		if (pre->val != cur->val)
			return false;
		pre = pre->next;
		cur = cur->next;
	}
	return true;

}

/*
另外一个思路，比上面的快在：算链表长度时，只要遍历半个链表
*/
//ListNode* reverseList(ListNode* head)
//{
//	if (head == NULL || head->next == NULL)
//		return head;
//	ListNode* nextHead = head->next;
//	head->next = NULL;
//	ListNode* newHead = head;
//	while (true)
//	{
//		ListNode* tmp = nextHead->next;
//		nextHead->next = newHead;
//		newHead = nextHead;
//		nextHead = tmp;
//		if (nextHead == NULL)
//			return newHead;
//	}
//}
//
//
//bool isPalindrome(ListNode* head) {
//	if (head == NULL || head->next == NULL)
//		return true;
//
//	ListNode* slow = head;
//	ListNode* fast = head;
//	while (fast && fast->next)
//	{
//		slow = slow->next;
//		fast = fast->next->next;
//	}
//
//	if (fast == NULL)
//		slow = reverseList(slow);
//	else
//	{
//		slow->next = reverseList(slow->next);
//		slow = slow->next;
//	}
//
//	ListNode* Head = head;
//	while (slow)
//	{
//		if (slow->val != Head->val)
//			return false;
//		else
//		{
//			slow = slow->next;
//			Head = Head->next;
//		}
//	}
//
//	return true;
//}

int main() {
	ListNode *a1 = new ListNode(1);
	ListNode *a2 = new ListNode(2);
	//ListNode *a3 = new ListNode(1);

	a1->next = a2;
	//a2->next = a3;

	bool rs = isPalindrome(a1);
	cout << rs << endl;
	system("pause");
	return 0;
}