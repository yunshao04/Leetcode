#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValid(string s) {
	if (s.size() == 0) {
		return true;
	}
	stack<char> a;
	for (int i = 0; i < s.size(); i++) {
		if (s.at(i) == '(' || s.at(i) == '[' || s.at(i) == '{') {
			a.push(s.at(i));
		}
		else if (s.at(i) == ')') {
			if (a.empty()) return false;
			if (a.top() == '(') a.pop(); else return false;
		} 
		else if (s.at(i) == ']') {
			if (a.empty()) return false;
			if (a.top() == '[') a.pop(); else return false;
		}
		else if (s.at(i) == '}') {
			if (a.empty()) return false;
			if (a.top() == '{')a.pop(); else return false;
		}
		else {
			return false;
		}
	}
	if (a.empty()) return true; 
	else return false;
}

/*
	第一次提交失败
	Runtime Error: "]"
	原因
	stack 的 top() 函数，如果一个stack为空时，不能调用top
	解决方案
	在调用top前判断一下stack是否为空

	第二次提交成功
	注意
	if (a.top() == '(') a.pop(); else return false;  这句中的else一定不能省，否则如果没有匹配上，就什么操作也不做了，如果最后stack同样被清空，就会被判定为正确 e.g., "(])"

*/

int main() {
	string a = "()[]]{}";
	bool b = isValid(a);
	cout << b << endl;
	//stack<int> c;
	//cout << c.top() << endl;
	return 0;
}