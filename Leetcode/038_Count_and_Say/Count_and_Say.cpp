#include <iostream> 
#include <string>

using namespace std;

/*
这是一道找规律的题
规律是：下一个数相当于是给上一个数的每个相同的数字前面加个计数器
这里要注意的是for (int i = 0; i < (n - 1); i++)这句话中，求第n个数，要做的是n-1次循环。因为已经给出了第一个数是 1
*/

string countAndSay(int n) {
	if (n == 0) {
		return "";
	}
	if (n == 1) {
		return "1";
	}
	string tmp = "1";
	string next = "";
	string s_counter = "";
	int cur = 0;
	int counter = 0;
	for (int i = 0; i < (n - 1); i++) {
		next = "";
		counter = 0;
		cur = (int)tmp[0];
		for (int j = 0; j < tmp.size(); j++) {
			if (cur == (int)tmp[j]) {
				counter++;
			}
			else {
				s_counter = to_string(counter);
				next += s_counter;
				next.push_back(tmp[j - 1]);
				counter = 1;
				cur = (int)tmp[j];
			}
			if (j == tmp.size() - 1) {
				s_counter = to_string(counter);
				next += s_counter;
				next.push_back(tmp[j]);
			}
		}
		tmp = next;
	}
	return tmp;
}

/*
第一次提交成功
*/

int main() {
	string rs = countAndSay(5);
	cout << rs << endl;
	system("pause");
	return 0; 
}