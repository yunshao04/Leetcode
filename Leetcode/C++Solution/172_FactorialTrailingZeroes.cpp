#include "solution.h"
#include <iostream>

using namespace std;

class FactorialTrailingZeroes : public slt::Solution {
public:
	/*
	n! = 1 * 2 * 3 * ... * n ����ֽ������ӣ�Ϊ2^x * 3^y * 5^z * ...
	ֻ��2 * 5�Ż����0
	��Ϊ���ڽ׳ˣ�x��ֵʼ�մ���z������ֻ��Ҫ���ж��ٸ�5������֤������http://www.cnblogs.com/ganganloveu/p/4193373.html��
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