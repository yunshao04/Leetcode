#include <iostream>
#include <vector>
#include <cmath>
#include "solution.h"

using namespace std;

class HappyNumber : public slt::Solution {
	bool isHappy(int n) {
		int rs = 0;
		int curSum = 0;
		vector<int> preRes;
		while (rs != 1) {
			curSum = 0;
			preRes.push_back(n);
			while (n) {
				curSum += ((n % 10) * (n % 10));
				n /= 10;
			}
			if (curSum == 1) {
				return true;
			}
			else {
				for (int i = 0; i < preRes.size(); i++) {
					if (preRes[i] == curSum)
						return false;
				}
				preRes.push_back(curSum);
				n = curSum;
			}
		}
	}

	void buildSolution() {
		bool rs = isHappy(19);
		cout << rs << endl;
	}
};