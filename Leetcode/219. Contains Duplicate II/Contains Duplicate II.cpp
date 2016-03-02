#include <iostream>
#include <vector>
#include <limits.h>
#include <unordered_set>

using namespace std;

/*
常规hashtable思路
*/
//bool containsNearbyDuplicate(vector<int>& nums, int k) {
//	unordered_set<int> contain;
//	for (int i = 0; i < nums.size(); i++) {
//		if (contain.count(nums[i]) == 1)
//			return true;
//		else {
//			contain.insert(nums[i]);
//			if (i >= k)
//				contain.erase(nums[i - k]);
//		}
//	}
//	return false;
//}

/*
用数组的每格代表这个数有没有出现过
*/
bool containsNearbyDuplicate(vector<int>& nums, int k) {
	int min = INT_MAX;
	int max = INT_MIN;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] < min)
			min = nums[i];
		if (nums[i] > max)
			max = nums[i];
	}
	vector<int> appear(max - min + 1, 0);
	for (int i = 0; i < nums.size(); i++) {
		if (appear[nums[i] - min] == 1)
			return true;
		else {
			appear[nums[i] - min] = 1;
			if (i >= k)
				appear[nums[i - k] - min] = 0;
		}
	}
	return false;
}

int main() {
	vector<int> a;
	a.push_back(1);
	a.push_back(8);
	a.push_back(4);
	a.push_back(6);
	a.push_back(8);
	bool rs = containsNearbyDuplicate(a, 3);
	cout << rs << endl;
	system("pause");
	return 0;
}