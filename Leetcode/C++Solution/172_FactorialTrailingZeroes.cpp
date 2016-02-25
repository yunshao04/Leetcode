#include "solution.h"
#include <iostream>

using namespace std;

class FactorialTrailingZeroes : public slt::Solution {
public:
	/*
	n! = 1 * 2 * 3 * ... * n 对其分解质因子，为2^x * 3^y * 5^z * ...
	只有2 * 5才会产生0
	因为对于阶乘，x的值始终大于z，所以只需要求有多少个5（具体证明见：http://www.cnblogs.com/ganganloveu/p/4193373.html）
	*/
	int trailingZeroes(int n) {
		int rs = 0;
		while (n) {
			rs += n / 5;
			n /= 5;
		}
		return rs;
	}

	void buildSolution() {
		int rs = trailingZeroes(6);
		cout << "trailing Zeroes:" << rs << endl;
	}
};