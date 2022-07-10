#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isValid(int row, int col, char val, vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) { // �ж������Ƿ��ظ�
        if (board[row][i] == val) {
            return false;
        }
    }
    for (int j = 0; j < 9; j++) { // �ж������Ƿ��ظ�
        if (board[j][col] == val) {
            return false;
        }
    }
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = startRow; i < startRow + 3; i++) { // �ж�9�������Ƿ��ظ�
        for (int j = startCol; j < startCol + 3; j++) {
            if (board[i][j] == val) {
                return false;
            }
        }
    }
    return true;
}

bool backtracking(vector<vector<char>>& board) {
    for (int i = 0; i < board.size(); i++) {        // ������
        for (int j = 0; j < board[0].size(); j++) { // ������
            if (board[i][j] != '0') continue;
            for (char k = '1'; k <= '9'; k++) {     // (i, j) ���λ�÷�k�Ƿ����
                if (isValid(i, j, k, board)) {
                    board[i][j] = k;                // ����k
                    if (backtracking(board)) return true; // ����ҵ�����һ�����̷���
                    board[i][j] = '.';              // ���ݣ�����k
                }
            }
            return false;                           // 9�����������ˣ������У���ô�ͷ���false
        }
    }
    return true; // ������û�з���false��˵���ҵ��˺�������λ����
}


//int main() {
//    vector<vector<char>> board;
//    for (int i = 0; i < 9; ++i) {
//        vector<char> v;
//        char line[17];
//        cin >> line;
//        for (int j = 0; j < 9; ++j) {
//            v.push_back(j*2 + 1);
//        }
//        board.push_back(v);
//    }
//    backtracking(board);
//
//
//    for (int i = 0; i < 9; ++i) {
//        vector<char> v;
//        if (v.size() > 0) {
//            for (int j = 0; j < 9; ++j) {
//                cout << v.at(j) << " ";
//            }
//        }
//        cout << endl;
//    }
//}