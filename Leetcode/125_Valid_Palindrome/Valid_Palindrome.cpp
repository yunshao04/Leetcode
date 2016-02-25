#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s) {
	if (s.size() == 0 || s.size() == 1)
		return true;
	int i = 0;
	int j = s.size() - 1;
	while (i < j) {
		if ((s[i] < 'a' || s[i] > 'z') && (s[i] < 'A' || s[i] > 'Z') && (s[i] < '0' || s[i] > '9')) {
			i++;
			continue;
		}
		if ((s[j] < 'a' || s[j] > 'z') && (s[j] < 'A' || s[j] > 'Z') && (s[j] < '0' || s[j] > '9')) {
			j--;
			continue;
		}
		if (toupper(s[i]) == toupper(s[j])) {
			i++;
			j--;
		}
		else 
			return false;
	}
	return true;
}

int main() {
	string a = "0P";
	bool rs = isPalindrome(a);
	cout << rs << endl;
	system("pause");
	return 0;
}