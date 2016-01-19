#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	/*
	这个思路有两个问题
	1 每次都是插入，太费时间
	2 while循环中的if判断有问题，如果nums1 = 1 3 4， nums2 = 4 5；这时nums2中的4会被插在nums1中的1和3之间
	*/
	//if (n == 0) return;
	//if (m == 0 && n != 0) {
	//	for (int i = 0; i < n; i++) {
	//		nums1.push_back(nums2[i]);
	//	}
	//	return;
	//}
	//int i = 0, j = 0;
	//vector<int>::iterator it;
	//while (i < m) {
	//	if (nums1[i] <= nums2[j]) {
	//		nums1.insert(it + i, nums2[j]);
	//		i++;
	//		j++;
	//		if (j == n) {
	//			break;
	//		}
	//	}
	//	else {
	//		i++;
	//	}
	//}
	//if (j < n) {
	//	for (j; j < n; j++) {
	//		nums1.push_back(nums2[j]);
	//	}
	//}

	/*
	第二个思路：先把nums2的所有数拿到nums1后面，然后对nums1排序
	*/
	if (n == 0) return;
	for (int i = 0; i < n; i++) {
		nums1[m + i] = nums2[i];
	}
	if (m == 0 && n != 0) {
		return;
	}
	sort(nums1.begin(), nums1.begin() + m + n);
}

/*
	第一次提交失败
	Wrong Answer： Input: [0] 0 [1] 1    Output: [0,1]    Expected: [1] 
	原因
	一开始认为m就是nums1.size(), n就是nums2.size()。感觉这里题目描述的不太清楚
	解决方案
	直接从nums1[m]的位置开始赋nums2

	第二次提交成功
*/

int main() {
	vector<int> num1;
	vector<int> num2;
	num1.push_back(1);
	num1.push_back(3);
	num1.push_back(4);
	num1.push_back(9);
	num1.push_back(11);

	num2.push_back(2);
	num2.push_back(5);
	num2.push_back(8);
	num2.push_back(10);

	merge(num1, (int)num1.size(), num2, (int)num2.size());

	for (int i = 0; i < num1.size(); i++) {
		cout << num1[i] << " ";
	}
	system("pause");
	return 0;
}