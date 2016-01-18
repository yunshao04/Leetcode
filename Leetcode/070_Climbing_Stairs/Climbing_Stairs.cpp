#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int n) {
	/*
	此思路没有考虑到重复的情况，作废
	*/
	//if (n == 0) return 0;
	//if (n == 1) return 1;
	//if (n == 2) return 2;
	//int counter = 1;
	//int initializer = n - 1;
	//int factor = 1;
	//for (int i = 0; i < (n / 2); i++) {
	//	counter += factor * initializer;
	//	factor *= initializer;
	//	initializer = initializer - 2;
	//	if (initializer <= 1) break;
	//}
	//if (n % 2 == 0) counter++;
	//return counter;

	/*
	第二个思路只想出了递归的方案
	应该是对的，但是超时了。。作废
	*/
	//if (n == 0) return 0;
	//if (n == 1) return 1;
	//if (n == 2) return 2;
	//int counter = 1;
	//int t = n - 2;
	//while (t >= 0) {
	//	counter = counter + climbStairs(t);
	//	t = t - 1;
	//}
	//return counter + 1;

	/*
	后来参考了下网上的答案，给出了一个递推公式：S[n] = S[n-1] + S[n-2] S[1] = 1 S[2] = 2
	这里要注意for (int i = 2; i < n; i++)这句话，i是从2开始。因为前面push_back了两个数，分别存储在下标0和1的位置
	这题之所以之前试了这么多失败的思路，是因为过度把注意力集中在通项公式上，忽略了递推公式。碰到找规律的题目时，先多列几项看看联系。
	*/
	if (n == 1) return 1;
	if (n == 2) return 2;
	vector<int> record;
	record.push_back(1);
	record.push_back(2);
	for (int i = 2; i < n; i++) {
		record.push_back(record[i - 2] + record[i - 1]);
	}
	return record.back();
}

/*
第一次提交失败
Wrong Answer: input: 2  expected: 2  output: 3
原因
没有考虑特殊情况
解决方案
在普遍运算开始前判断特殊情况

第二次提交失败
Wrong Answer: input: 5  expected: 8  output: 13
原因
之前找的规律有重复的没有考虑

第三次提交失败
Time Limit Exceeded

第四次提交成功
*/

int main() {
	int rs = climbStairs(5);
	cout << rs << endl;
	system("pause");
	return 0;
}