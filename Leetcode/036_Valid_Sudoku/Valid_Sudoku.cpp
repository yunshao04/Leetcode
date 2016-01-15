#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/*
这题其实没什么技术含量，就是死算，用hash表
判断第三个条件，即subSudoku的时候循环想的有点吃力，可能因为之前做的循环都是i++的，这次i = i + 3的
另：输入比较烦，就没写main函数
*/

bool checkSubSudoku(vector<vector<char>>& board, int x1, int x2, int y1, int y2) {
	unordered_set<char> checkList;
	for (int i = x1; i < x2; i++) {
		for (int j = y1; j < y2; j++) {
			if (isdigit(board[i][j])) {
				if (checkList.count(board[i][j]) > 0) return false;
				checkList.insert(board[i][j]);
			}
		}
	}
	return true;
}

bool isValidSudoku(vector<vector<char>>& board) {
	unordered_set<char> checkList;
	if (board.size() != 9) return false;
	for (int i = 0; i < 9; i++) {
		if (board[i].size() != 9) return false;
		for (int j = 0; j < 9; j++) {
			if (isdigit(board[i][j])) {
				if (checkList.count(board[i][j]) > 0) return false;
				checkList.insert(board[i][j]);
			}
		}
		checkList.clear();
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (isdigit(board[j][i])) {
				if (checkList.count(board[j][i]) > 0) return false;
				checkList.insert(board[j][i]);
			}
		}
		checkList.clear();
	}
	for (int i = 0; i <= 6; i = i + 3) {
		for (int j = 0; j <= 6; j = j + 3) {
			bool rs = checkSubSudoku(board, i, i + 3, j, j + 3);
			if (rs == 0) return false;
		}
	}
	return true;
}

/*
第一次提交成功
*/

int main() {
	vector<vector<char>> a;



}