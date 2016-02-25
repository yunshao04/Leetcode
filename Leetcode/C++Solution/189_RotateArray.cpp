#include <iostream>
#include <vector>
#include "solution.h"

using namespace std;

class RotateArray : public slt::Solution {
public:
	/*
	这个思路是二次翻转，空间O(1),时间O(n)，但速度不是最快
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
	另外看到一种思路：把最后的k个数放到新的vector中，再插入到原来的veector前面
	*/
	void rotate(vector<int>& nums, int k) {
		k = k % nums.size();
		vector<int> tmpVector(nums.end() - k, nums.end());
		nums.erase(nums.end() - k, nums.end());
		nums.insert(nums.begin(), tmpVector.begin(), tmpVector.end());
	}

	/*
	第二种方法速度比一种快，速度计算可能有问题，从算法的角度来说，第一种好
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