#include <iostream>
#include <stdint.h>
#include "solution.h"

using namespace std;

class ReverseBits : public slt::Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t rs = 0;
		for (int i = 0; i < 32; ++i) {
			rs |= (((n >> i) & 1) << (31 - i));
		}
		return rs;
	}

	void buildSolution() {

	}
};