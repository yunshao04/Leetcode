#include <iostream> 
#include <string>

using namespace std;

/*
����һ���ҹ��ɵ���
�����ǣ���һ�����൱���Ǹ���һ������ÿ����ͬ������ǰ��Ӹ�������
����Ҫע�����for (int i = 0; i < (n - 1); i++)��仰�У����n������Ҫ������n-1��ѭ������Ϊ�Ѿ������˵�һ������ 1
*/

string countAndSay(int n) {
	if (n == 0) {
		return "";
	}
	if (n == 1) {
		return "1";
	}
	string tmp = "1";
	string next = "";
	string s_counter = "";
	int cur = 0;
	int counter = 0;
	for (int i = 0; i < (n - 1); i++) {
		next = "";
		counter = 0;
		cur = (int)tmp[0];
		for (int j = 0; j < tmp.size(); j++) {
			if (cur == (int)tmp[j]) {
				counter++;
			}
			else {
				s_counter = to_string(counter);
				next += s_counter;
				next.push_back(tmp[j - 1]);
				counter = 1;
				cur = (int)tmp[j];
			}
			if (j == tmp.size() - 1) {
				s_counter = to_string(counter);
				next += s_counter;
				next.push_back(tmp[j]);
			}
		}
		tmp = next;
	}
	return tmp;
}

/*
��һ���ύ�ɹ�
*/

int main() {
	string rs = countAndSay(5);
	cout << rs << endl;
	system("pause");
	return 0; 
}