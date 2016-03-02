#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

bool isIsomorphic(string s, string t) {
	/*
	网上看了一个比较灵活的方法

	*/
	int mapCounter = 1;


	/*
	这个是死方法，速度一般
	*/
	//if (s.length() != t.length())
	//	return false;
	//unordered_map<char, char> stMap;
	//unordered_map<char, char> tsMap;
	//for (int i = 0; i < s.length(); i++) {
	//	unordered_map<char, char>::const_iterator inStMap = stMap.find(s[i]);
	//	unordered_map<char, char>::const_iterator inTsMap = tsMap.find(t[i]);
	//	if (inStMap != stMap.end()) {
	//		if (inStMap->second == t[i])
	//			continue;
	//		else
	//			return false;
	//	}
	//	else if (inTsMap != tsMap.end()) {
	//		if (inTsMap->second == s[i])
	//			continue;
	//		else
	//			return false;
	//	}
	//	else {
	//		stMap.insert({ s[i], t[i] });
	//		tsMap.insert({ t[i], s[i] });
	//	}
	//}
	//return true;
}

int main() {
	string a = "ba";
	string b = "cc";
	bool rs = isIsomorphic(a, b);
	cout << rs << endl;
	system("pause");
	return 0;
}