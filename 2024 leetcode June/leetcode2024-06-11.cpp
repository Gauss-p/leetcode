#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        int res = 0;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if ((j>0 && board[i][j-1] == 'X') || (i>0 && board[i-1][j] == 'X')) continue;
                if (board[i][j] == 'X') res++;
            }
        }
        return res;
        // for (int i=0; i<m; i++){
        //     for (int j=0; j<n; j++){
        //         if (board[i][j] == 'X'){
        //             board[i][j] = '.';
        //             for (int r=j+1; r<n; r++){
        //                 if (board[i][r] == 'X'){
        //                     board[i][r] = '.';
        //                 }
        //                 else{
        //                     break;
        //                 }
        //             }
        //             for (int d=i+1; d<m; d++){
        //                 if (board[d][j] == 'X'){
        //                     board[d][j] = '.';
        //                 }
        //                 else{
        //                     break;
        //                 }
        //             }
        //             res++;
        //         }
        //     }
        // }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<char>> board = {{'X','X','.','X'},{'.','.','.','X'},{'.','.','.','X'}};
    cout << s.countBattleships(board) << endl;
}
