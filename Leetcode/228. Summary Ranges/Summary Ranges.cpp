#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
	vector<string> rs;
	if (nums.size() == 0)
		return rs;
	int subBegin = nums[0];
	int subEnd = nums[0];
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i - 1] + 1 != nums[i]) {
			if (subBegin == subEnd)
				rs.push_back(to_string(subBegin));
			else
				rs.push_back(to_string(subBegin) + "->" + to_string(subEnd));
			subBegin = nums[i];
			subEnd = nums[i];
		}
		else {
			subEnd = nums[i];
		}
	}
	if (subBegin == subEnd)
		rs.push_back(to_string(subBegin));
	else
		rs.push_back(to_string(subBegin) + "->" + to_string(subEnd));
	return rs;
}

int main() {
	vector<int> a;
	a.push_back(-2147483647 - 1);
	a.push_back(-2147483647);
	a.push_back(2147483647);
	vector<string> rs = summaryRanges(a);
	for (int i = 0; i < rs.size(); i++)
		cout << rs[i] << ", ";
	system("pause");
	return 0; 
}