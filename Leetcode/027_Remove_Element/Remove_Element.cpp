#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
	/*
	�����˼·�ǿ�����ָ��i��j��i��ǰ����ɨ��jʼ��ͣ�����һ����val��λ�á���ָ��i����һ������val��ֵʱ���ͺ�j������ֱ����ֻ���ص�
	������ָ���ص�ʱ��Ҫע�⡣Ҫ���� i��j��� �� j�ܵ�iǰ�� ���ֲ�ͬ�����
	*/
	if (nums.size() == 0) {
		return 0;
	}
	if (nums.size() == 1) {
		if (nums.at(0) == val) return 0;
		else return 1;
	}
	int i = 0, j = nums.size() - 1;
	int tmp;
	while (i <= j) {
		while (nums.at(j) == val) {
			j--;
			if (j < 0)
				return 0;
		}
		if (j == i) return i + 1;
		if (j < i) return i;
		if (nums.at(i) == val) {
			tmp = nums.at(i);
			nums.at(i) = nums.at(j);
			nums.at(j) = tmp;
			j--;
		}
		else {
			i++;
		}
	}
}

/*
��һ���ύ�ɹ�
*/

int main() {
	vector<int> a;
	a.push_back(1);
	a.push_back(4);
	a.push_back(3);
	a.push_back(15);
	a.push_back(7);
	a.push_back(5);
	a.push_back(12);
	a.push_back(3);
	a.push_back(3);

	int rs = removeElement(a, 3);
	cout << rs << endl;
	for (int i = 0; i < rs; i++) {
		cout << a.at(i) << " ";
	}
	system("pause");
	return 0;
}