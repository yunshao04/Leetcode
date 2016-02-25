#include <iostream>
#include <stdint.h>
#include "solution.h"

using namespace std;

class Numberof1Bits : public slt::Solution{
	int hammingWeight(uint32_t n) {
		int rs = 0;
		while (n) {
			rs += n % 2;
			n = n / 2;
		}
		return rs;
	}

	void buildSolution() {
		uint32_t a = 7;
		int rs = hammingWeight(a);
		cout << rs << endl; 
	}
};