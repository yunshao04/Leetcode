#include <iostream>
#include <stack>

using namespace std;
/*
	这题没想出来是用两个stack，直接放网上找到的分析
	1 想到用两个stack来维护这个结构。1个stack用来正常进行stack的push pop等操作。另外1个stack用来维护min.每次对stack进行pop或者push时，也对min_stack进行相应操作。

	2 第2个stack的大小是可以进行优化的。不一定每个min都要入栈min_stack,push的时候，只入栈比当前min小或者相等的值就可以了。pop的时候，比较待pop元素和min_stack的top的大小。如果待pop元素和min_stack top相等，则将min stack进行pop。

	3 online judge做得真心好，如果用了两个栈但是没有空间优化，是没法ac的。

	直接把官网上的unlocked之后的解答抄过来:

	O(1) runtime, O(n) space – Extra stack:
*/
class MinStack {
private:
	stack<int> minSt;
	stack<int> dataSt;

public:
	void push(int x) {
		dataSt.push(x);
		if (minSt.size() == 0) {
			minSt.push(x);
		}
		else {
			if (x <= minSt.top())
				minSt.push(x);
		}
	}

	void pop() {
		if (dataSt.top() == minSt.top())
			minSt.pop();
		dataSt.pop();
	}

	int top() {
		return dataSt.top();
	}

	int getMin() {
		return minSt.top();
	}
};