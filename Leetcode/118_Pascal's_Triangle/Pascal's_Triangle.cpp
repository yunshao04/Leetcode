#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows) {
	vector<vector<int>> rs;
	vector<int> v;
	for (int i = 0; i < numRows; i++)
		rs.push_back(v);
	if (numRows == 0)
		return rs;
	if (numRows == 1) {
		rs[0].push_back(1);
		return rs;
	}
	rs[0].push_back(1);
	rs[1].push_back(1);
	rs[1].push_back(1);
	for (int i = 2; i < numRows; i++) {
		rs[i].push_back(1);
		for (int j = 1; j < i; j++) {
			rs[i].push_back(rs[i - 1][j - 1] + rs[i - 1][j]);
		}
		rs[i].push_back(1);
	}
	return rs;
}

int main() {
	int i, j;
	vector<vector<int>> rs = generate(3);
	for (i = 0; i < rs.size(); i++) {
		for (j = 0; j < rs[i].size(); j++) {
			cout << rs[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}