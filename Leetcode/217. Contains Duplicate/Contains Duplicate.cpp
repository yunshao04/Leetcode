#include <iostream>
#include <vector>
#include <unordered_set>
#include <limits.h>

using namespace std;

/*
最常规的hashtable思路
*/
//bool containsDuplicate(vector<int>& nums) {
//	unordered_set<int> contains;
//	for (int i = 0; i < nums.size(); i++) {
//		if (contains.count(nums[i]))
//			return true;
//		else
//			contains.insert(nums[i]);
//	}
//	return false;
//}

/*
另外看到了一种思路，很巧妙：用数组的每格代表这个数有没有出现过
*/
bool containsDuplicate(vector<int>& nums) {
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
		if (appear[nums[i] - min] == 1) {
			return true;
		}
		else {
			appear[nums[i] - min] = 1;
		}
	}
	return false;
}

int main() {
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(4);
	a.push_back(6);
	a.push_back(8);
	bool rs = containsDuplicate(a);
	cout << rs << endl;
	system("pause");
	return 0;
}