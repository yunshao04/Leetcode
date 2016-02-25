#include <iostream>
#include <vector>
#include "solution.h"

using namespace std;

class RotateArray : public slt::Solution {
public:
	/*
	���˼·�Ƕ��η�ת���ռ�O(1),ʱ��O(n)�����ٶȲ������
	*/
	/*
	void reverse(vector<int>& nums, int left, int right) {
		while (left < right) {
			int tmp = nums[left];
			nums[left++] = nums[--right];
			nums[right] = tmp;
		}
	}

	void rotate(vector<int>& nums, int k) {
		int n = nums.size();
		k = k % n;
		reverse(nums, 0, n);
		reverse(nums, 0, k);
		reverse(nums, k, n);
	}
	*/

	/*
	���⿴��һ��˼·��������k�����ŵ��µ�vector�У��ٲ��뵽ԭ����veectorǰ��
	*/
	void rotate(vector<int>& nums, int k) {
		k = k % nums.size();
		vector<int> tmpVector(nums.end() - k, nums.end());
		nums.erase(nums.end() - k, nums.end());
		nums.insert(nums.begin(), tmpVector.begin(), tmpVector.end());
	}

	/*
	�ڶ��ַ����ٶȱ�һ�ֿ죬�ٶȼ�����������⣬���㷨�ĽǶ���˵����һ�ֺ�
	*/

	void buildSolution() {
		vector<int> a;
		a.push_back(1);
		a.push_back(2);
		a.push_back(3);
		a.push_back(4);
		a.push_back(5);
		a.push_back(6);
		a.push_back(7);

		rotate(a, 3);
		for (int i = 0; i < a.size(); i++) {
			cout << a[i] << " ";
		}
	}
};