#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
/*
�����һ��ʼ��֪����sorted list����ô����ģ��������˸�����Ӧ��Ȼ����Ŀ����Ӧ��������sorted list���һ��sorted list���о���Ŀ���������Ǻ������
˼·����˫ָ��ָ��ͬ������
��һ��˼·�ǵݹ飬Ŀǰû��ʵ�֡�

���䣺�����е�sorted listӦ������С����
���⣺���ǵ�ʱ�򲻽���Ҫ��������Ϊ��ռ���single����double������ҲҪ���ؿ���
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
	��һ���ύʧ��
	Runtime Error: [1, 3, 4] [0]
	ԭ��
	else if (p1->val < p2->next->val) ��p2->next->val����ӦΪp1->next->val
	�˾����ڸ��ݵ�һ�������ж�flag��ֵ������ǵ�����sorted list��flag = -1������ǵݼ���sorted list��flag = 1�����sorted list��������������ȵģ�flag = 0��

	�ڶ����ύʧ��
	Wrong Answer: [2] [1]
	ԭ��
	�����������ֻ����һ��Ԫ�أ������������Ӧ���ƣ�ֱ�ӽ���flag = 0�ķ�֧������flag = 0�ķ�֧��û�бȽ�������ͷ�Ĵ�С��
	ԭ����Ϊ��ֻ�е�����������Ԫ�ض����ʱ��flag�Ż����0�����￼�ǲ��ܡ�ʵ���ϵ����������ж�ֻ����һ��Ԫ��ʱ��Ҳ�����flag = 0�ķ�֧��
	�������
	��flag = 0��֧�����ӱ�ͷ��С���ж�

	�������ύ�ɹ�
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