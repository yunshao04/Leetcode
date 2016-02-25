#include <iostream>
#include <vector>

using namespace std;

/*
	这题参考网上的思路和代码
	Find k different element, and "remove" them as a group, the remaining element must be the element that appears more than ?n/k? times. (Detailed explanation is given in comment)

	In this problem, k equals to 2.

	Thus we "remove" each pair of 2 different elements, and the remaining element that do not have its counterpart is the desired element.

	Note that one element E appears more than ?n/k? times. To simplify the description, we supposed n/k is divisible, so E appears n/k+1 times. 
We divide the array into n/k groups evenly and each group has k elements. If E is evenly distributed (extreme case), then n/k-1 groups have one E each, 
and the rest one group has two E and we know E is the required element. In implementation we need to find k different elements and treat them as a group. 
In that case, E may not evenly distributed, so the rest group may contain more than 2 E.
*/

int majorityElement(vector<int>& nums) {
	int target;
	int count = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (count == 0) {
			target = nums[i];
			count++;
		}
		else {
			if (nums[i] == target)
				count++;
			else
				count--;
		}
	}
	return target;
}

int main() {
	vector<int> a;
	a.push_back(3);
	a.push_back(3);
	a.push_back(4);
	//a.push_back(1);
	//a.push_back(1);
	//a.push_back(2);
	//a.push_back(3);

	int rs = majorityElement(a);
	cout << rs << endl;
	system("pause");
	return 0;



}