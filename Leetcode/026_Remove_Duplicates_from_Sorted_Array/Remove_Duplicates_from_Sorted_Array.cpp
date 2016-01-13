#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
/*
这里一开始对题目理解错了。以为他只要数组中不同的数字的个数。实际上是要改变这个数组。让不同的数字排在前面。
此思路作废
*/
	//if (nums.size() == 0) {
	//	return 0;
	//}
	//if (nums.size() == 1) {
	//	return 1;
	//}
	//int count = 1, cur = nums.at(0);
	//for (int i = 1; i < nums.size(); i++) {
	//	if (nums.at(i) > cur) {
	//		cur = nums.at(i);
	//		count++;
	//	}
	//}
	//return count;

	if (nums.size() == 0) {
		return 0;
	}
	if (nums.size() == 1) {
		return 1;
	}
	int i = 1, j = 1;
	int cur = nums.at(0);
	while (j < nums.size()) {
		if (nums.at(j) > cur) {
			cur = nums.at(j);
			if (j != i) {
				nums.at(i) = nums.at(j);
			}
			i++;
			j++;
			continue;
		}
		j++;
	}
	return i;
}

/*
	第一次提交失败
	原因：题目理解有误

	第二次提交成功
	但是这题思考的时间很久。原因是对双指针的空间想象还不熟练。
*/

int main() {
	vector<int> a;
	a.push_back(1);
	a.push_back(1);
	a.push_back(4);
	a.push_back(5);
	int rs = removeDuplicates(a);
	cout << rs << endl;
	for (int i = 0; i < rs; i++) {
		cout << a.at(i) << " ";
	}
	system("pause");
	return 0;
}