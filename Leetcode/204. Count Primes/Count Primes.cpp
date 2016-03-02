#include <iostream>
#include <vector>

using namespace std;

int countPrimes(int n) {
	/*
	这个方法很巧妙
	总体思路是，为每一个小于n的数开一个bool，从i = 2开始，把i的倍数都标记为false，最后数true的个数
	*/
	vector<bool> isPrime(n, true);
	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 2; i < sqrt(n); i++) {
		for (int j = i * i; j < n; j += i) {
			isPrime[j] = false;
		}
	}
	return count(isPrime.begin(), isPrime.end(), true);

	/*
	这种方法更快一点
	if(n<=2)  return 0;
	vector<bool>  check(n, false);

	int result=1;
	int upper=sqrt(n);
	for(int i=3; i<n; i+=2){
		if(!check[i]){
			result++;
			if(i>upper) continue;
			for(int j=i*i; j<n; j+=i){
				check[j]=true;
			}
		}
	}
	return result;
	*/

	/*
	这个方法超时
	*/
	//if (n <= 2)
	//	return 0;
	//int count = 1;
	//for (int i = 3; i < n; i++) {
	//	for (int j = 2; j <= i / 2 + 1; j++) {
	//		if (i % j == 0)
	//			break;
	//		if (j == i / 2 + 1)
	//			count++;
	//	}
	//}
	//return count;
}

int main() {
	int rs = countPrimes(10);
	cout << rs << endl;
	system("pause");
	return 0;
}