#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/*
������ʵûʲô�����������������㣬��hash��
�жϵ�������������subSudoku��ʱ��ѭ������е������������Ϊ֮ǰ����ѭ������i++�ģ����i = i + 3��
������ȽϷ�����ûдmain����
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
��һ���ύ�ɹ�
*/

int main() {
	vector<vector<char>> a;



}