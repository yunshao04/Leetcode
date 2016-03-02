#include <iostream>

using namespace std;

/*
这个思路复杂度是log(n)
*/
//bool isPowerOfTwo(int n) {
//	while (n > 1) {
//		if (n % 2 != 0)
//			return false;
//		n = n / 2;
//	}
//	if (n % 2 == 1)
//		return true;
//	else
//		return false;
//}

/*
网上一个 利用位运算 的思路
*/
bool isPowerOfTwo(int n) {
	if (n > 0 && ((n & (n - 1)) == 0))
		return true;
	return false;
}

int main() {
	bool rs = isPowerOfTwo(2);
	cout << rs << endl;
	system("pause");
	return 0;
}