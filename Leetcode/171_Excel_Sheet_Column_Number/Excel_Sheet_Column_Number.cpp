#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

/*
本质上当成26进制转10进制
*/

//int titleToNumber(string s) {
//	if (s.size() == 0)
//		return 0;
//	int rs = 0;
//	for (int i = 0; i < s.size(); i++) {
//		rs += (s[s.size() - 1 - i] - 'A' + 1) * pow(26, i);
//	}
//	return rs;
//}

/*
第一次提交成功，但是速度不是最快的一档
原因是每次循环都计算了pow(26, i)
*/

/*
优化一下，把pow(26, i)的值每次都存下来
*/

int titleToNumber(string s) {
	if (s.size() == 0)
		return 0;
	int rs = 0;
	int tmp = 1;
	for (int i = 0; i < s.size(); i++) {
		rs += (s[s.size() - 1 - i] - 'A' + 1) * tmp;
		tmp *= 26;
	}
	return rs;
}

/*
第一次提交成功，优化到最快的梯队
*/



int main() {
	string a = "AD";
	int rs = titleToNumber(a);
	cout << rs << endl;
	system("pause");
	return 0;
}