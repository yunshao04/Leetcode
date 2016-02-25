#include <iostream>
#include <string>
#include <vector>

using namespace std;

string convertToTitle(int n) {
	int tmp = n;
	int remain = 0;
	int result = 0;
	vector<int> digit;
	string rs = "";
	while (tmp != 0) {
		result = (tmp - 1) / 26;
		digit.push_back((tmp - 1) % 26);
		tmp = result;
	}
	for (int i = digit.size() - 1; i >= 0; i--) {
		rs.push_back('A' + digit[i]);
	}
	return rs;
}

int main() {
	int a = 26;
	string rs = convertToTitle(a);
	cout << rs << endl;
	system("pause");
	return 0;
}