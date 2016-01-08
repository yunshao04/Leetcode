#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
	string rs = "";
	char c;
	int index = 0, min;
	if (strs.size() == 0) {
		return "";
	}
	if (strs.size() == 1) {
		return strs.at(0);
	}
	min = strs.at(0).length();
	for (int i = 0; i < strs.size(); i++) {
		if (strs.at(i).length() == 0) {
			return "";
		}
		if (strs.at(i).length() < min) {
			min = strs.at(i).length();
		}
	}
	for (; index < min; index++) {
		for (int i = 0; i < strs.size(); i++) {
			if (index >= strs.at(i).length()) {
				return rs;
			}
			if (i == 0) {
				c = strs.at(i).at(index);
			}
			else {
				if (strs.at(i).at(index) == c) {
					if (i == strs.size() - 1) {
						rs.push_back(c);
					}
				}
				else {
					return rs;
				}
			}
		}
	}
	return rs;
}

int main() {
	vector<string> s;
	string common = "";
	s.push_back("ab");
	s.push_back("");
	s.push_back("abdc");
	common = longestCommonPrefix(s);
	cout << common << endl;
	return 0;
}