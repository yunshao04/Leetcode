#include <iostream>
#include <string>

using namespace std;

int strStr(string haystack, string needle) {
	/*
	这题的思路很简单。
	主要要注意访问越界问题。
	e.g.，初稿时就把if (j == (l2 - 1)) return i; 写成了 if (j == l2) return i; 这样这句话永远不会被执行到
	另一个注意越界的地方是for (int i = 0; i <= l1 - l2; i++)中i的范围。如果不用l1 - l2， 则会越界；如果不用i <= l1 - l2， 则最后一次循环会被忽略
	*/
	int l1 = haystack.size();
	int l2 = needle.size();
	if (l1 == 0 && l2 == 0) return 0;
	if (l1 > 0 && l2 == 0) return 0;
	if (l1 == 0) return -1;
	for (int i = 0; i <= l1 - l2; i++) {
		for (int j = 0; j < l2; j++) {
			if (haystack.at(i + j) != needle.at(j)) {
				break;
			}
			if (j == (l2 - 1)) return i;
		}
	}
	return -1;
}

/*
第一次提交失败
Wrong Answer: "" ""    output: -1    expected: 0
原因：
对题目理解有偏差，考虑到了这种特殊情况，但是认为他应该返回-1。面试时特殊情况的解法一定要沟通
解决方案
在分别判断l1和l2长度之前加一句 if (l1 == 0 && l2 == 0) return 0;

第二次提交失败
Wrong Answer: "a" ""    output: -1    expected: 0
原因同上
解决方案
与上面类似

第三次提交成功
*/

int main() {
	string a = "qweabsqwe";
	string b = "abs";
	int rs = strStr(a, b);
	cout << rs << endl;
	system("pause");
	return 0;
}