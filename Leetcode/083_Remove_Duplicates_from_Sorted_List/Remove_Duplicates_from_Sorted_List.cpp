#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
	if (head == NULL || head->next == NULL) return head;
	int cur = head->val;
	ListNode *tmp = head->next;
	ListNode *index = head;
	while (tmp != NULL) {
		if (tmp->val <= index->val) {
			tmp = tmp->next;
		}
		else {
			index->next = tmp;
			index = index->next;
			tmp = tmp->next;
		}
	}
	index->next = NULL;
	return head;
}

int main() {
	ListNode *n1 = new ListNode(0);
	ListNode *n2 = new ListNode(1);
	ListNode *n3 = new ListNode(1);
	ListNode *n4 = new ListNode(2);
	ListNode *n5 = new ListNode(3);
	ListNode *n6 = new ListNode(4);
	ListNode *n7 = new ListNode(4);
	ListNode *n8 = new ListNode(4);
	ListNode *n9 = new ListNode(7);
	
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = n8;
	n8->next = n9;

	ListNode *rs = deleteDuplicates(n1);
	while (rs != NULL) {
		cout << rs->val << "->";
		rs = rs->next;
	}
	system("pause");
	return 0;
}