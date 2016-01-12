#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
/*
这边我一开始不知道他sorted list是怎么排序的，所以做了个自适应。然后题目需求应该是两个sorted list组成一个sorted list。感觉题目的描述不是很清楚。
思路是用双指针指向不同的链表。
另一个思路是递归，目前没有实现。

补充：该题中的sorted list应该是由小到大
另外：考虑的时候不仅仅要考虑输入为大空集，single甚至double的输入也要着重考虑
*/
	if (l1 == NULL) {
		return l2;
	}
	if (l2 == NULL) {
		return l1;
	}
	int flag = 0;
	ListNode *p1 = l1, *p2 = l2;
	ListNode *tmp = NULL;
	while (p1->next != NULL) {
		if (p1->val > p1->next->val) {
			flag = 1;
			break;
		}
		else if (p1->val < p1->next->val) {
			flag = -1;
			break;
		}
		p1 = p1->next;
	}
	if (flag == 0) {
		while (p2->next != NULL) {
			if (p2->val > p2->next->val) {
				flag = 1;
				break;
			}
			else if (p2->val < p2->next->val) {
				flag = -1;
				break;
			}
			p2 = p2->next;
		}
	}
	ListNode *newHead = NULL;
	ListNode *cur = NULL;
	p1 = l1; p2 = l2;
	if (flag == -1) {
		if (p1->val < p2->val) {
			cur = p1;
			p1 = p1->next;
		}
		else {
			cur = p2;
			p2 = p2->next;
		}
		newHead = cur;
		while (p1 != NULL && p2 != NULL) {
			if (p1->val < p2->val) {
				cur->next = p1;
				p1 = p1->next;
			}
			else {
				cur->next = p2;
				p2 = p2->next;
			}
			cur = cur->next;
		}
		if (p1 == NULL && p2 != NULL) {
			cur->next = p2;
		}
		if (p2 == NULL && p1 != NULL) {
			cur->next = p1;
		}
	} else if (flag == 1) {
		if (p1->val > p2->val) {
			cur = p1;
			p1 = p1->next;
		}
		else {
			cur = p2;
			p2 = p2->next;
		}
		newHead = cur;
		while (p1 != NULL && p2 != NULL) {
			if (p1->val > p2->val) {
				cur->next = p1;
				p1 = p1->next;
			}
			else {
				cur->next = p2;
				p2 = p2->next;
			}
			cur = cur->next;
		}
		if (p1 == NULL && p2 != NULL) {
			cur->next = p2;
		}
		if (p2 == NULL && p1 != NULL) {
			cur->next = p1;
		}
	}
	else if (flag == 0) {
		if (p1->val < p2->val) {
			newHead = p1;
			tmp = p2;
		}
		else {
			newHead = p2;
			tmp = p1;
		}
		cur = newHead;
		while (cur->next != NULL) {
			cur = cur->next;
		}
		cur->next = tmp;
	}
	return newHead;
}

/*
	第一次提交失败
	Runtime Error: [1, 3, 4] [0]
	原因
	else if (p1->val < p2->next->val) 中p2->next->val笔误，应为p1->next->val
	此句用于根据第一个链表判断flag的值（如果是递增的sorted list，flag = -1；如果是递减的sorted list，flag = 1；如果sorted list中所有数都是相等的，flag = 0）

	第二次提交失败
	Wrong Answer: [2] [1]
	原因
	如果两个链表都只包含一个元素，则会跳过自适应机制，直接进入flag = 0的分支。而在flag = 0的分支中没有比较两个表头的大小。
	原来认为，只有当两个表所有元素都相等时，flag才会等于0。这里考虑不周。实际上当两个链表中都只含有一个元素时，也会进入flag = 0的分支。
	解决方案
	在flag = 0分支中增加表头大小的判断

	第三次提交成功
*/

int main() {
	ListNode* l1n1 = new ListNode(2);
	ListNode* l2n1 = new ListNode(1);
	//ListNode* l1n2 = new ListNode(3);
	//ListNode* l2n2 = new ListNode(4);
	//ListNode* l1n3 = new ListNode(4);
	//ListNode* l2n3 = new ListNode(8);
	//ListNode* l1n4 = new ListNode(8);
	//ListNode* l2n4 = new ListNode(7);
	//ListNode* l1n5 = new ListNode(7);

	//l1n1->next = l1n2;
	//l1n2->next = l1n3;
	//l1n3->next = l1n4;
	//l1n4->next = l1n5;

	//l2n1->next = l2n2;
	//l2n2->next = l2n3;
	//l2n3->next = l2n4;

	ListNode* cur = mergeTwoLists(l1n1, l2n1);
	
	while (cur != NULL) {
		cout << cur->val << "->";
		cur = cur->next;
	}

	system("pause");
	return 0;
}