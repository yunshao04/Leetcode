#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

/*
�����ϵ���26����ת10����
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
��һ���ύ�ɹ��������ٶȲ�������һ��
ԭ����ÿ��ѭ����������pow(26, i)
*/

/*
�Ż�һ�£���pow(26, i)��ֵÿ�ζ�������
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
��һ���ύ�ɹ����Ż��������ݶ�
*/



int main() {
	string a = "AD";
	int rs = titleToNumber(a);
	cout << rs << endl;
	system("pause");
	return 0;
}