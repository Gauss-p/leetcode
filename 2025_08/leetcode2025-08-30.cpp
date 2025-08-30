#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9, vector<int>(10, 0)), col(9, vector<int>(10, 0)), block(9, vector<int>(10, 0));
        for (int i=0; i<9; i++){
            for (int j=0; j<9; j++){
                if (board[i][j] == '.'){
                    continue;
                }
                int cur = (board[i][j]-'0');
                if (row[i][cur] || col[j][cur] || block[j/3+(i/3)*3][cur]){
                    return false;
                }
                row[i][cur] = 1;
                col[j][cur] = 1;
                block[j/3+(i/3)*3][cur] = 1;
            }
        }
        return true;
    }
};

int main(){
    Solution s;
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    cout << s.isValidSudoku(board) << endl;
}
