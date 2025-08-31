#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool valid;
    vector<vector<int>> space;
    vector<vector<int>> row, col;
    vector<vector<vector<int>>> block;
    void dfs(vector<vector<char>>& board, int pos){
        if (pos == space.size()){
            valid = true;
            return;
        }
        int i = space[pos][0], j = space[pos][1];
        for (int digit=1; digit<10; digit++){
            if (row[i][digit]==0 && col[j][digit]==0 && block[i/3][j/3][digit]==0){
                row[i][digit] = 1;
                col[j][digit] = 1;
                block[i/3][j/3][digit] = 1;

                board[i][j] = ('0'+digit);
                dfs(board, pos+1);

                row[i][digit] = 0;
                col[j][digit] = 0;
                block[i/3][j/3][digit] = 0;
            }
            if (valid){
                return;
            }
        }
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        row.resize(9, vector<int>(10, 0));
        col.resize(9, vector<int>(10, 0));
        block.resize(3, vector<vector<int>>(3, vector<int>(10, 0)));
        valid = false;
        for (int i=0; i<9; i++){
            for (int j=0; j<9; j++){
                if (board[i][j] == '.'){
                    space.push_back({i, j});
                }
                else{
                    int digit = board[i][j]-'0';
                    row[i][digit] = 1;
                    col[j][digit] = 1;
                    block[i/3][j/3][digit] = 1;
                }
            }
        }
        dfs(board, 0);
    }
};

int main(){
    Solution s;
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    s.solveSudoku(board);
    for (vector<char> i : board){
        for (char j : i){
            cout << j << ' ';
        }
        cout << endl;
    }
}
