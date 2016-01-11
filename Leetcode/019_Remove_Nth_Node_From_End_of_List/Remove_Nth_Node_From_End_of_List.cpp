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
这是我一开始的思路：把链表先颠倒一次，再计算我要删除的是第几个节点，最后再把链表颠倒回来
这个题目要求遍历一遍链表即完成，但这个方法其实遍历了3遍。
就当做练习链表反转了
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
第二个思路是开一个vector，然后把地址依次存下，这样就相当于给链表加了直接访问，想删哪个删哪个
*/
	vector<ListNode*> ListAdd;
	while (head->next != NULL) {

	}



}

int main() {
	ListNode *node1 = new ListNode(1);
	ListNode *node2 = new ListNode(2);
	ListNode *node3 = new ListNode(3);
	ListNode *node4 = new ListNode(4);
	ListNode *node5 = new ListNode(5);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;

	ListNode* rs = removeNthFromEnd(node1, 2);
	ListNode* cur = rs;
	while (cur != NULL) {
		cout << cur->val << "->";
		cur = cur->next;
	}
	return 0;
}