#include <iostream>
#include "solution.h"
#include "struct.h"

using namespace std;

class RemoveLinkedListElements : public slt::Solution {
	ListNode* removeElements(ListNode* head, int val) {
		if (head == NULL)
			return NULL;
		ListNode *cur = head - sizeof(head);
		cur->next = head;
		ListNode *preHead = cur;
		while (cur->next != NULL) {
			if (cur->next->val == val)
				cur->next = cur->next->next;
			else
				cur = cur->next;
		}
		return preHead->next;
	}

	void buildSolution() {
		ListNode *a = new ListNode(1);
		ListNode *b = new ListNode(4);
		ListNode *c = new ListNode(6);
		ListNode *d = new ListNode(3);
		ListNode *e = new ListNode(7);
		ListNode *f = new ListNode(6);

		a->next = b;
		b->next = c;
		c->next = d;
		d->next = e;
		e->next = f;

		ListNode *tmp = removeElements(a, 1);

		while (tmp != NULL) {
			cout << tmp->val << "->";
			tmp = tmp->next;
		}

	}
};