#include <iostream>

using namespace std;

bool isPalindrome(int x) {
	if (x < 0) {
		return false;
	}
	if (x < 10) {
		return true;
	}
	int base = 1000000000;
	int lowBase = 10;
	while ((x / base) == 0) {
		base = base / 10;
	}
	while (x / base == x % lowBase) {
		x = (x % base) / 10;
		base = base / 100;
		if (base < lowBase) {
			return true;
		}
	}
	return false;
}

int main() {
	int a1 = 1001101;
	bool r = isPalindrome(a1);
	cout << r << endl;
	return 0;
}