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
	��һ���ύʧ��
	Runtime Error: "]"
	ԭ��
	stack �� top() ���������һ��stackΪ��ʱ�����ܵ���top
	�������
	�ڵ���topǰ�ж�һ��stack�Ƿ�Ϊ��

	�ڶ����ύ�ɹ�
	ע��
	if (a.top() == '(') a.pop(); else return false;  ����е�elseһ������ʡ���������û��ƥ���ϣ���ʲô����Ҳ�����ˣ�������stackͬ������գ��ͻᱻ�ж�Ϊ��ȷ e.g., "(])"

*/

int main() {
	string a = "()[]]{}";
	bool b = isValid(a);
	cout << b << endl;
	//stack<int> c;
	//cout << c.top() << endl;
	return 0;
}