#include <iostream>
#include <vector>

using namespace std;

/*
����ܼ򵥡���Ҫ˼·�ǴӺ���ǰ��9��һ����һ��Ѹ�λ��0����������һ������9������λ��ʱ�Ѹ�λ����1�����ȫ������9����ô�Ͱ����λ��һ��ĩβpush_backһ��0��
��Ŀ��������һ��the most significant digit is at the head of the list����仰һ��ʼû�붮�����������룬most significant digitӦ����Ȩ������λ��
����˵һ��3λ����Ȩ�����Ŀ϶��ǰ�λ
*/

vector<int> plusOne(vector<int>& digits) {
	if (digits.size() == 0) {
		digits.push_back(1);
		return digits;
	}
	int flag = 0;
	for (int i = digits.size() - 1; i >= 0; i--) {
		if (digits.at(i) != 9) {
			flag = 1;
			digits.at(i) += 1;
			break;
		}
		else {
			digits.at(i) = 0;
		}
	}
	if (flag == 0) {
		digits.at(0) = 1;
		digits.push_back(0);
	}
	return digits;
}

/*
��һ���ύ�ɹ�
*/

int main() {
	vector<int> a;
	//a.push_back(0);
	//a.push_back(9);
	//a.push_back(9);
	//a.push_back(9);
	//a.push_back(9);
	vector<int> rs = plusOne(a);
	for (int i = 0; i < rs.size(); i++) {
		cout << rs[i];
	}
	system("pause");
	return 0;
}