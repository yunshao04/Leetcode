#include <iostream>
#include <vector>

using namespace std;


/*
	从最后一个元素开始修改
*/
vector<int> getRow(int rowIndex) {
	vector<int> rs;
	rs.push_back(1);
	if (rowIndex == 0)
		return rs;
	rs.push_back(1);
	if (rowIndex == 1)
		return rs;
	for (int i = 1; i < rowIndex; i++) {
		rs.push_back(1);
		for (int j = i; j > 0; j--) {
			rs[j] = rs[j] + rs[j - 1];
		}
	}
	return rs;
}

int main() {
	int i, j;
	vector<int> rs = getRow(5);
	for (i = 0; i < rs.size(); i++) {
		cout << rs[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}