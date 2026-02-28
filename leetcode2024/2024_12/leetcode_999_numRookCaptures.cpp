#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int x=0, y=0;
        for (int i=0; i<8; i++){
            for (int j=0; j<8; j++){
                if (board[i][j] == 'R'){
                    x=i;
                    y=j;
                    break;
                }
            }
        }
        vector<vector<int>> directions = {{0,-1},{0,1},{1,0},{-1,0}};
        int res = 0;
        for (auto d : directions){
            int dx = d[0], dy = d[1];
            int nx = x+dx, ny = y+dy;
            while ((nx>=0 && nx<8) && (ny>=0 && ny<8)){
                if (board[nx][ny] == 'B'){
                    break;
                }
                if (board[nx][ny] == 'p'){
                    res++;
                    break;
                }
                nx += dx;
                ny += dy;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<char>> board = {{'.','.','.','.','.','.','.','.'},{'.','.','.','p','.','.','.','.'},{'.','.','.','R','.','.','.','p'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','p','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'}};
    cout << s.numRookCaptures(board) << endl;
}
