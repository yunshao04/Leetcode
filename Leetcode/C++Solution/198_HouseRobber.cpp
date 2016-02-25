#include <vector>
#include <iostream>
#include "solution.h"

using namespace std;

/*
	DP要注意结果数组的初始化问题
*/

class HouseRobber : public slt::Solution {
	int rob(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		vector<int> rs;
		if (nums.size() == 1)
			return nums[0];
		if (nums.size() == 2) {
			if (nums[1] > nums[0]) {
				return nums[1];
			}
			else {
				return nums[0];
			}
		}
		if (nums[0] > nums[1]) {
			rs.push_back(nums[0]);
			rs.push_back(nums[0]);
		}
		else {
			rs.push_back(nums[0]);
			rs.push_back(nums[1]);
		}

		for (int i = 2; i < nums.size(); i++) {
			if ((rs[i - 2] + nums[i]) > rs[i - 1])
				rs.push_back(rs[i - 2] + nums[i]);
			else
				rs.push_back(rs[i - 1]);
		}
		return *(rs.end() - 1);
	}

	void buildSolution() {
		vector<int> a;
		a.push_back(1);
		a.push_back(3);
		a.push_back(1);
		//a.push_back(4);
		//a.push_back(5);
		//a.push_back(6);

		int rs = rob(a);
		cout << rs << endl;
	}
};