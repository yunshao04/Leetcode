#include <iostream>
#include <string>

using namespace std;

/*
这题思路很简单，就是从后往前判断，不是空字符，count++；是空字符，返回count
这里题目有个地方的意思没有表达清楚（见下面）。碰到这种情况要优先和面试官交流
*/

int lengthOfLastWord(string s) {
	int count = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		if (count == 0 && s.at(i) == ' ') continue;
		if (s.at(i) != ' ') {
			count++;
		}
		else {
			break;
		}
	}
	return count;
}

/*
第一次提交失败
Wrong Answer: "a " expected: 1  output: 0
原因
感觉题目描述的不是很清楚。第一次写的时候考虑到了这种情况，但是认为最后一个字符为 ‘ ’的时候应该属于最后一个字符不存在的情况。
所以返回了0。而题目要求应该是在这种情况下返回前一个word的长度
解决方案
增加一个判断，当count = 0时，如果当前指向空字符，指针直接向前移动一个。

第二次提交成功
*/

int main() {
	string a = " ";
	int rs = lengthOfLastWord(a);
	cout << rs << endl;
	system("pause");
	return 0;
}