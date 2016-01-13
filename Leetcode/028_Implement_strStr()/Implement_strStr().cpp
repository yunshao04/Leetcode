#include <iostream>
#include <string>

using namespace std;

int strStr(string haystack, string needle) {
	/*
	�����˼·�ܼ򵥡�
	��ҪҪע�����Խ�����⡣
	e.g.������ʱ�Ͱ�if (j == (l2 - 1)) return i; д���� if (j == l2) return i; ������仰��Զ���ᱻִ�е�
	��һ��ע��Խ��ĵط���for (int i = 0; i <= l1 - l2; i++)��i�ķ�Χ���������l1 - l2�� ���Խ�磻�������i <= l1 - l2�� �����һ��ѭ���ᱻ����
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
��һ���ύʧ��
Wrong Answer: "" ""    output: -1    expected: 0
ԭ��
����Ŀ�����ƫ����ǵ����������������������Ϊ��Ӧ�÷���-1������ʱ��������Ľⷨһ��Ҫ��ͨ
�������
�ڷֱ��ж�l1��l2����֮ǰ��һ�� if (l1 == 0 && l2 == 0) return 0;

�ڶ����ύʧ��
Wrong Answer: "a" ""    output: -1    expected: 0
ԭ��ͬ��
�������
����������

�������ύ�ɹ�
*/

int main() {
	string a = "qweabsqwe";
	string b = "abs";
	int rs = strStr(a, b);
	cout << rs << endl;
	system("pause");
	return 0;
}