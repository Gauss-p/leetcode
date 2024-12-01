#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
private:
    unordered_map<int, int> col, diagonal1, diagonal2;
    vector<char> row;
    vector<int> queens;
    vector<vector<string>> solutions;
    int nn;

    vector<string> makeBoard(){
        vector<string> board;
        for (int i=0; i<nn; i++){
            row[queens[i]] = 'Q';
            string tmpRow;
            for (char c : row) tmpRow += c;
            board.push_back(tmpRow);
            row[queens[i]] = '.';
        }
        return board;
    }

    void setQueens(int rowIndex){
        if (rowIndex == nn){
            vector<string> tmpBoard = makeBoard();
            solutions.push_back(tmpBoard);
            return;
        }
        for (int i=0; i<nn; i++){
            if (col[i] || diagonal1[rowIndex-i] || diagonal2[rowIndex+i]){
                continue;
            }
            queens[rowIndex] = i;
            col[i] = 1;
            diagonal1[rowIndex-i] = 1;
            diagonal2[rowIndex+i] = 1;
            setQueens(rowIndex+1);
            col[i] = 0;
            diagonal1[rowIndex-i] = 0;
            diagonal2[rowIndex+i] = 0;
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        nn = n;
        row.resize(n, '.');
        queens.resize(n, -1);
        setQueens(0);
        return solutions;
    }
};

int main(){
    Solution s;
    int n = 9;
    vector<vector<string>> res = s.solveNQueens(n);
    for (auto i : res){
        for (auto j : i){
            cout << j << endl;
        }
        cout << endl;
    }
    cout << res.size() << endl;
}
