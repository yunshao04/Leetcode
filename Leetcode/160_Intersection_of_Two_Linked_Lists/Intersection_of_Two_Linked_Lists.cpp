#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*
	直接上网上的思路
	1）如果两个链表的最后一个节点一样，那么说明两个链表一定有交点。
	2）分别求出两个链表的长度，然后对长度长的链表向前移动：LengA - LengB，将两个链表进行对齐，之后一起遍历，直到找到第一个相同的节点。
*/
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	if (headA == NULL || headB == NULL)
		return NULL;
	int lenA = 1;
	int lenB = 1;
	ListNode* lastA = headA;
	ListNode* lastB = headB;
	ListNode* newHeadA = headA;
	ListNode* newHeadB = headB;
	while (lastA->next != NULL) {
		lastA = lastA->next;
		lenA++;
	}
	while (lastB->next != NULL) {
		lastB = lastB->next;
		lenB++;
	}
	if (lastA != lastB)
		return NULL;
	int diff = abs(lenA - lenB);
	if (lenA > lenB) {
		for (int i = 0; i < diff; i++) {
			newHeadA = newHeadA->next;
		}
	}
	else {
		for (int i = 0; i < diff; i++) {
			newHeadB = newHeadB->next;
		}
	}
	while (newHeadA != NULL) { //这里不能写成newHeadA->next，否则如果链表只有一个节点的情况下，会进不来。
		if (newHeadA == newHeadB)
			return newHeadA;
		else {
			newHeadA = newHeadA->next;
			newHeadB = newHeadB->next;
		}
	}
	//sccooor fall a medical couch on line coaching july night applicatio: coach volunteer coach self train usn  atheltes hardcopy
}

int main() {
	ListNode* a1 = new ListNode(1);
	ListNode* a2 = new ListNode(3);
	ListNode* b1 = new ListNode(2);
	ListNode* b2 = new ListNode(6);
	ListNode* c1 = new ListNode(4);

	//a1->next = a2;
	//a2->next = c1;
	//b1->next = b2;
	//b2->next = c1;


	ListNode* rs = getIntersectionNode(a1, a1);
	if (rs != NULL)
		cout << rs->val << endl;
	else
		cout << "NULL" << endl;
	system("pause");
	return 0;
}