#include <iostream>
#include <stack>

using namespace std;
/*
	����û�������������stack��ֱ�ӷ������ҵ��ķ���
	1 �뵽������stack��ά������ṹ��1��stack������������stack��push pop�Ȳ���������1��stack����ά��min.ÿ�ζ�stack����pop����pushʱ��Ҳ��min_stack������Ӧ������

	2 ��2��stack�Ĵ�С�ǿ��Խ����Ż��ġ���һ��ÿ��min��Ҫ��ջmin_stack,push��ʱ��ֻ��ջ�ȵ�ǰminС������ȵ�ֵ�Ϳ����ˡ�pop��ʱ�򣬱Ƚϴ�popԪ�غ�min_stack��top�Ĵ�С�������popԪ�غ�min_stack top��ȣ���min stack����pop��

	3 online judge�������ĺã������������ջ����û�пռ��Ż�����û��ac�ġ�

	ֱ�Ӱѹ����ϵ�unlocked֮��Ľ�𳭹���:

	O(1) runtime, O(n) space �C Extra stack:
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