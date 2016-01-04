#include <iostream>
#include <vector>
#include <string>

using namespace std;

string convert(string s, int numRows) {
	if (numRows == 1) {
		return s;
	}
	vector<string> zigzag;
	string rs = "";
	int period = numRows * 2 - 2;
	int remain = 0;

	for (int i = 0; i < numRows; i++) {
		zigzag.push_back("");
	}
	for (int i = 0; i < s.length(); i++) {
		remain = i % period;
		if (remain < numRows) {
			zigzag.at(remain).push_back(s.at(i));
		} else {
			zigzag.at(period - remain).push_back(s.at(i));
		}
	}
	for (int i = 0; i < numRows; i++) {
		rs += zigzag.at(i);
	}
	return rs;
}

int main() {
	string input = "A";	
	string output;
	int nRows = 1;
	output = convert(input, nRows);
	cout << output << endl;
	return 0;
}
