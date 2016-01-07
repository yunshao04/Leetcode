#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int reverse(int x) {
	int value;
	string sValue;
	if (x < 0) {
		value = abs(x);
	}
	else {
		value = x;
	}
	sValue = to_string(value);
	for (int i = 0; i < (sValue.length() / 2); i++) {
		char temp = sValue.at(i);
		sValue.at(i) = sValue.at(sValue.length() - i - 1);
		sValue.at(sValue.length() - i - 1) = temp;
	}
	int rs = stoi(sValue, NULL, 10);
	if (x < 0) {
		rs = 0 - rs;
	}
	return rs;
}

int main() {
	int n1 = 123;
	int n2 = -123;
	int rs = reverse(n2);
	cout << rs << endl;
	system("pause");
	return 0;
}
