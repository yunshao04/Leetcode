#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int n) {
	/*
	��˼·û�п��ǵ��ظ������������
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
	�ڶ���˼·ֻ����˵ݹ�ķ���
	Ӧ���ǶԵģ����ǳ�ʱ�ˡ�������
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
	�����ο��������ϵĴ𰸣�������һ�����ƹ�ʽ��S[n] = S[n-1] + S[n-2] S[1] = 1 S[2] = 2
	����Ҫע��for (int i = 2; i < n; i++)��仰��i�Ǵ�2��ʼ����Ϊǰ��push_back�����������ֱ�洢���±�0��1��λ��
	����֮����֮ǰ������ô��ʧ�ܵ�˼·������Ϊ���Ȱ�ע����������ͨ�ʽ�ϣ������˵��ƹ�ʽ�������ҹ��ɵ���Ŀʱ���ȶ��м������ϵ��
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
��һ���ύʧ��
Wrong Answer: input: 2  expected: 2  output: 3
ԭ��
û�п����������
�������
���ձ����㿪ʼǰ�ж��������

�ڶ����ύʧ��
Wrong Answer: input: 5  expected: 8  output: 13
ԭ��
֮ǰ�ҵĹ������ظ���û�п���

�������ύʧ��
Time Limit Exceeded

���Ĵ��ύ�ɹ�
*/

int main() {
	int rs = climbStairs(5);
	cout << rs << endl;
	system("pause");
	return 0;
}