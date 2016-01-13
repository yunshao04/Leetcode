#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
	/*
	这题的思路是开两个指针i，j，i从前往后扫，j始终停在最后一个非val的位置。当指针i发现一个等于val的值时，就和j交换，直到两只真重叠
	这里两指针重叠时需要注意。要考虑 i和j相等 和 j跑到i前面 两种不同的情况
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
第一次提交成功
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