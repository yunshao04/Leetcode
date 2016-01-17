#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/*
这题看了下答案。原因是没有想到 每位上可以这样处理 int cur = ((a[i] - '0') + (b[i] - '0') + flag) % 2
	分析下这句话：首先，(a[i] - '0')可以把字符转换成int; 其次3项加起来在取除以2的余数就是当前位的数字
另外还有一些tricks：一开始，把两个字符串补齐，方便循环里调用; 
				  重新开一个字符串来存结果，这样条理更清晰（初始想法是直接改其中比较长的一个字符串，这样也可以做，但条理不够清晰，而且在返回时有点麻烦）
*/

string addBinary(string a, string b) {
	if (a.size() == 0 && b.size() == 0) return "";
	if (a.size() == 0) return b;
	if (b.size() == 0) return a;
	int flag = 0;
	int cur = 0;
	int diff = abs((int)a.size() - (int)b.size());
	string add(diff, '0');
	string rs = "";
	if (a.size() > b.size()) {
		rs.resize(a.size(), '0');
		b = add + b;
	}
	else {
		rs.resize(b.size(), '0');
		a = add + a;
	}
	for (int i = rs.size() - 1; i >= 0; i--) {
		cur = (a[i] - '0') + (b[i] - '0') + flag;
		if (cur > 1) flag = 1;
		else flag = 0;
		cur = cur % 2;
		if (cur == 1) rs[i] = '1';
	}
	if (flag == 1) rs = '1' + rs;
	return rs;
}

/*
第一次提交成功
*/

int main() {
	string a = "111";
	string b = "11";
	string rs = addBinary(a, b);
	cout << rs << endl;
	system("pause");
	return 0;
}