#include <iostream>
#include <string>

using namespace std;

/*
����˼·�ܼ򵥣����ǴӺ���ǰ�жϣ����ǿ��ַ���count++���ǿ��ַ�������count
������Ŀ�и��ط�����˼û�б������������棩�������������Ҫ���Ⱥ����Թٽ���
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
��һ���ύʧ��
Wrong Answer: "a " expected: 1  output: 0
ԭ��
�о���Ŀ�����Ĳ��Ǻ��������һ��д��ʱ���ǵ������������������Ϊ���һ���ַ�Ϊ �� ����ʱ��Ӧ���������һ���ַ������ڵ������
���Է�����0������ĿҪ��Ӧ��������������·���ǰһ��word�ĳ���
�������
����һ���жϣ���count = 0ʱ�������ǰָ����ַ���ָ��ֱ����ǰ�ƶ�һ����

�ڶ����ύ�ɹ�
*/

int main() {
	string a = " ";
	int rs = lengthOfLastWord(a);
	cout << rs << endl;
	system("pause");
	return 0;
}