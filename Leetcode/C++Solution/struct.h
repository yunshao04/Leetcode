#ifndef STRUCT_H
#define STRUCT_H

#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

#endif