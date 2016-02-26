#include <iostream>

using namespace std;

int countPrimes(int n) {
	if (n <= 2)
		return 0;
	int count = 1;
	for (int i = 3; i < n; i++) {
		for (int j = 2; j <= i / 2 + 1; j++) {
			if (i % j == 0)
				break;
			if (j == i / 2 + 1)
				count++;
		}
	}
	return count;
}

int main() {
	int rs = countPrimes(10);
	cout << rs << endl;
	system("pause");
	return 0;
}