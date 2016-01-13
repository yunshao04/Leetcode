#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
/*
����һ��ʼ����Ŀ�����ˡ���Ϊ��ֻҪ�����в�ͬ�����ֵĸ�����ʵ������Ҫ�ı�������顣�ò�ͬ����������ǰ�档
��˼·����
*/
	//if (nums.size() == 0) {
	//	return 0;
	//}
	//if (nums.size() == 1) {
	//	return 1;
	//}
	//int count = 1, cur = nums.at(0);
	//for (int i = 1; i < nums.size(); i++) {
	//	if (nums.at(i) > cur) {
	//		cur = nums.at(i);
	//		count++;
	//	}
	//}
	//return count;

	if (nums.size() == 0) {
		return 0;
	}
	if (nums.size() == 1) {
		return 1;
	}
	int i = 1, j = 1;
	int cur = nums.at(0);
	while (j < nums.size()) {
		if (nums.at(j) > cur) {
			cur = nums.at(j);
			if (j != i) {
				nums.at(i) = nums.at(j);
			}
			i++;
			j++;
			continue;
		}
		j++;
	}
	return i;
}

/*
	��һ���ύʧ��
	ԭ����Ŀ�������

	�ڶ����ύ�ɹ�
	��������˼����ʱ��ܾá�ԭ���Ƕ�˫ָ��Ŀռ����󻹲�������
*/

int main() {
	vector<int> a;
	a.push_back(1);
	a.push_back(1);
	a.push_back(4);
	a.push_back(5);
	int rs = removeDuplicates(a);
	cout << rs << endl;
	for (int i = 0; i < rs; i++) {
		cout << a.at(i) << " ";
	}
	system("pause");
	return 0;
}