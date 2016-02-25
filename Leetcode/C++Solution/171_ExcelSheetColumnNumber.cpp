#include "solution.h"
#include <string>
#include <iostream>

using namespace std;

class ExcelSheetColumnNumber : public slt::Solution {
public:
	int titleToNumber(string s) {
		if (s.size() == 0)
			return 0;
		int rs = 0;
		int tmp = 1;
		for (int i = 0; i < s.size(); i++) {
			rs += (s[s.size() - 1 - i] - 'A' + 1) * tmp;
			tmp *= 26;
		}
		return rs;
	}

	void buildSolution() {
		string a = "AD";
		int rs = titleToNumber(a);
		cout <<rs << endl;
	}
};