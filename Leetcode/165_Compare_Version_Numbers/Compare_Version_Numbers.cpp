#include <iostream>
#include <string>

using namespace std;

/*
	这题有一个地方要注意的是，它不限定小数点的个数，所以要用到递归。卡了挺久的这题
*/

int compareVersion(string version1, string version2) {
	if (version1.length() == 0 && version2.length() == 0)
		return 0;
	int dot1 = 0;
	int dot2 = 0;
	for (dot1; dot1 < version1.size(); dot1++) {
		if (version1[dot1] == '.')
			break;
	}
	for (dot2; dot2 < version2.size(); dot2++) {
		if (version2[dot2] == '.')
			break;
	}
	int iV1 = atoi(version1.substr(0, dot1).c_str());
	int iV2 = atoi(version2.substr(0, dot2).c_str());
	if (iV1 > iV2)
		return 1;
	else if (iV1 < iV2)
		return -1;
	else {
		if (dot1 + 1 < version1.length())
			version1 = version1.substr(dot1 + 1);
		else
			version1 = "";
		if (dot2 + 1 < version2.length())
			version2 = version2.substr(dot2 + 1);
		else
			version2 = "";
		return compareVersion(version1, version2);
	}
}

int main() {
	string v1 = "1.1";
	string v2 = "1.1.01";
	int rs = compareVersion(v1, v2);
	cout << rs << endl;
	system("pause");
	return 0;
}