#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/*
���⿴���´𰸡�ԭ����û���뵽 ÿλ�Ͽ����������� int cur = ((a[i] - '0') + (b[i] - '0') + flag) % 2
	��������仰�����ȣ�(a[i] - '0')���԰��ַ�ת����int; ���3���������ȡ����2���������ǵ�ǰλ������
���⻹��һЩtricks��һ��ʼ���������ַ������룬����ѭ�������; 
				  ���¿�һ���ַ����������������������������ʼ�뷨��ֱ�Ӹ����бȽϳ���һ���ַ���������Ҳ���������������������������ڷ���ʱ�е��鷳��
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
��һ���ύ�ɹ�
*/

int main() {
	string a = "111";
	string b = "11";
	string rs = addBinary(a, b);
	cout << rs << endl;
	system("pause");
	return 0;
}