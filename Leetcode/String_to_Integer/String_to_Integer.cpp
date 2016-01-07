// Example program
#include <iostream>
#include <string>

using namespace std;

int myAtoi(string str) {
	int c;
	int flag_np = 0, flag_num = 0, flag_o = 0;
	long long rs = 0;
	for (int i = 0; i < str.length(); i++) {
		c = (int)str.at(i);
		if (c >= 48 && c <= 57) {
			if (flag_num == 0) {
				if (i >= 1) {
					if (str.at(i - 1) != ' ' && str.at(i - 1) != '+' && str.at(i - 1) != '-') {
						return 0;
					}
					for (int j = 0; j < i - 1; j++) {
						if (str.at(j) != ' ') {
							return 0;
						}
					}
					if (str.at(i - 1) == '-') {
						flag_np = 1;
					}
				}
				rs = c - 48;
				flag_num = 1;
			}
			else {
				rs = rs * 10 + (c - 48);
				if (rs > 2147483648 && flag_np == 1) {
					flag_o = 1;
					break;
				}
				else if (rs > 2147483647 && flag_np == 0) {
					flag_o = 1;
					break;
				}
				flag_num = 1;
			}
		}
		else {
			if (flag_num == 0) {
				continue;
			}
			else {
				break;
			}
		}
	}
	if (flag_o == 1 && flag_np == 0) {
		rs = 2147483647;
	}
	else if (flag_o == 1 && flag_np == 1) {
		rs = -2147483647 - 1;
		flag_np = 0;
	}
	if (flag_np == 1) {
		rs = 0 - rs;
	}
	return (int)rs;
}

int main()
{
	string s = "-2147483648";
	char* s1 = " - 123 ";
	int i = myAtoi(s);
	int j = atoi(s1);
	cout << i << " " << j << endl;
	system("pause");
	return 0;
}
