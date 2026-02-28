#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    unordered_map<int, int> col, diagonal1, diagonal2;
    vector<vector<string>> solutions;
    int nn;
    // setQueens是用递归的方式求出皇后的每一种排列方式
    int setQueens(int rowIndex){
        if (rowIndex == nn){
            // 递归基，如果rowIndex已经为n，说明每一行的位置都已计算完，即为一种情况
            return 1;
        }
        int cnt = 0;
        for (int i=0; i<nn; i++){
            if (col[i] || diagonal1[rowIndex-i] || diagonal2[rowIndex+i]){
                // i用来循环当前行的皇后位置，如果i在之前已经出现，那么不能进行循环
                // 接下来还需判断对角线，我们发现，从左上到右下的对角线上所有位置[i][j]，i-j都是定值，而从右上到坐下的对角线上所有位置[i][j]，i+j都是定值，所以如果rowIndex-i或rowIndex+i的值之前已经出现过，就说明当前位置和之前的某个位置在同一条对角线上，会攻击，因此跳过
                continue;
            }
            col[i] = 1;
            diagonal1[rowIndex-i] = 1;
            diagonal2[rowIndex+i] = 1;
            // 以上操作是将当前位置加入已选择的位置之中
            cnt += setQueens(rowIndex+1);
            col[i] = 0;
            diagonal1[rowIndex-i] = 0;
            diagonal2[rowIndex+i] = 0;
            // 恢复现场
        }
        return cnt;
    }
public:
    int totalNQueens(int n) {
        nn = n;
        // 从第0行开始填
        return setQueens(0);
        // vector<int> res = {0, 1, 0, 0, 2, 10, 4, 40, 92, 352};
        // return res[n];
    }
};

int main(){
    Solution s;
    int n = 13;
    cout << s.totalNQueens(n) << endl;
}
