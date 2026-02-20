#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for (int i=0; i<m/2; i++){
            for (int j=0; j<n/2; j++){
                int tmp = grid[i][j]+grid[m-i-1][j]+grid[m-i-1][n-j-1]+grid[i][n-j-1];
                res += min(tmp, 4-tmp);
            }
        }
        int tmpSum = 0, tmpRes = 0;
        // tmpSum用来统计在中间一列及中间一行中，对称位置相同的1的个数
        // tmpRes用来统计在中间一列及中间一行中，对称位置不同的数对个数
        if (m%2 == 1){
            for (int j=0; j<n/2; j++){
                if (grid[m/2][j]^grid[m/2][n-j-1]){
                    tmpRes++;
                }
                else{
                    tmpSum += grid[m/2][j]+grid[m/2][n-j-1];
                    // tmpSum += grid[m/2][j]*2;
                }
            }
        }
        if (n%2 == 1){
            for (int i=0; i<m/2; i++){
                if (grid[i][n/2]^grid[m-i-1][n/2]){
                    tmpRes++;
                }
                else{
                    tmpSum += grid[i][n/2]+grid[m-i-1][n/2];
                    // tmpSum += grid[i][n/2]*2;
                }
            }
        }
        if (n%2==1 && m%2==1){
            // 当m和n都为奇数时，由于矩阵中1的数目可以被4整除，所以正中间的元素必须是0
            res += grid[m/2][n/2];
        }
        // 当tmpSum模4为0时，无需额外操作。
        // if (tmpSum % 4 == 0){
        //     return res+tmpRes;
        // }
        // else{
        // 否则，凑出一个4的倍数
        // 剩下的情况都是tmpSum模4为2的情况
        if (tmpRes){
            // 如果还有对称位置不同的数对，那么我们就将其中的一对置为1，其他的都置为0，这样，总和就多出了2
            res += tmpRes;
        }
        else{
            // 否则就对原数组进行修改，将其中的一对1变为0或将其中的一对0变为1即可
            res += (tmpSum%4);
        }
        // }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{0,0,1},{0,1,0},{1,0,0}};
    cout << s.minFlips(grid) << endl;
}
