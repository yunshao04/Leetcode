#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	/*
	���˼·����������
	1 ÿ�ζ��ǲ��룬̫��ʱ��
	2 whileѭ���е�if�ж������⣬���nums1 = 1 3 4�� nums2 = 4 5����ʱnums2�е�4�ᱻ����nums1�е�1��3֮��
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
	�ڶ���˼·���Ȱ�nums2���������õ�nums1���棬Ȼ���nums1����
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
	��һ���ύʧ��
	Wrong Answer�� Input: [0] 0 [1] 1    Output: [0,1]    Expected: [1] 
	ԭ��
	һ��ʼ��Ϊm����nums1.size(), n����nums2.size()���о�������Ŀ�����Ĳ�̫���
	�������
	ֱ�Ӵ�nums1[m]��λ�ÿ�ʼ��nums2

	�ڶ����ύ�ɹ�
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