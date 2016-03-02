#include <iostream>
#include <vector>

using namespace std;

int countPrimes(int n) {
	/*
	�������������
	����˼·�ǣ�Ϊÿһ��С��n������һ��bool����i = 2��ʼ����i�ı��������Ϊfalse�������true�ĸ���
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
	���ַ�������һ��
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
	���������ʱ
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