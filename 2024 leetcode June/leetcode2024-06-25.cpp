#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        // 对于这道题目，我们首先需要证明好子集只有一行或是两行的情况
        // 可以通过分类讨论再利用题目中对好子集的定义，证明出如果没有小于四行的解，就没有大于或等于四行的解
        // 又因为三行的解可以转化成两行的解，所以只需要考虑一行、两行以及无解三种情况
        // 因为每一行都只有0和1，所以可以转化成二进制数，又因为数字太多，就进行去重操作
        // 如果两行对应的二进制数按位与的结果为0，答案就是这两行
        // 当然，如果有一行完全是0，就返回这一行；否则返回[]
        // 注意，返回的下标要按升序排列
        unordered_map<int, int> mp;
        int n = grid.size();
        for (int i=0; i<n; i++){
            int tmp = 0;
            for (int j=0; j<(int)grid[i].size(); j++){
                tmp |= grid[i][j] << j;
            }
            if (tmp == 0){
                return {i};
            }
            mp[tmp] = i;
        }
        for (auto &kv : mp){
            for (auto &kv2 : mp){
                int tmp1 = kv.first, tmp2 = kv2.first;
                int indx1 = kv.second, indx2 = kv2.second;
                if ((tmp1 & tmp2) == 0){
                    if (indx1 > indx2) return {indx2, indx1};
                    else return {indx1, indx2};
                }
            }
        }
        return {};
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{0,1,1,0},{0,0,0,1},{1,1,1,1}};
    vector<int> res = s.goodSubsetofBinaryMatrix(grid);
    for (auto i : res){
        cout << i << " ";
    }
    cout << endl;
}
