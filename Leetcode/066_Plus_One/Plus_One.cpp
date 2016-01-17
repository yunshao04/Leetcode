#include <iostream>
#include <vector>

using namespace std;

/*
这题很简单。主要思路是从后往前数9，一边数一遍把该位置0。当数到第一个不是9的数的位置时把该位自增1。如果全部都是9，那么就把最高位置一，末尾push_back一个0。
题目表述中有一个the most significant digit is at the head of the list。这句话一开始没想懂。后来想了想，most significant digit应该是权重最大的位。
比如说一个3位数，权重最大的肯定是百位
*/

vector<int> plusOne(vector<int>& digits) {
	if (digits.size() == 0) {
		digits.push_back(1);
		return digits;
	}
	int flag = 0;
	for (int i = digits.size() - 1; i >= 0; i--) {
		if (digits.at(i) != 9) {
			flag = 1;
			digits.at(i) += 1;
			break;
		}
		else {
			digits.at(i) = 0;
		}
	}
	if (flag == 0) {
		digits.at(0) = 1;
		digits.push_back(0);
	}
	return digits;
}

/*
第一次提交成功
*/

int main() {
	vector<int> a;
	//a.push_back(0);
	//a.push_back(9);
	//a.push_back(9);
	//a.push_back(9);
	//a.push_back(9);
	vector<int> rs = plusOne(a);
	for (int i = 0; i < rs.size(); i++) {
		cout << rs[i];
	}
	system("pause");
	return 0;
}